#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H
#include<QObject>

class PlayerInterface : public QObject
{
    Q_OBJECT
public:
    PlayerInterface(QObject *parent = 0);

public slots:

};

#endif // PLAYERINTERFACE_H
