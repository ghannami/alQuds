#include "pluginloader.h"
#include <QPluginLoader>
#include <QWidget>
#include <QDebug>
#include "launcher.h"
#include <QApplication>
#include <QDir>
#include <QMessageBox>

PluginLoader::PluginLoader(QObject *parent)
    :QPluginLoader(parent)
{
    mAlquds = 0;
}

void PluginLoader::loadLauncher(QString fileName)
{
    QString tFileName = fileName;

    QDir pluginsDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
    pluginsDir.cd("plugins");
    tFileName = tFileName+".dll";
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cd("plugins");
    }
    tFileName = "lib"+tFileName+".dylib";
#endif

    setFileName(pluginsDir.absoluteFilePath(tFileName));
    if(!load())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error");
        msg->setText(errorString());
        msg->exec();
        qDebug()<<"PluginLoader::loadLauncher "<<pluginsDir.absolutePath()+"/"+tFileName <<isLoaded() <<" "<<errorString();
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
}

void PluginLoader::activateWindow()
{
    if(mAlquds)
        mAlquds->activateWindow();
}
