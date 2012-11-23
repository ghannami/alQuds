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
    loadLauncher("wakib");
}

void PluginLoader::loadLauncher(QString fileName)
{
    QDir pluginsDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
//    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
//        pluginsDir.cdUp();
//    pluginsDir.cdUp();
    pluginsDir.cd("plugins");
    fileName = fileName+".dll";
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cd(fileName);
    }
    fileName = "lib"+fileName+".dylib";
#endif

    setFileName(pluginsDir.absoluteFilePath(fileName));
    if(!load())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error");
        msg->setText(errorString());
        msg->exec();
        qDebug()<<"PluginLoader::loadLauncher "<<pluginsDir.absolutePath()+"/"+fileName <<isLoaded() <<" "<<errorString();
        exit(0);
    }
    QObject *plugin = instance();
    if (plugin) {
        Launcher *launcher = qobject_cast<Launcher *>(plugin);
        if (launcher)
        {
            launcher->setPluginLoader(this);
            launcher->launch();
        }
    }
}
