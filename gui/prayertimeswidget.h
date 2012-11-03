#ifndef PRAYERTIMESWIDGET_H
#define PRAYERTIMESWIDGET_H

#include "winwidget.h"
class AthanManager;
class QStandardItemModel;

namespace Ui {
class PrayerTimesWidget;
}

class PrayerTimesWidget : public WinWidget
{
    Q_OBJECT
    
public:
    explicit PrayerTimesWidget(QWidget *parent = 0);
    ~PrayerTimesWidget();
    
public slots:
    void updateTimes();
private:
    Ui::PrayerTimesWidget *ui;
    AthanManager *mAthanManager;
};

#endif // PRAYERTIMESWIDGET_H
