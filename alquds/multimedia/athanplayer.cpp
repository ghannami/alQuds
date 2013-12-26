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

}

void AthanPlayer::playAthan(PrayerTimes::TimeID xTime)
{
    stopAthan();

    qDebug()<<"AthanPlayer::playAthan "<<mFileList[xTime];
    QUrl url(mFileList[xTime]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);    
    if(!AthanSettings::instance()->silentMode())
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

void AthanPlayer::playFajrAthan()
{
    playAthan(PrayerTimes::Fajr);
}

void AthanPlayer::playDhurAthan()
{
    playAthan(PrayerTimes::Dhuhr);
}

void AthanPlayer::playAsrAthan()
{
    playAthan(PrayerTimes::Asr);
}

void AthanPlayer::playMaghribAthan()
{
    playAthan(PrayerTimes::Maghrib);
}

void AthanPlayer::playIshaAthan()
{
    playAthan(PrayerTimes::Isha);
}

void AthanPlayer::updateAthanFiles()
{
    mFileList[PrayerTimes::Fajr] = AthanSettings::instance()->fajrFile();
    mFileList[PrayerTimes::Dhuhr] = AthanSettings::instance()->dhurFile();
    mFileList[PrayerTimes::Asr] = AthanSettings::instance()->asrFile();
    mFileList[PrayerTimes::Maghrib] = AthanSettings::instance()->maghribFile();
    mFileList[PrayerTimes::Isha] = AthanSettings::instance()->ishaFile();
}
