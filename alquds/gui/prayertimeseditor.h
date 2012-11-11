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
    void OnMethodChanged(int xIndex);
    void OnAdjustChanged(int xIndex);
    void OnAsrMethodChanged(int xIndex);

private:
    Ui::PrayerTimesEditor *ui;
};

#endif // PRAYERTIMESSETTINGS_H
