#include "generalsettings.h"
#include <QSettings>
#include <QApplication>

GeneralSettings *GeneralSettings::mInstance = 0;

GeneralSettings::GeneralSettings()
{
    mSettings = new QSettings("Ghannami","AlQuds");
    mSettings->beginGroup("GeneralSettings");
}

GeneralSettings::~GeneralSettings()
{
    if(mSettings)
        delete mSettings;
}

GeneralSettings *GeneralSettings::instance()
{
    if(mInstance == 0)
        mInstance = new GeneralSettings();
    return mInstance;
}

bool GeneralSettings::startWithSystem()
{
    if(mSettings->value("general/startwithsys").isNull())
        setStartWithSystem(true);

    return mSettings->value("general/startwithsys").toBool();
/*
#ifdef Q_OS_WIN
    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
                       QSettings::NativeFormat);
    if(settings.contains("alqudsStartWithSys1005"))
        return true;
    else
        return false;
#endif
*/
}

void GeneralSettings::setStartWithSystem(bool v)
{
    mSettings->setValue("general/startwithsys", v);

#ifdef Q_OS_WIN
    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
                       QSettings::NativeFormat);
    if(v)
    {
        QString file(qApp->applicationFilePath());
        file.replace("/","\\");
        settings.setValue("alqudsStartWithSys1005", "\""+file+"\" -d");
    }
    else
    {
        settings.remove("alqudsStartWithSys1005");
    }
#endif
}
