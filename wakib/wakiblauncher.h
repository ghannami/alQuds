#ifndef WAKIBLAUNCHER_H
#define WAKIBLAUNCHER_H
#include <QObject>
#include "../badi/launcher.h"

class UpdateWidget;

class WakibLauncher : public QObject, public Launcher
{
    Q_OBJECT

    Q_INTERFACES(Launcher)

public:
    WakibLauncher();
    virtual void launch();
    void launchProgramm();

private:
    UpdateWidget *mWidget;
};

#endif // WAKIBLAUNCHER_H
