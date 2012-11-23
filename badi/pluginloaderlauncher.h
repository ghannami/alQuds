#ifndef PLUGINLOADERLAUNCHER_H
#define PLUGINLOADERLAUNCHER_H
#include <QObject>
#include "launcher.h"


class PluginLoaderLauncher : public QObject, public Launcher
{
    Q_OBJECT

    Q_INTERFACES(Launcher)

public:
    PluginLoaderLauncher();
    virtual void launch();

private:

};

#endif // PLUGINLOADERLAUNCHER_H
