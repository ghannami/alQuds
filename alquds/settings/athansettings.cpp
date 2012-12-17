#include "athansettings.h"
#include <QSettings>
#include <QDir>
#include <QUrl>
#include <QDebug>
#include "pathsettings.h"

AthanSettings *AthanSettings::mInstance = 0;

AthanSettings::AthanSettings(QObject *parent) :
    QObject(parent)
{
    mSettings = new QSettings("Ghannami","AlQuds");

    mSettings->beginGroup("AthanSettings");

    if(mSettings->value("athan/configured").isNull() || mSettings->value("athan/configured").toBool() == false)
    {
        QString fileUrl    (PathSettings::instance()->audioPath().absoluteFilePath("zahrani.mp3"));
        QString fileUrlFajr(PathSettings::instance()->audioPath().absoluteFilePath("zahrani-fajr.mp3"));

        mSettings->setValue("athan/fajrfile", fileUrlFajr);
        mSettings->setValue("athan/dhurfile", fileUrl);
        mSettings->setValue("athan/asrfile", fileUrl);
        mSettings->setValue("athan/maghribfile", fileUrl);
        mSettings->setValue("athan/ishafile", fileUrl);
        mSettings->setValue("athan/silentmode",false);
        mSettings->setValue("athan/playdua",true);

        mSettings->setValue("athan/configured", true);
    }
}

AthanSettings::~AthanSettings()
{
    if(mSettings)
        delete mSettings;
}

AthanSettings *AthanSettings::instance()
{
    if(mInstance == 0)
        mInstance = new AthanSettings;
    return mInstance;
}

QString AthanSettings::fajrFile()
{
    return mSettings->value("athan/fajrfile").toString();
}

QString AthanSettings::dhurFile()
{
    return mSettings->value("athan/dhurfile").toString();
}

QString AthanSettings::asrFile()
{
    return mSettings->value("athan/asrfile").toString();
}

QString AthanSettings::maghribFile()
{
    return mSettings->value("athan/maghribfile").toString();
}

QString AthanSettings::ishaFile()
{
    return mSettings->value("athan/ishafile").toString();
}


void AthanSettings::setFajrFile(QString xFile)
{
    mSettings->setValue("athan/fajrfile", xFile);
    emit prayerFilesChanged();
}

void AthanSettings::setDhurFile(QString xFile)
{
    mSettings->setValue("athan/dhurfile", xFile);
    emit prayerFilesChanged();
}

void AthanSettings::setAsrFile(QString xFile)
{
    mSettings->setValue("athan/asrfile", xFile);
    qDebug()<<"AthanSettings::setAsrFile "<<xFile;
    emit prayerFilesChanged();
}

void AthanSettings::setMaghribFile(QString xFile)
{
    mSettings->setValue("athan/maghribfile", xFile);
    emit prayerFilesChanged();
}

void AthanSettings::setIshaFile(QString xFile)
{
    mSettings->setValue("athan/ishafile", xFile);
    emit prayerFilesChanged();
}

bool AthanSettings::silentMode()
{
    return mSettings->value("athan/silentmode").toBool();
}

void AthanSettings::setSilentMode(bool xMode)
{
    mSettings->setValue("athan/silentmode", xMode);
    emit prayerFilesChanged();
}

bool AthanSettings::playDua()
{
    return mSettings->value("athan/playdua").toBool();
}

void AthanSettings::setPlayDua(bool play)
{
    mSettings->setValue("athan/playdua", play);
    emit prayerFilesChanged();
}
