#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include "winwidget.h"
#include "prayertimes.hpp"
#include <QTime>
#include <QMap>
#include <QDomDocument>

class AthanManager;
namespace Ui {
class HomeWidget;
}
class QLabel;

class HomeWidget : public WinWidget
{
    Q_OBJECT
    
public:
    explicit HomeWidget(QWidget *parent = 0);
    ~HomeWidget();

public slots:
    void updateTimes();
    void updateUntilNextTime(PrayerTimes::TimeID, QTime xTime);
    void updateNextPrayerTime(PrayerTimes::TimeID xTimeID);
    void updateLocation();
    void updateServiceContent(QDomDocument xDoc);
    void itsPrayerTime(PrayerTimes::TimeID xTimeID);
    void itsAthanTime(PrayerTimes::TimeID xTimeID);
    void itsBeforAthan(PrayerTimes::TimeID, QTime xTime);

private:
    Ui::HomeWidget *ui;
    AthanManager *mAthanManager;
    QMap<PrayerTimes::TimeID, QLabel* > mPrayerLabels;
    QMap<PrayerTimes::TimeID, QLabel* > mPrayerTimesLabels;
};

#endif // HOMEWIDGET_H
