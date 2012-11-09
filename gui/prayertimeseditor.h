#ifndef PRAYERTIMESSETTINGS_H
#define PRAYERTIMESSETTINGS_H

#include <QWidget>

namespace Ui {
class PrayerTimesSettings;
}

class PrayerTimesSettings : public QWidget
{
    Q_OBJECT
    
public:
    explicit PrayerTimesSettings(QWidget *parent = 0);
    ~PrayerTimesSettings();
    
private:
    Ui::PrayerTimesSettings *ui;
};

#endif // PRAYERTIMESSETTINGS_H
