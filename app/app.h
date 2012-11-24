#ifndef APP_H
#define APP_H

#include <QObject>
class Launcher;

class App : public QObject
{
    Q_OBJECT
public:
    explicit App(QObject *parent = 0);
    void laodApplication();

public slots:
    void activeApplication();

private:
    Launcher *mLauncher;
};

#endif // APP_H
