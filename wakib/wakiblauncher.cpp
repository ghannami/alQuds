#include "wakiblauncher.h"
#include "updatewidget.h"
#include <QtPlugin>
#include <QtGui>
#include "../badi/pluginloader.h"

WakibLauncher::WakibLauncher():
    Launcher()
{
    mWidget = new UpdateWidget(this);
}

void WakibLauncher::launch()
{
    mWidget->show();
}

void WakibLauncher::setPluginLoader(PluginLoader *loader)
{
    Launcher::setPluginLoader(loader);
    connect(this, SIGNAL(relaunchAll()), mPluginLoader, SLOT(relaunchAll()));
}

void WakibLauncher::launchAlquds()
{
    mPluginLoader->loadLauncher("alquds");
}

Q_EXPORT_PLUGIN2(wakiblauncher, WakibLauncher);
