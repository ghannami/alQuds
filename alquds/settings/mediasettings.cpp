#include "mediasettings.h"
#include <QSettings>

MediaSettings *MediaSettings::mInstance = 0;

MediaSettings::MediaSettings(QObject *parent) :
    QObject(parent)
{
    mSettings = new QSettings("Ghannami","AlQuds");
}

MediaSettings *MediaSettings::instance()
{
    if(mInstance == 0)
        mInstance = new MediaSettings;
    return mInstance;
}

