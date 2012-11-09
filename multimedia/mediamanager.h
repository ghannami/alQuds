#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <QObject>
#include "prayertimes/prayertimes.hpp"

class AthanPlayer;

class MediaManager : public QObject
{
    Q_OBJECT

private:
    MediaManager(QObject *parent = 0);

public:
    static MediaManager *instance();

public slots:
    void playAthan(PrayerTimes::TimeID xTime);
private:
    static MediaManager *mInstance;
    AthanPlayer *mAthanPlayer;
};

#endif // MEDIAMANAGER_H
