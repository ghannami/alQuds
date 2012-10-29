#include "mainwindow.h"
#include "prayertimes/location.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    new Location();
}
