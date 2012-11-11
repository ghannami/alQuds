#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H
#include <QMediaPlayer>

class MediaPlayer : public QMediaPlayer
{
public:
    MediaPlayer(QObject *parent = 0, Flags flags = 0, QMediaServiceProvider *provider = QMediaServiceProvider::defaultServiceProvider());
    ~MediaPlayer();
};

#endif // MEDIAPLAYER_H
