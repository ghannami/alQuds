#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QToolBar;
class WinAction;
class WinWidget;
class QDockWidget;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    void setCentralWidget(WinWidget *xCurr);
private:
    QToolBar *mWidgetsToolBar;
    WinAction *mHomeAct;
    WinAction *mPrayerConfAct;
    WinWidget *mHomeWidget;
    WinWidget *mPrayerConfWidget;
    WinWidget *mCurrentWin;
    QHBoxLayout *mMainLayout;
    QWidget *mCentralWidget;
};

#endif // MAINWINDOW_H
