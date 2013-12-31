#include "athanplayer.h"
#include "mediaplayer.h"
#include <qmediacontent.h>
#include <QUrl>
#include "athansettings.h"
#include <QMessageBox>

AthanPlayer::AthanPlayer(QObject *parent):
    PlayerInterface(parent)
{
    mPlayer = new MediaPlayer(this);
    for(int i = 0; i < PrayerTimes::TimesCount; i++)
        mFileList[i] = "";

    updateAthanFiles();
    connect(AthanSettings::instance(), SIGNAL(prayerFilesChanged()), this, SLOT(updateAthanFiles()));
    connect(mPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(onError(QMediaPlayer::Error)));
    connect(AthanSettings::instance(), SIGNAL(silentModeChanged(bool)), this, SLOT(onSilenModeChanged(bool)));
}

void AthanPlayer::playAthan(PrayerTimes::TimeID xTime)
{
    stopAthan();
    QUrl url(mFileList[xTime]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);
    //if(!AthanSettings::instance()->silentMode())
    mPlayer->play();
}

void AthanPlayer::stopAthan()
{
    if(mPlayer->state() == MediaPlayer::PlayingState)
        mPlayer->stop();
}

void AthanPlayer::onError(QMediaPlayer::Error err)
{
    QMessageBox msg;
    msg.setText(mPlayer->errorString());
    msg.exec();
}

void AthanPlayer::onSilenModeChanged(bool silent)
{
    mPlayer->setMuted(silent);
}

void AthanPlayer::playFajrAthan(bool play)
{
    if(play)
        playAthan(PrayerTimes::Fajr);
    else
        stopAthan();
}

void AthanPlayer::playDhurAthan(bool play)
{
    if(play)
        playAthan(PrayerTimes::Dhuhr);
    else
        stopAthan();
}

void AthanPlayer::playAsrAthan(bool play)
{
    if(play)
        playAthan(PrayerTimes::Asr);
    else
        stopAthan();
}

void AthanPlayer::playMaghribAthan(bool play)
{
    if(play)
        playAthan(PrayerTimes::Maghrib);
    else
        stopAthan();
}

void AthanPlayer::playIshaAthan(bool play)
{
    if(play)
        playAthan(PrayerTimes::Isha);
    else
        stopAthan();
}

void AthanPlayer::updateAthanFiles()
{
    mFileList[PrayerTimes::Fajr] = AthanSettings::instance()->fajrFile();
    mFileList[PrayerTimes::Dhuhr] = AthanSettings::instance()->dhurFile();
    mFileList[PrayerTimes::Asr] = AthanSettings::instance()->asrFile();
    mFileList[PrayerTimes::Maghrib] = AthanSettings::instance()->maghribFile();
    mFileList[PrayerTimes::Isha] = AthanSettings::instance()->ishaFile();
}
