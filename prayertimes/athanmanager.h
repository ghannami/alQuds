#ifndef ATHANMANAGER_H
#define ATHANMANAGER_H
#include <QObject>
#include <QTime>

class Location;

class AthanManager : public QObject
{
public:
    AthanManager(QObject *parent = 0);
    QTime getFajr();
    QTime getSunrise();
    QTime getDhuhr();
    QTime getAsr();
    QTime getSunset();
    QTime getMaghrib();
    QTime getIsha();

private:
    Location *mLocation;
};

#endif // ATHANMANAGER_H
