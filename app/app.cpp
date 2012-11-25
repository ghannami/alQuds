#include "app.h"
#include <QPluginLoader>
#include <QtGui>
#include "../badi/launcher.h"
#include "../alquds/settings/pathsettings.h"

App::App(QObject *parent) :
    QObject(parent)
{
    mLauncher = 0;
}

void App::laodApplication()
{
    QPluginLoader pluginLoader;
    QString tFileName = "badi";

#if defined(Q_OS_WIN)
    tFileName = tFileName+".dll";
#elif defined(Q_OS_MAC)
    tFileName = "lib"+tFileName+".dylib";
#endif

    pluginLoader.setFileName(PathSettings::instance()->pluginsPath().absoluteFilePath(tFileName));

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
