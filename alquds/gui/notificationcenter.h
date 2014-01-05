#ifndef NOTIFICATIONCENTER_H
#define NOTIFICATIONCENTER_H

#include <QObject>

class AthanTrayWidget;

class NotificationCenter : public QObject
{
    Q_OBJECT
public:
    explicit NotificationCenter(QObject *parent = 0);
    
signals:
    
public slots:
    void untilNextTimeChanged();
    
private:
    AthanTrayWidget *m_trayWidget;
};

#endif // NOTIFICATIONCENTER_H
