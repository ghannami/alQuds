#ifndef PRAYERTIMESSETTINGS_H
#define PRAYERTIMESSETTINGS_H

#include "winwidget.h"

namespace Ui {
class PrayerTimesEditor;
}

class PrayerTimesEditor : public WinWidget
{
    Q_OBJECT
    
public:
    explicit PrayerTimesEditor(QWidget *parent = 0);
    ~PrayerTimesEditor();

public slots:
    void saveSettings();
    void readFields();
    void onFieldChanged();
    void onStartWithSysChanged(bool);

private:
    Ui::PrayerTimesEditor *ui;
};

#endif // PRAYERTIMESSETTINGS_H
