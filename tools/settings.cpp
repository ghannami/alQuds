#include "settings.h"
#include <QSettings>

Settings *Settings::mInstance = 0;

Settings::Settings()
{
    mSettings = new QSettings("Ghannami","AlQuds");
//    settings.setValue("location/latitude",50.3551);
//    settings.setValue("location/longitude",7.592136);

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
}

QString Settings::city()
{
    return mSettings->value("location/city").toString();
}

void Settings::setCountry(QString xValue)
{
    mSettings->setValue("location/country",xValue);
}

QString Settings::country()
{
    return mSettings->value("location/country").toString();
}

void Settings::setLatitude(double xValue)
{
    mSettings->setValue("location/latitude",xValue);
}

double Settings::latitude()
{
    return mSettings->value("location/latitude").toDouble();
}

void Settings::setLongitude(double xValue)
{
    mSettings->setValue("location/longitude",xValue);
}

double Settings::longitude()
{
    return mSettings->value("location/longitude").toDouble();
}
