#ifndef LOCATIONSETTINGS_H
#define LOCATIONSETTINGS_H

#include "winwidget.h"
#include <QByteArray>

namespace Ui {
class LocationSettings;
}
class QTreeWidgetItem;

class LocationSettings : public WinWidget
{
    Q_OBJECT
public:
    explicit LocationSettings(QWidget *parent = 0);
    ~LocationSettings();
    
public slots:
    void OnSearchClicked();
    void OnGeoDownloaded(QByteArray xData);
    void OnLocationItemClicked(QTreeWidgetItem *xItem);
    void OnMethodChanged(int xIndex);
    void OnAdjustChanged(int xIndex);
    void OnAsrMethodChanged(int xIndex);
private:
    Ui::LocationSettings *ui;
};

#endif // LOCATIONSETTINGS_H
