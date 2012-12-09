#ifndef PLUGINLOADERLAUNCHER_H
#define PLUGINLOADERLAUNCHER_H
#include <QObject>
#include "launcher.h"

class Application;

class PluginLoaderLauncher : public QObject, public Launcher
{
    Q_OBJECT

    Q_INTERFACES(Launcher)

public:
    PluginLoaderLauncher();
    virtual void launch();

public slots:
    virtual void activateWindow();

private:
    PluginLoader *mPluginLoader;
};

#endif // PLUGINLOADERLAUNCHER_H
