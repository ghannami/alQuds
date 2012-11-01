#ifndef LOCATIONSETTINGS_H
#define LOCATIONSETTINGS_H

#include <QWidget>

namespace Ui {
class LocationSettings;
}

class LocationSettings : public QWidget
{
    Q_OBJECT
public:
    explicit LocationSettings(QWidget *parent = 0);
    ~LocationSettings();
    
public slots:
    void OnSearchClicked();
    void OnGeoDownloaded(QByteArray xData);
private:
    Ui::LocationSettings *ui;
};

#endif // LOCATIONSETTINGS_H
