#ifndef ALQUDSLAUNCHER_H
#define ALQUDSLAUNCHER_H
#include <QObject>
#include "../badi/launcher.h"

class AlqudsLauncher : public QObject, public Launcher
{
    Q_OBJECT

    Q_INTERFACES(Launcher)

public:
    AlqudsLauncher();
    virtual void launch();
};

#endif // ALQUDSLAUNCHER_H
