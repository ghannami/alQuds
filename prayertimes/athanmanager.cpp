#include "athanmanager.h"
#include "location.h"
#include "prayertimes.hpp"
#include "../settings/locationsettings.h"
#include "../multimedia/mediamanager.h"
#include <QDebug>

AthanManager::AthanManager(QObject *parent)
    :QObject(parent)
{
    mLocation = new Location(this);

    mOneSecondTimer = new QTimer(this);

    connect(this, SIGNAL(athanTime(PrayerTimes::TimeID)), MediaManager::instance(), SLOT(playAthan(PrayerTimes::TimeID)));

    connect(mOneSecondTimer, SIGNAL(timeout()), this,  SLOT(oneSecondTimeOut()));
    mNextPrayer = nextPrayerTime();
    mOneSecondTimer->start(1000);
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

    if(tCurrTime > getFajr() && tCurrTime <= getDhuhr())
        return PrayerTimes::Dhuhr;

    if(tCurrTime > getDhuhr() && tCurrTime <= getAsr())
        return PrayerTimes::Asr;

    if(tCurrTime > getAsr() && tCurrTime <= getMaghrib())
        return PrayerTimes::Maghrib;

    if(tCurrTime > getMaghrib() && tCurrTime <= getIsha())
        return PrayerTimes::Isha;

    if(tCurrTime > getIsha() || tCurrTime <= getFajr())
        return PrayerTimes::Fajr;
}

void AthanManager::oneSecondTimeOut()
{
    QTime start(0,0,0);
    QTime untilTime = untilNextPrayer();
    int diff = start.secsTo(untilTime);

    if(diff == 0)
    {
        emit athanTime(mNextPrayer);
    }
    else emit updateUntilNextTime(untilTime);

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

QString AthanManager::prayerTimeByName(PrayerTimes::TimeID xTimeID)
{
    if(xTimeID == PrayerTimes::Fajr)
        return tr("Fajr");
    else if(xTimeID == PrayerTimes::Dhuhr)
        return tr("Dhuhr");
    else if(xTimeID == PrayerTimes::Asr)
        return tr("Asr");
    else if(xTimeID == PrayerTimes::Maghrib)
        return tr("Maghrib");
    else if(xTimeID == PrayerTimes::Isha)
        return tr("Isha");
}
