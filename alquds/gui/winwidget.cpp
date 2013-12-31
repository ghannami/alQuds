#include "winwidget.h"
#include <QStyleOption>
#include <QPainter>
#include <QStyle>

WinWidget::WinWidget(QWidget *parent) :
    QWidget(parent)
{

}

void WinWidget::paintEvent(QPaintEvent *)
 {
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }
