#include "mediaplayer.h"

MediaPlayer::MediaPlayer(QObject *parent, Flags flags, QMediaServiceProvider *provider)
    :QMediaPlayer(parent, flags, provider)
{

}

MediaPlayer::~MediaPlayer()
{

}
