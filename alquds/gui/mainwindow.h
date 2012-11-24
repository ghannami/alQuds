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

protected:
    void closeEvent(QCloseEvent *);
private:
    QToolBar *mWidgetsToolBar;

    WinWidget *mCurrentWin;
    QHBoxLayout *mMainLayout;
    QWidget *mCentralWidget;
};

#endif // MAINWINDOW_H
