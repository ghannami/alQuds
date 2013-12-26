
#include "alqudslauncher.h"
#include "gui/mainwindow.h"
#include <QtPlugin>
#include <QtGui>

AlqudsLauncher::AlqudsLauncher()
{
    mWindow = 0;
}

void AlqudsLauncher::launch()
{
    mWindow = new MainWindow();
    mWindow->show();
}

void AlqudsLauncher::activateWindow()
{
    if (mWindow) {
        mWindow->wakeUpWindow();
    }
}

Q_EXPORT_PLUGIN2(alqudslauncher, AlqudsLauncher);
