#include "mediamanager.h"
#include "athanplayer.h"

MediaManager *MediaManager::mInstance = 0;

MediaManager::MediaManager(QObject *parent)
    :QObject(parent)
{
    mAthanPlayer = new AthanPlayer(this);
}

MediaManager *MediaManager::instance()
{
    if(mInstance == 0)
        mInstance = new MediaManager;
    return mInstance;
}

void MediaManager::playAthan(PrayerTimes::TimeID xTime)
{
    mAthanPlayer->playAthan(xTime);
}
