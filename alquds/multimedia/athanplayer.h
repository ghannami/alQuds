#ifndef ATHANPLAYER_H
#define ATHANPLAYER_H
#include "../prayertimes/prayertimes.hpp"
#include "playerinterface.h"

class MediaPlayer;

class AthanPlayer : public PlayerInterface
{
    Q_OBJECT

public:
    AthanPlayer(QObject *parent = 0);

public slots:
    void playAthan(PrayerTimes::TimeID xTime);
    void updateAthanFiles();
    void playFajrAthan();
    void playDhurAthan();
    void playAsrAthan();
    void playMaghribAthan();
    void playIshaAthan();
    void stopAthan();
private:
    MediaPlayer *mPlayer;
    QString mFileList[PrayerTimes::TimesCount];
};

#endif // ATHANPLAYER_H
