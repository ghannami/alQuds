#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H
#include <qmediaplayer.h>

class MediaPlayer : public QMediaPlayer
{
public:
    MediaPlayer(QObject *parent = 0, Flags flags = 0, QMediaServiceProvider *provider = QMediaServiceProvider::defaultServiceProvider());
    ~MediaPlayer();
};

#endif // MEDIAPLAYER_H
