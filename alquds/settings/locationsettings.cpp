#include "locationsettings.h"
#include <QSettings>
#include "../prayertimes/prayertimes.hpp"
#include <QDate>

LocationSettings *LocationSettings::mInstance = 0;

LocationSettings::LocationSettings()
{
    mSettings = new QSettings("Ghannami","AlQuds");

    mSettings->beginGroup("LocationSettings");
    if(mSettings->value("location/configured").isNull())
    {
        mSettings->setValue("location/latitude",21.408966);
        mSettings->setValue("location/longitude",39.818573);
        mSettings->setValue("location/city","Mekka");
        mSettings->setValue("location/country","Saudi");
        mSettings->setValue("location/useSystemTimezone","true");
        mSettings->setValue("location/configured","true");
    }
    if(mSettings->value("prayerConfig/configured").isNull())
    {
        mSettings->setValue("prayerConfig/calculationMethod", PrayerTimes::MWL);
        mSettings->setValue("prayerConfig/asrMethod", PrayerTimes::Shafii);
        mSettings->setValue("prayerConfig/adjustingMethod", PrayerTimes::AngleBased);
        mSettings->setValue("prayerConfig/dhuhrMinutes", 0);
        mSettings->setValue("prayerConfig/configured", true);
    }
}

LocationSettings::~LocationSettings()
{
    if(mSettings)
        delete mSettings;
}

LocationSettings *LocationSettings::instance()
{
    if(mInstance==0)
        mInstance = new LocationSettings;
    return mInstance;
}

void LocationSettings::setCity(QString xValue)
{
    mSettings->setValue("location/city",xValue);
    emit locationChanged();
}

QString LocationSettings::city()
{
    return mSettings->value("location/city").toString();
}

void LocationSettings::setCountry(QString xValue)
{
    mSettings->setValue("location/country",xValue);
    emit locationChanged();
}

QString LocationSettings::country()
{
    return mSettings->value("location/country").toString();
}

void LocationSettings::setLatitude(double xValue)
{
    mSettings->setValue("location/latitude",xValue);
    emit locationChanged();
}

double LocationSettings::latitude()
{
    return mSettings->value("location/latitude").toDouble();
}

void LocationSettings::setLongitude(double xValue)
{
    mSettings->setValue("location/longitude",xValue);
    emit locationChanged();
}

double LocationSettings::longitude()
{
    return mSettings->value("location/longitude").toDouble();
}

void LocationSettings::setTimezone(double xValue)
{
    mSettings->setValue("location/timezone",xValue);
    emit locationChanged();
}

double LocationSettings::timezone()
{
    if(mSettings->value("location/useSystemTimezone").toBool())
        return PrayerTimes::get_effective_timezone(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day());
    return mSettings->value("location/timezone").toDouble();
}

void LocationSettings::setUseSystemTimezone(bool xValue)
{
    mSettings->setValue("location/useSystemTimezone",xValue);
    emit locationChanged();
}

bool LocationSettings::useSystemTimezone()
{
    return mSettings->value("location/useSystemTimezone").toBool();
}

PrayerTimes::CalculationMethod LocationSettings::calculationMethod()
{
    return (PrayerTimes::CalculationMethod)mSettings->value("prayerConfig/calculationMethod").toInt();
}

void LocationSettings::setCalculationMethod(int xCalc_method)
{
    mSettings->setValue("prayerConfig/calculationMethod", xCalc_method);
    emit prayerConfigChanged();
}

PrayerTimes::JuristicMethod LocationSettings::asrMethod()
{
    return (PrayerTimes::JuristicMethod)mSettings->value("prayerConfig/asrMethod").toInt();
}

void LocationSettings::setAsrMethod(int xAsr_juristic)
{
    mSettings->setValue("prayerConfig/asrMethod", xAsr_juristic);
    emit prayerConfigChanged();
}

PrayerTimes::AdjustingMethod LocationSettings::adjustingMethod()
{
    return (PrayerTimes::AdjustingMethod)mSettings->value("prayerConfig/adjustingMethod").toInt();
}

void LocationSettings::setAdjustingMethod(int xAdjust_high_lats)
{
    mSettings->setValue("prayerConfig/adjustingMethod", xAdjust_high_lats);
    emit prayerConfigChanged();
}

double LocationSettings::dhuhrMinutes()
{
    return mSettings->value("prayerConfig/dhuhrMinutes").toDouble();
}

void LocationSettings::setDhuhrMinutes(double xDhuhr_minutes)
{
    mSettings->setValue("prayerConfig/dhuhrMinutes", xDhuhr_minutes);
    emit prayerConfigChanged();
}
