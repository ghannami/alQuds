#ifndef ATHANMANAGER_H
#define ATHANMANAGER_H
#include <QObject>
#include <QTime>
#include "prayertimes.hpp"

#include <QDate>
#include <QTimer>
class Location;
class AthanTrayWidget;

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
    static QString prayerTimeByName(PrayerTimes::TimeID xTimeID);
    void itsPrayerTime();

public slots:
    void oneSecondTimeOut();
    void onItsPrayerTimeOut();

signals:
    void updateNextPrayer(PrayerTimes::TimeID);
    void athanTime(PrayerTimes::TimeID);
    void updateUntilNextTime(QTime);

private:
    Location *mLocation;
    QTimer *mOneSecondTimer;
    QTimer *mItsPrayerTimer;
    PrayerTimes::TimeID mNextPrayer;
    AthanTrayWidget *m_trayWidget;
    bool m_isPrayerTime;
    int m_prayerDuration;
};

#endif // ATHANMANAGER_H
