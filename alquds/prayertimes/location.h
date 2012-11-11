#ifndef LOCATION_H
#define LOCATION_H
#include <QObject>
#include <QTime>

class PrayerTimesAdapter;

class Location : public QObject
{
    Q_OBJECT

public:
    Location(QObject *parent = 0);
    QString city();
    QString country();
    QTime *getPrayerTimes();

public slots:
    void readLocationSettings();
    void readPrayerSettings();

private:
    PrayerTimesAdapter *mPrayerTimes;
    QString mCity, mCountry;
};

#endif // LOCATION_H
