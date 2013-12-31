#ifndef WINWIDGET_H
#define WINWIDGET_H

#include <QWidget>

class WinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WinWidget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);
    
signals:
    
public slots:
    
};

#endif // WINWIDGET_H
