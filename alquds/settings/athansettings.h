#ifndef ATHANSETTINGS_H
#define ATHANSETTINGS_H

#include <QObject>
class QSettings;

class AthanSettings : public QObject
{
    Q_OBJECT
private:
    explicit AthanSettings(QObject *parent = 0);
    
public:
    static AthanSettings *instance();
    ~AthanSettings();
    QString fajrFile();
    QString dhurFile();
    QString asrFile();
    QString maghribFile();
    QString ishaFile();
    bool silentMode();
    bool playDua();

signals:
    void prayerFilesChanged();
public slots:
    void setFajrFile(QString xFile);
    void setDhurFile(QString xFile);
    void setAsrFile(QString xFile);
    void setMaghribFile(QString xFile);
    void setIshaFile(QString xFile);
    void setSilentMode(bool xMode);
    void setPlayDua(bool play);

private:
    static AthanSettings *mInstance;
    QSettings *mSettings;
};

#endif // ATHANSETTINGS_H
