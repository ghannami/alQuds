 #include "mainwindow.h"
#include "prayertimeseditor.h"
#include <QMdiArea>
#include "locationeditor.h"
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QtGui>
#include "winaction.h"
#include "athaneditor.h"
#include "../webservices/islamwayparser.h"
#include "homewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    HomeWidget *tHomeWidget = new HomeWidget();
    PrayerTimesEditor *tPrayerEditor= new PrayerTimesEditor();
    LocationEditor *tLocationEditor= new LocationEditor();

    mWidgetsToolBar = new QToolBar("", this);
    WinAction *tHomeAct = new WinAction(tHomeWidget, tr("Home"));
    WinAction *tPrayerEditorAct = new WinAction(tPrayerEditor, tr("Payer settings"));
    WinAction *tLocationEditorAct = new WinAction(tLocationEditor, tr("Location"));

    WinWidget *tAthanSettings = new WinWidget;
    QHBoxLayout *tAthanSettingsLay = new QHBoxLayout;
    tAthanSettingsLay->addWidget(new AthanEditor);
    tAthanSettings->setLayout(tAthanSettingsLay);
    WinAction *tAthanSettingsAct = new WinAction(tAthanSettings,tr("Athan settings"));

    mWidgetsToolBar->addAction(tHomeAct);
    mWidgetsToolBar->addAction(tLocationEditorAct);
    mWidgetsToolBar->addAction(tAthanSettingsAct);
    mWidgetsToolBar->addAction(tPrayerEditorAct);

    connect(tHomeAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(tLocationEditorAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(tPrayerEditorAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(tAthanSettingsAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));

    addToolBar(mWidgetsToolBar);

    mMainLayout = new QHBoxLayout();
    mMainLayout->setContentsMargins(0,0,0,0);
    mCentralWidget = new QWidget;
    mCentralWidget->setLayout(mMainLayout);
    mCurrentWin = 0;

    QMainWindow::setCentralWidget(mCentralWidget);
    setCentralWidget(tHomeWidget);

    QFile tFile(":qss/stylesheet.css");
    tFile.open(QFile::ReadOnly);
    QString tStyleSheet = QLatin1String(tFile.readAll());
    qApp->setStyleSheet(tStyleSheet);

    //qApp->setStyleSheet("MainWindow{ background-color: red; }");
    setMaximumSize(QSize(500,400));
    setMinimumSize(QSize(500,400));

}

void MainWindow::setCentralWidget(WinWidget *xCurr)
{
    if(!xCurr || xCurr == mCurrentWin)
        return;
    if(mCurrentWin)
    {
        mMainLayout->removeWidget(mCurrentWin);
        mCurrentWin->setParent(0);
    }
    mMainLayout->addWidget(xCurr);
    mCurrentWin = xCurr;
}
