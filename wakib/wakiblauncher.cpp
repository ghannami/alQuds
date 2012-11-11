#include "wakiblauncher.h"
#include "updatewidget.h"
#include <QtPlugin>
#include <QtGui>

WakibLauncher::WakibLauncher()
{
    mWidget = new UpdateWidget(this);
}

void WakibLauncher::launch()
{
    mWidget->show();
    //loadLauncher("alquds");
}

void WakibLauncher::launchProgramm()
{
    mWidget->close();
    mPluginLoader->loadLauncher("alquds");
}

Q_EXPORT_PLUGIN2(wakiblauncher, WakibLauncher);
