#ifndef ATHANMANAGER_H
#define ATHANMANAGER_H
#include <QObject>
#include <QTime>
#include "prayertimes.hpp"

class Location;
#include <QTimer>

class AthanManager : public QObject
{
    Q_OBJECT

public:
    AthanManager(QObject *parent = 0);
    QTime getFajr();
    QTime getSunrise();
    QTime getDhuhr();
    QTime getAsr();
    QTime getSunset();
    QTime getMaghrib();
    QTime getIsha();
    QTime getNextTime();
    PrayerTimes::TimeID nextPrayerTime();

    QTime untilNextPrayer();

public slots:
    void oneMinuteTimeOut();
signals:
    void updateUntilNextTime(QTime);
    void updateNextPrayer(PrayerTimes::TimeID);
private:
    Location *mLocation;
    QTimer *mOneMinuteTimer;
    PrayerTimes::TimeID mNextPrayer;
};

#endif // ATHANMANAGER_H
