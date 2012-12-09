#include "application.h"
#include <QPluginLoader>
#include <QtGui>
#include "../badi/launcher.h"
#include "../alquds/settings/pathsettings.h"
#include "PluginLoaderLauncher.h"

Application::Application(int argc, char **argv)
        :QtSingleApplication(argc,argv)
{
    if(PathSettings::instance()->updateFilesPath().exists())
        installUpdateFiles();
    loadApplication();
    connect(this, SIGNAL(messageReceived(const QString&)),
                     this, SLOT(activeApplication()));
}

bool Application::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::ApplicationActivate:
        activeApplication();
    default:
        return QtSingleApplication::event(event);
    }
}

void Application::loadApplication()
{
    mPluginLoader = new PluginLoader;
    mLauncher = qobject_cast<Launcher *>(mPluginLoader->loadLauncher("wakib"));
}

void Application::activeApplication()
{
    if(mPluginLoader)
        mPluginLoader->activateWindow();
}

void Application::installUpdateFiles()
{
    qDebug()<<"Application::installUpdateFiles ";
    copyFolder(PathSettings::instance()->updateFilesPath().absolutePath(), PathSettings::instance()->installationRootPath().absolutePath());
//    removeUpdateFolder();
    removeDir(PathSettings::instance()->updateFilesPath());

}

void Application::copyFolder(const QString& sourceFolder,const QString& destFolder)
{
    QQueue< QPair<QString, QString> > queue;

    queue.enqueue(qMakePair(sourceFolder, destFolder));

    while (!queue.isEmpty())
    {
        QPair<QString, QString> pair = queue.dequeue();
        QDir sourceDir(pair.first);
        QDir destDir(pair.second);

        if(!sourceDir.exists())
            continue;

        if(!destDir.exists())
            destDir.mkpath(pair.second);

        QStringList files = sourceDir.entryList(QDir::Files);
        for(int i = 0; i < files.count(); i++)
        {
            QString srcName = pair.first + "/" + files.at(i);
            QString destName = pair.second + "/" + files.at(i);
            QFileInfo fi(destName);
            if(fi.exists())
                sourceDir.remove(fi.absoluteFilePath());
            QFile::copy(srcName, destName);
        }

        QStringList dirs = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
        for(int i = 0; i < dirs.count(); i++)
        {
            QString srcName = pair.first + "/" + dirs.at(i);
            QString destName = pair.second + "/" + dirs.at(i);
            queue.enqueue(qMakePair(srcName, destName));
        }
   }
}

bool Application::removeDir(QDir dir)
{
    if ( ! dir.exists() )
        return false;

    foreach ( QFileInfo fi,
        dir.entryInfoList(
            QDir::AllEntries |
            QDir::NoDotAndDotDot |
            QDir::Hidden |
            QDir::System
        ) )
    {
        if ( fi.isSymLink() || fi.isFile() )
        {
            if ( ! dir.remove(fi.absoluteFilePath()) )
                return false;
        }
        else if ( fi.isDir() )
        {
            if ( ! removeDir(fi.filePath()) )
                return false;
        }
    }

    if ( ! dir.rmdir(dir.absolutePath()) )
        return false;

    return true;
}
