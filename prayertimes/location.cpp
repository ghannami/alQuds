#include "location.h"
#include "prayertimesadapter.h"
#include "../tools/settings.h"
#include <QDebug>

Location::Location(QObject *parent)
    :QObject(parent)
{
    mPrayerTimes = new PrayerTimesAdapter(Settings::instance()->latitude(), Settings::instance()->longitude(),Settings::instance()->timezone());
    connect(Settings::instance(), SIGNAL(locationChanged()), this, SLOT(readLocationSettings()));
    connect(Settings::instance(), SIGNAL(prayerConfigChanged()), this, SLOT(readPrayerSettings()));

    readLocationSettings();
    readPrayerSettings();
    mPrayerTimes->updatePrayerTimes();
}

void Location::readLocationSettings()
{
    mCity = Settings::instance()->city();
    mCountry = Settings::instance()->country();
    mPrayerTimes->setLocation(Settings::instance()->latitude(), Settings::instance()->longitude());
    mPrayerTimes->setTimezone(Settings::instance()->timezone());
    mPrayerTimes->setAdjustingMethod((PrayerTimes::AdjustingMethod)1);
}

void Location::readPrayerSettings()
{
    mPrayerTimes->setAdjustingMethod(Settings::instance()->adjustingMethod());
    mPrayerTimes->setAsrMethod(Settings::instance()->asrMethod());
    mPrayerTimes->setCalculationMethod(Settings::instance()->calculationMethod());
    mPrayerTimes->setDhuhrMinutes(Settings::instance()->dhuhrMinutes());
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
