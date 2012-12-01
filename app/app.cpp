#include "app.h"
#include <QPluginLoader>
#include <QtGui>
#include "../badi/launcher.h"
#include "../alquds/settings/pathsettings.h"
#include "../wakib/zipzap.h"

App *App::mInstance = 0;
App::App(QObject *parent) :
    QObject(parent)
{
    mLauncher = 0;
    mPluginLoader = new QPluginLoader(this);
}

App *App::instance()
{
    if(mInstance == 0)
        mInstance = new App;
    return mInstance;
}

void App::laodApplication()
{
    QString tFileName = "badi";

#if defined(Q_OS_WIN)
    tFileName = tFileName+".dll";
#elif defined(Q_OS_MAC)
    tFileName = "lib"+tFileName+".dylib";
#endif

    mPluginLoader->setFileName(PathSettings::instance()->pluginsPath().absoluteFilePath(tFileName));

    if(!pluginLoader.load())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error");
        msg->setText(mPluginLoader->errorString());
        qDebug()<<"main "<<mPluginLoader->fileName();
        msg->exec();
        exit(0);
    }
    QObject *plugin = mPluginLoader->instance();
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

void App::installUpdateFiles(QTemporaryFile *file)
{
    if(mLauncher)

    mPluginLoader->unload();
    if(ZipZap::UnzipTo(file, PathSettings::instance()->updateRootPath().absolutePath()+"/"))
    {
        return;
    }
}
