#ifndef APP_H
#define APP_H

#include <QtSingleApplication>
#include <QDir>

class Launcher;
class PluginLoader;

class Application : public QtSingleApplication
{
    Q_OBJECT

public:

    Application(int argc, char **argv);
    bool event(QEvent *event);
    void loadApplication();


    void installUpdateFiles();
    void copyFolder(const QString &sourceFolder, const QString &destFolder);
    void removeUpdateFolder();
    bool removeDir(QDir);
public slots:
    void activeApplication();

private:
    Launcher *mLauncher;
    PluginLoader *mPluginLoader;
};
#endif // APP_H

