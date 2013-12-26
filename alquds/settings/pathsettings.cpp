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
    QDir tDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)
    tDir.cd("audio");
#elif defined(Q_OS_MAC)
    if (tDir.dirName() == "MacOS") {
        tDir.cdUp();
        tDir.cd("audio");
    }
    else{
        tDir.cd(qApp->applicationName()+".app");
        tDir.cd("Contents");
        tDir.cd("audio");
    }
#endif
    return tDir;

}

QDir PathSettings::installationRootPath()
{
    QDir tDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)

#elif defined(Q_OS_MAC)
    if (tDir.dirName() == "MacOS") {
        tDir.cdUp();
        tDir.cdUp();
    }
    else{
        tDir.cd(qApp->applicationName()+".app");
        //tDir.cd("Contents");
    }
#endif
    return tDir;
}

QDir PathSettings::updateFilesPath()
{
    QDir tDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)

#elif defined(Q_OS_MAC)
    if (tDir.dirName() == "MacOS") {
        tDir.cdUp();
    }
    else{
        tDir.cd(qApp->applicationName()+".app");
        tDir.cd("Contents");
    }
#endif
    qDebug()<<QDir(tDir.absolutePath()+"/update").absolutePath();
    return QDir(tDir.absolutePath()+"/update");
}
