#include "pathsettings.h"
#include <QSettings>
#include <QtGui>

PathSettings *PathSettings::mInstance = 0;

PathSettings::PathSettings()
{
//    mSettings = new QSettings("Ghannami","AlQuds");
}

PathSettings* PathSettings::instance()
{
    if(mInstance == 0)
        mInstance = new PathSettings();
    return mInstance;
}

QDir PathSettings::pluginsPath()
{
    QDir pluginsDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)
    pluginsDir.cd("plugins");
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cd("plugins");
    }
    else{
        pluginsDir.cd(qApp->applicationName()+".app");
        pluginsDir.cd("Contents");
        pluginsDir.cd("plugins");
    }
#endif
    return pluginsDir;
}

QDir PathSettings::audioPath()
{
    QDir pluginsDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)
    pluginsDir.cd("audio");
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cd("audio");
    }
    else{
        pluginsDir.cd(qApp->applicationName()+".app");
        pluginsDir.cd("Contents");
        pluginsDir.cd("audio");
    }
#endif
    return pluginsDir;

}

QDir PathSettings::updateRootPath()
{
    QDir pluginsDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)

#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
    }
    else{
        pluginsDir.cd(qApp->applicationName()+".app");
        pluginsDir.cd("Contents");
    }
#endif
    return pluginsDir;
}
