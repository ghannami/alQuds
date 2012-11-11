#include "alqudslauncher.h"
#include "gui/mainwindow.h"
#include <QtPlugin>
#include <QtGui>

AlqudsLauncher::AlqudsLauncher()
{

}

void AlqudsLauncher::launch()
{
    MainWindow *window = new MainWindow();
    window->show();
}

Q_EXPORT_PLUGIN2(alqudslauncher, AlqudsLauncher);
