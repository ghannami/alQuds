#include "athanmanager.h"
#include "location.h"
#include "prayertimes.hpp"

AthanManager::AthanManager(QObject *parent)
    :QObject(parent)
{
    mLocation = new Location(this);
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
