#include "app.h"
#include <QPluginLoader>
#include <QtGui>
#include "../badi/launcher.h"

App::App(QObject *parent) :
    QObject(parent)
{
    mLauncher = 0;
}

void App::laodApplication()
{
    QPluginLoader pluginLoader;
#if defined(Q_WS_WIN)
    pluginLoader.setFileName("badi.dll");
#elif defined(Q_OS_MAC)
    QDir tDir = QDir::currentPath();
    if(QDir::current().dirName()=="MacOS")
        tDir.cdUp();
        pluginLoader.setFileName(tDir.absoluteFilePath("plugins/libbadi.dylib"));
#endif

    if(!pluginLoader.load())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error");
        msg->setText(pluginLoader.errorString());
        qDebug()<<"main "<<pluginLoader.fileName();
        msg->exec();
        exit(0);
    }
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
        mLauncher = qobject_cast<Launcher *>(plugin);
        if (mLauncher)
        {
            mLauncher->launch();
        }
    }

}

void App::activeApplication()
{
    if(mLauncher)
        mLauncher->activateWindow();
}

