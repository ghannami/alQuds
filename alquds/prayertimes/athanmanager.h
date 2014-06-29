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
    enum TimeState{
        BeforAthan  = 1,
        AthanTime ,
        PlayingAthan,
        AthanFinished,
        PrayerTime,
        NextPrayer
    };

    AthanManager(QObject *parent = 0);
    QTime getFajr();
    QTime getSunrise();
    QTime getDhuhr();
    QTime getAsr();
    QTime getSunset();
    QTime getMaghrib();
    QTime getIsha();
    QTime getNextTime();
    QTime getPrevTime();
    PrayerTimes::TimeID nextPrayerTime();
    PrayerTimes::TimeID prevPrayerTime();

    QTime untilNextPrayer();
    QTime passedPrevPrayer();

    static QString prayerTimeByName(PrayerTimes::TimeID xTimeID);
    void updateState();

public slots:
    void oneSecondTimeOut();
    void onAthanFinished();

signals:
    void athanFinished();
    void updateNextPrayer(PrayerTimes::TimeID);

    void stateChanged(TimeState);
    void beforAthan(PrayerTimes::TimeID, QTime);
    void athanTime(PrayerTimes::TimeID);
    void itsPrayerTime(PrayerTimes::TimeID);
    void updateUntilNextTime(PrayerTimes::TimeID, QTime);

private:
    Location *mLocation;
    QTimer *mOneSecondTimer;
    TimeState m_state;
    PrayerTimes::TimeID m_currNextPrayer;
};

#endif // ATHANMANAGER_H
