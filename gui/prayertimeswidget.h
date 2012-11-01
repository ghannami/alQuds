#ifndef PRAYERTIMESWIDGET_H
#define PRAYERTIMESWIDGET_H

#include <QWidget>
class AthanManager;
class QStandardItemModel;

namespace Ui {
class PrayerTimesWidget;
}

class PrayerTimesWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PrayerTimesWidget(QWidget *parent = 0);
    ~PrayerTimesWidget();
    
public slots:
    void updateModel();
private:
    Ui::PrayerTimesWidget *ui;
    AthanManager *mAthanManager;
    QStandardItemModel *mModel;
};

#endif // PRAYERTIMESWIDGET_H
