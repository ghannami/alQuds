 #include "mainwindow.h"
#include "prayertimeswidget.h"
#include <QMdiArea>
#include "locationsettings.h"
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QtGui>
#include "winaction.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mHomeWidget = new PrayerTimesWidget();
    mPrayerConfWidget= new LocationSettings();

    mWidgetsToolBar = new QToolBar("", this);
    mHomeAct = new WinAction(mHomeWidget, tr("Home"));
    mPrayerConfAct = new WinAction(mPrayerConfWidget, tr("Payer settings"));

    mWidgetsToolBar->addAction(mHomeAct);
    mWidgetsToolBar->addAction(mPrayerConfAct);

    connect(mHomeAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(mPrayerConfAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    addToolBar(mWidgetsToolBar);

    mMainLayout = new QHBoxLayout();
    mCentralWidget = new QWidget;
    mCentralWidget->setLayout(mMainLayout);
    mCurrentWin = 0;

    QMainWindow::setCentralWidget(mCentralWidget);
    setCentralWidget(mHomeWidget);

//    QFile tFile(":qss/stylesheet.css");
//    tFile.open(QFile::ReadOnly);
//    QString tStyleSheet = QLatin1String(tFile.readAll());
//    qApp->setStyleSheet(tStyleSheet);
}

void MainWindow::setCentralWidget(WinWidget *xCurr)
{
    if(!xCurr)
        return;
    if(mCurrentWin)
    {
        //mCurrentWin->setHidden(true);
        mMainLayout->removeWidget(mCurrentWin);
        mCurrentWin->setParent(0);
    }
    mMainLayout->addWidget(xCurr);
    mCurrentWin = xCurr;
}
