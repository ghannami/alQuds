#ifndef LOCATIONEDITOR_H
#define LOCATIONEDITOR_H

#include "winwidget.h"
#include <QByteArray>

namespace Ui {
class LocationEditor;
}
class QTreeWidgetItem;

class LocationEditor : public WinWidget
{
    Q_OBJECT
public:
    explicit LocationEditor(QWidget *parent = 0);
    ~LocationEditor();
    
public slots:
    void OnSearchClicked();
    void OnGeoDownloaded(QByteArray xData);
    void OnLocationItemClicked(QTreeWidgetItem *xItem);

private:
    Ui::LocationEditor *ui;
};

#endif // LOCATIONEDITOR_H
