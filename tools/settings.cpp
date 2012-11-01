#include "settings.h"
#include <QSettings>
#include "prayertimes/prayertimes.hpp"
#include <QDate>

Settings *Settings::mInstance = 0;

Settings::Settings()
{
    mSettings = new QSettings("Ghannami","AlQuds");
    if(mSettings->value("location/configured").isNull())
    {
        mSettings->setValue("location/latitude",21.408966);
        mSettings->setValue("location/longitude",39.818573);
        mSettings->setValue("location/city","Mekka");
        mSettings->setValue("location/longitude","Saudi");
        mSettings->setValue("location/useSystemTimezone","true");
        mSettings->setValue("location/configured","true");
    }
    if(mSettings->value("prayerConfig/configured").isNull())
    {
        mSettings->setValue("prayerConfig/calculationMethod", PrayerTimes::Makkah);
        mSettings->setValue("prayerConfig/asrMethod", PrayerTimes::Shafii);
        mSettings->setValue("prayerConfig/adjustingMethod", PrayerTimes::MidNight);
        mSettings->setValue("prayerConfig/dhuhrMinutes", 0);
        mSettings->setValue("prayerConfig/configured", true);
    }
}

Settings *Settings::instance()
{
    if(mInstance==0)
        mInstance = new Settings;
    return mInstance;
}

void Settings::setCity(QString xValue)
{
    mSettings->setValue("location/city",xValue);
    emit locationChanged();
}

QString Settings::city()
{
    return mSettings->value("location/city").toString();
}

void Settings::setCountry(QString xValue)
{
    mSettings->setValue("location/country",xValue);
    emit locationChanged();
}

QString Settings::country()
{
    return mSettings->value("location/country").toString();
}

void Settings::setLatitude(double xValue)
{
    mSettings->setValue("location/latitude",xValue);
    emit locationChanged();
}

double Settings::latitude()
{
    return mSettings->value("location/latitude").toDouble();
}

void Settings::setLongitude(double xValue)
{
    mSettings->setValue("location/longitude",xValue);
    emit locationChanged();
}

double Settings::longitude()
{
    return mSettings->value("location/longitude").toDouble();
}

void Settings::setTimezone(double xValue)
{
    mSettings->setValue("location/timezone",xValue);
    emit locationChanged();
}

double Settings::timezone()
{
    if(mSettings->value("location/useSystemTimezone").toBool())
        return PrayerTimes::get_effective_timezone(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day());
    return mSettings->value("location/timezone").toDouble();
}

void Settings::setUseSystemTimezone(bool xValue)
{
    mSettings->setValue("location/useSystemTimezone",xValue);
    emit locationChanged();
}

bool Settings::useSystemTimezone()
{
    return mSettings->value("location/useSystemTimezone").toBool();
}

PrayerTimes::CalculationMethod Settings::calculationMethod()
{
    return (PrayerTimes::CalculationMethod)mSettings->value("prayerConfig/calculationMethod").toInt();
}

void Settings::setCalculationMethod(int xCalc_method)
{
    mSettings->setValue("prayerConfig/calculationMethod", xCalc_method);
    emit prayerConfigChanged();
}

PrayerTimes::JuristicMethod Settings::asrMethod()
{
    return (PrayerTimes::JuristicMethod)mSettings->value("prayerConfig/asrMethod").toInt();
}

void Settings::setAsrMethod(int xAsr_juristic)
{
    mSettings->setValue("prayerConfig/asrMethod", xAsr_juristic);
    emit prayerConfigChanged();
}

PrayerTimes::AdjustingMethod Settings::adjustingMethod()
{
    return (PrayerTimes::AdjustingMethod)mSettings->value("prayerConfig/adjustingMethod").toInt();
}

void Settings::setAdjustingMethod(int xAdjust_high_lats)
{
    mSettings->setValue("prayerConfig/adjustingMethod", xAdjust_high_lats);
    emit prayerConfigChanged();
}

double Settings::dhuhrMinutes()
{
    return mSettings->value("prayerConfig/dhuhrMinutes").toDouble();
}

void Settings::setDhuhrMinutes(double xDhuhr_minutes)
{
    mSettings->setValue("prayerConfig/dhuhrMinutes", xDhuhr_minutes);
    emit prayerConfigChanged();
}
