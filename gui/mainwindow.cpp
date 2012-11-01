 #include "mainwindow.h"
#include "prayertimeswidget.h"
#include <QMdiArea>
#include "locationsettings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mMdiArea = new QMdiArea(this);
    mMdiArea->setViewMode(QMdiArea::TabbedView);
    mMdiArea->addSubWindow(new PrayerTimesWidget(this));
    mMdiArea->addSubWindow(new LocationSettings(this));
    setCentralWidget(mMdiArea);
}
