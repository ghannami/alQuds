#include "pluginloaderlauncher.h"
#include <QtPlugin>
#include "pluginloader.h"

PluginLoaderLauncher::PluginLoaderLauncher()
{

}

void PluginLoaderLauncher::launch()
{
    mPluginLoader = new PluginLoader;
    mPluginLoader->loadLauncher("wakib");
}

void PluginLoaderLauncher::activateWindow()
{
    mPluginLoader->activateWindow();
}

Q_EXPORT_PLUGIN2(pluginloaderlauncher, PluginLoaderLauncher);
