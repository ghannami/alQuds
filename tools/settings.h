#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
class QSettings;

class Settings : public QObject
{
private:
    Settings();

public:
    static Settings *instance();
    void setLatitude(double xValue);
    double latitude();
    void setLongitude(double xValue);
    double longitude();
    void setCity(QString xValue);
    QString city();
    void setCountry(QString xValue);
    QString country();

private:
    static Settings *mInstance;
    QSettings *mSettings;

};

#endif // SETTINGS_H
