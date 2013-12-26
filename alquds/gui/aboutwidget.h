#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include "winwidget.h"

namespace Ui {
class AboutWidget;
}

class AboutWidget : public WinWidget
{
    Q_OBJECT

public:
    explicit AboutWidget(QWidget *parent = 0);
    ~AboutWidget();

private:
    Ui::AboutWidget *ui;
};

#endif // ABOUTWIDGET_H
