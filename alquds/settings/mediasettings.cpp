#include "mediasettings.h"
#include <QSettings>

MediaSettings *MediaSettings::mInstance = 0;

MediaSettings::MediaSettings(QObject *parent) :
    QObject(parent)
{
    mSettings = new QSettings("Ghannami","AlQuds");
    mSettings->beginGroup("MediaSettings");

}

MediaSettings::~MediaSettings()
{
    if(mSettings)
        delete mSettings;
}

MediaSettings *MediaSettings::instance()
{
    if(mInstance == 0)
        mInstance = new MediaSettings;
    return mInstance;
}

