#ifndef MEDIASETTINGS_H
#define MEDIASETTINGS_H

#include <QObject>
class QSettings;

class MediaSettings : public QObject
{
    Q_OBJECT
private:
    explicit MediaSettings(QObject *parent = 0);
    
public:
    static MediaSettings *instance();
private:
    static MediaSettings *mInstance;
    QSettings *mSettings;
};

#endif // MEDIASETTINGS_H
