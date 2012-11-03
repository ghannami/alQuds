#include "athanmanager.h"
#include "location.h"
#include "prayertimes.hpp"

AthanManager::AthanManager(QObject *parent)
    :QObject(parent)
{
    mLocation = new Location(this);
    mOneMinuteTimer = new QTimer(this);
    mOneMinuteTimer->setInterval(6000);
    connect(mOneMinuteTimer, SIGNAL(timeout()), this,  SLOT(oneMinuteTimeOut()));
}

QTime AthanManager::getFajr()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Fajr];
}

QTime AthanManager::getAsr()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Asr];
}

QTime AthanManager::getDhuhr()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Dhuhr];
}

QTime AthanManager::getIsha()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Isha];
}

QTime AthanManager::getMaghrib()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Maghrib];
}

QTime AthanManager::getSunrise()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Sunrise];
}

QTime AthanManager::getSunset()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Sunset];
}

QTime AthanManager::getNextTime()
{
    return mLocation->getPrayerTimes()[nextPrayerTime()];
}

PrayerTimes::TimeID AthanManager::nextPrayerTime()
{
    QTime tCurrTime = QTime::currentTime();
    PrayerTimes::TimeID tTimeID;
    for(int i = 0; i < PrayerTimes::TimesCount; i++)
    {
        if(tCurrTime < mLocation->getPrayerTimes()[i] &&
                (PrayerTimes::TimeID)i != PrayerTimes::Sunrise && (PrayerTimes::TimeID)i != PrayerTimes::Sunset)
        {
            tTimeID = (PrayerTimes::TimeID)i;
            break;
        }
    }
    return tTimeID;
}

void AthanManager::oneMinuteTimeOut()
{
    emit updateUntilNextTime(untilNextPrayer());
    if(mNextPrayer != nextPrayerTime())
    {
        mNextPrayer = nextPrayerTime();
        emit updateNextPrayer(mNextPrayer);
    }
}

QTime AthanManager::untilNextPrayer()
{
    QTime tNextTime = getNextTime();
    QTime tUntilTime(0,0,0);
    return tUntilTime.addSecs(QTime::currentTime().secsTo(tNextTime));
}
