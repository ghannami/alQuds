#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

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
    void wakeUpWindow();
signals:
    
public slots:
    void setCentralWidget(WinWidget *xCurr);
    void onSystemTrayActivated(QSystemTrayIcon::ActivationReason reason);

protected:
    void closeEvent(QCloseEvent *);
    void createTrayIcon();

private:
    QToolBar *mWidgetsToolBar;

    WinWidget *mCurrentWin;
    QHBoxLayout *mMainLayout;
    QWidget *mCentralWidget;
};

#endif // MAINWINDOW_H
