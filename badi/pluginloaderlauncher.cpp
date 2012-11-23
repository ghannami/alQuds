#include "pluginloaderlauncher.h"
#include <QtPlugin>
#include "pluginloader.h"

PluginLoaderLauncher::PluginLoaderLauncher()
{

}

void PluginLoaderLauncher::launch()
{
    PluginLoader *tPluginLoader = new PluginLoader;
}

Q_EXPORT_PLUGIN2(pluginloaderlauncher, PluginLoaderLauncher);
