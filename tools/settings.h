#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
#include "prayertimes/prayertimes.hpp"

class QSettings;
class Settings : public QObject
{
    Q_OBJECT
private:
    Settings();

public:
    static Settings *instance();
    double latitude();
    double longitude();
    QString city();
    QString country();
    double timezone();
    bool useSystemTimezone();
    PrayerTimes::CalculationMethod calculationMethod();
    PrayerTimes::JuristicMethod asrMethod();
    PrayerTimes::AdjustingMethod adjustingMethod();
    double dhuhrMinutes();

public slots:
    /// location configuration
    void setCity(QString xValue);
    void setLongitude(double xValue);
    void setLatitude(double xValue);
    void setTimezone(double xValue);
    void setCountry(QString xValue);
    void setUseSystemTimezone(bool xValue);
    /// prayer configuration
    void setCalculationMethod(int xCalc_method);
    void setAsrMethod(int xAsr_juristic);
    void setAdjustingMethod(int xAdjust_high_lats);
    void setDhuhrMinutes(double xDhuhr_minutes);

signals:
    void locationChanged();
    void prayerConfigChanged();
private:
    static Settings *mInstance;
    QSettings *mSettings;

};

#endif // SETTINGS_H
