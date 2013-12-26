#include "mainwindow.h"
#include "prayertimeseditor.h"
#include <QMdiArea>
#include "locationeditor.h"
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QtGui>
#include <QtWidgets>
#include "winaction.h"
#include "athaneditor.h"
#include "../webservices/islamwayparser.h"
#include "homewidget.h"
#include "../version.h"
#include <iostream>
#include "../WinSparkle/winsparkle.h"
#include "aboutwidget.h"

void shutdownCallBack()
{
    qApp->quit();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    HomeWidget *tHomeWidget = new HomeWidget();
    PrayerTimesEditor *tPrayerEditor= new PrayerTimesEditor();
    LocationEditor *tLocationEditor= new LocationEditor();

    mWidgetsToolBar = new QToolBar("", this);
    WinAction *tHomeAct = new WinAction(tHomeWidget, tr("Home"));
    WinAction *tPrayerEditorAct = new WinAction(tPrayerEditor, tr("Options"));
    WinAction *tLocationEditorAct = new WinAction(tLocationEditor, tr("Location"));

    AthanEditor *tAthanSettings = new AthanEditor;
    WinAction *tAthanSettingsAct = new WinAction(tAthanSettings,tr("Athan"));

    AboutWidget *tAboutWidget = new AboutWidget;
    WinAction *tAboutWidgetAct = new WinAction(tAboutWidget,tr("About"));

    mWidgetsToolBar->addAction(tHomeAct);
    mWidgetsToolBar->addAction(tLocationEditorAct);
    mWidgetsToolBar->addAction(tAthanSettingsAct);
    mWidgetsToolBar->addAction(tPrayerEditorAct);
    mWidgetsToolBar->addAction(tAboutWidgetAct);

    connect(tHomeAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(tLocationEditorAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(tPrayerEditorAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(tAthanSettingsAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));
    connect(tAboutWidgetAct, SIGNAL(clicked(WinWidget*)), this, SLOT(setCentralWidget(WinWidget*)));

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


//         QString program = "/Applications/Skype.app/Contents/MacOS/Skype";
//         QStringList arguments;
//         arguments << "-style" << "motif";

//         QProcess *myProcess = new QProcess(this);
//         myProcess->start(program, arguments);


    setWindowTitle(ALQUDS_VERSION);
    setWindowIcon(QIcon(":/icons/128/kubbetussahra.png"));

    createTrayIcon();

#ifdef Q_OS_WIN
    win_sparkle_init();
    win_sparkle_set_shutdown_request_callback(&shutdownCallBack);
    win_sparkle_check_update_without_ui();
#endif
}

MainWindow::~MainWindow()
{
    win_sparkle_cleanup();
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

void MainWindow::onSystemTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
        wakeUpWindow();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

void MainWindow::createTrayIcon()
{
    QMenu *trayIconMenu;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    minimizeAction = new QAction("Minimizar", this);
    restoreAction = new QAction("Restaurar", this);
    quitAction = new QAction("Quit", this);

    connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect (restoreAction, SIGNAL(triggered()),this,SLOT(showNormal()));
    connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction (minimizeAction);
    trayIconMenu->addAction (restoreAction);
    trayIconMenu->addAction (quitAction);
    QSystemTrayIcon* systray = new QSystemTrayIcon(this);
    QIcon icon(":/icons/48/kubbetussahra.png");
    systray->setIcon(icon);
    systray->setContextMenu (trayIconMenu);
    systray->show();
    connect(systray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onSystemTrayActivated(QSystemTrayIcon::ActivationReason)));

#ifdef Q_WS_MACX
    extern void qt_mac_set_dock_menu(QMenu*);
    qt_mac_set_dock_menu(trayIconMenu);
#endif

}

void MainWindow::wakeUpWindow()
{
    setWindowState(windowState() & ~Qt::WindowMinimized);
    raise();
    activateWindow();
    showNormal();
}
