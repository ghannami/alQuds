#include "pluginloader.h"
#include <QPluginLoader>
#include <QWidget>
#include <QDebug>
#include "launcher.h"
#include <QApplication>
#include <QDir>
#include <QMessageBox>
#include "../alquds/settings/pathsettings.h"
#include <QProcess>

PluginLoader::PluginLoader(QObject *parent)
    :QPluginLoader(parent)
{
    mAlquds = 0;
}

QObject* PluginLoader::loadLauncher(QString fileName)
{
    QString tFileName = fileName;

#if defined(Q_OS_WIN)
    tFileName = tFileName+".dll";
#elif defined(Q_OS_MAC)
    tFileName = "lib"+tFileName+".dylib";
#endif

    setFileName(PathSettings::instance()->pluginsPath().absoluteFilePath(tFileName));
//    qDebug()<<PathSettings::instance()->pluginsPath().absoluteFilePath(tFileName);
    if(!load())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error");
        msg->setText(errorString());
        msg->exec();
//        qDebug()<<"PluginLoader::loadLauncher "<<pluginsDir.absolutePath()+"/"+tFileName <<isLoaded() <<" "<<errorString();
        exit(0);
    }
    QObject *plugin = instance();
    if (plugin) {
        Launcher *launcher = qobject_cast<Launcher *>(plugin);
        if (launcher)
        {
            launcher->setPluginLoader(this);
            launcher->launch();
            if(fileName == "alquds")
                mAlquds = launcher;
        }
    }
    return plugin;
}

void PluginLoader::activateWindow()
{
    if(mAlquds)
        mAlquds->activateWindow();
}

void PluginLoader::relaunchAll()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
}
