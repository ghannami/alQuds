#include "location.h"
#include "prayertimesadapter.h"
#include "../settings/locationsettings.h"
#include <QDebug>

Location::Location(QObject *parent)
    :QObject(parent)
{
    mPrayerTimes = new PrayerTimesAdapter(LocationSettings::instance()->latitude(), LocationSettings::instance()->longitude(),LocationSettings::instance()->timezone());
    connect(LocationSettings::instance(), SIGNAL(locationChanged()), this, SLOT(readLocationSettings()));
    connect(LocationSettings::instance(), SIGNAL(prayerConfigChanged()), this, SLOT(readPrayerSettings()));

    readLocationSettings();
    readPrayerSettings();
    mPrayerTimes->updatePrayerTimes();
}

void Location::readLocationSettings()
{
    mCity = LocationSettings::instance()->city();
    mCountry = LocationSettings::instance()->country();
    mPrayerTimes->setLocation(LocationSettings::instance()->latitude(), LocationSettings::instance()->longitude());
    mPrayerTimes->setTimezone(LocationSettings::instance()->timezone());
    mPrayerTimes->setAdjustingMethod((PrayerTimes::AdjustingMethod)1);
}

void Location::readPrayerSettings()
{
    mPrayerTimes->setAdjustingMethod(LocationSettings::instance()->adjustingMethod());
    mPrayerTimes->setAsrMethod(LocationSettings::instance()->asrMethod());
    mPrayerTimes->setCalculationMethod(LocationSettings::instance()->calculationMethod());
    mPrayerTimes->setDhuhrMinutes(LocationSettings::instance()->dhuhrMinutes());
}

QString Location::city()
{
    return mCity;
}

QString Location::country()
{
    return mCountry;
}

QTime *Location::getPrayerTimes()
{
    return mPrayerTimes->getPrayerTimes();
}
