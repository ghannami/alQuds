#include "athantraywidget.h"
#include <QDesktopWidget>
#include <QApplication>

AthanTrayWidget::AthanTrayWidget(QWidget *parent) :
    QWidget(parent)
{
    Qt::WindowFlags wFlags;
#ifdef Q_OS_WIN
    wFlags = Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool;
#else
    wFlags = Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint;
#endif

    setWindowFlags(wFlags);
    setFixedSize(300,50);
    QDesktopWidget * desktop = QApplication::desktop();
    QRect screen = desktop->availableGeometry(this);
    move(screen.bottomRight().x() - width(), screen.bottomRight().y() - height());
}
