#include "mediamanager.h"
#include "athanplayer.h"
#include "../settings/athansettings.h"

MediaManager *MediaManager::mInstance = 0;

MediaManager::MediaManager(QObject *parent)
    :QObject(parent)
{
    mAthanPlayer = new AthanPlayer(this);
    connect(mAthanPlayer, SIGNAL(finished()), this, SIGNAL(athanFinished()));
}

MediaManager *MediaManager::instance()
{
    if(mInstance == 0)
        mInstance = new MediaManager;
    return mInstance;
}

void MediaManager::playAthan(PrayerTimes::TimeID xTime)
{
    if(AthanSettings::instance()->silentMode())
        return;

    mAthanPlayer->playAthan(xTime);
}
