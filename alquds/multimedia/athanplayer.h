#ifndef ATHANPLAYER_H
#define ATHANPLAYER_H
#include "../prayertimes/prayertimes.hpp"
#include "playerinterface.h"
#include <QMediaPlayer>

class MediaPlayer;

class AthanPlayer : public PlayerInterface
{
    Q_OBJECT

public:
    AthanPlayer(QObject *parent = 0);

public slots:
    void playAthan(PrayerTimes::TimeID xTime);
    void updateAthanFiles();
    void playFajrAthan(bool play = true);
    void playDhurAthan(bool play = true);
    void playAsrAthan(bool play = true);
    void playMaghribAthan(bool play = true);
    void playIshaAthan(bool play = true);
    void stopAthan();
    void onError(QMediaPlayer::Error);
    void onSilenModeChanged(bool silent);

private:
    MediaPlayer *mPlayer;
    QString mFileList[PrayerTimes::TimesCount];
};

#endif // ATHANPLAYER_H
