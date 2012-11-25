#include "athanplayer.h"
#include "../settings/athansettings.h"
#include "mediaplayer.h"
#include <qmediacontent.h>
#include <QUrl>

AthanPlayer::AthanPlayer(QObject *parent):
    PlayerInterface(parent)
{
    mPlayer = new MediaPlayer(this);
    for(int i = 0; i < PrayerTimes::TimesCount; i++)
        mFileList[i] = "";

    updateAthanFiles();
    connect(AthanSettings::instance(), SIGNAL(prayerFilesChanged()), this, SLOT(updateAthanFiles()));

}

void AthanPlayer::playAthan(PrayerTimes::TimeID xTime)
{
    qDebug()<<"AthanPlayer::playAthan "<<mFileList[xTime];
    //QMediaContent tContent(QUrl::fromLocalFile("/Volumes/Data/iDevelop/Git-Projects/Alquds/src/mp3/athan.mp3"));
    QUrl url(mFileList[xTime]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);
    mPlayer->play();

}

void AthanPlayer::stopAthan()
{
    if(mPlayer->state() == MediaPlayer::PlayingState)
        mPlayer->stop();
}

void AthanPlayer::playFajrAthan()
{
    stopAthan();
    QUrl url(mFileList[PrayerTimes::Fajr]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);
    mPlayer->play();

}

void AthanPlayer::playDhurAthan()
{
    stopAthan();
    QUrl url(mFileList[PrayerTimes::Dhuhr]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);
    mPlayer->play();

}

void AthanPlayer::playAsrAthan()
{
    stopAthan();
    QUrl url(mFileList[PrayerTimes::Asr]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);
    mPlayer->play();

}

void AthanPlayer::playMaghribAthan()
{
    stopAthan();
    QUrl url(mFileList[PrayerTimes::Maghrib]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);
    mPlayer->play();

}

void AthanPlayer::playIshaAthan()
{
    stopAthan();
    QUrl url(mFileList[PrayerTimes::Isha]);
    QMediaContent tContent(url);
    mPlayer->setMedia(tContent);
    mPlayer->play();

}

void AthanPlayer::updateAthanFiles()
{
    mFileList[PrayerTimes::Fajr] = AthanSettings::instance()->fajrFile();
    mFileList[PrayerTimes::Dhuhr] = AthanSettings::instance()->dhurFile();
    mFileList[PrayerTimes::Asr] = AthanSettings::instance()->asrFile();
    mFileList[PrayerTimes::Maghrib] = AthanSettings::instance()->maghribFile();
    mFileList[PrayerTimes::Isha] = AthanSettings::instance()->ishaFile();
}
