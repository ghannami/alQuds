#ifndef LAUNCHER_H
#define LAUNCHER_H
#include "pluginloader.h"
class Launcher
{
public:
    virtual ~Launcher() {}
    void setPluginLoader(PluginLoader *loader){
        mPluginLoader = loader;
    }

    void loadLauncher(QString name)
    {
        mPluginLoader->loadLauncher(name);
    }
    virtual void activateWindow(){}
    virtual void launch()  = 0;

protected:
    PluginLoader *mPluginLoader;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(Launcher,
                    "com.ghannami.Plugin.Launcher/1.0")
QT_END_NAMESPACE

#endif // LAUNCHER_H
