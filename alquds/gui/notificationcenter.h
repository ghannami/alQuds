#ifndef NOTIFICATIONCENTER_H
#define NOTIFICATIONCENTER_H

#include <QObject>
#include "prayertimes.hpp"
#include <QTime>

class AthanTrayWidget;

class NotificationCenter : public QObject
{
    Q_OBJECT
private:
    explicit NotificationCenter(QObject *parent = 0);
    
public:
    static NotificationCenter *instance();

signals:
    
public slots:
    void itsBeforAthan(PrayerTimes::TimeID id, QTime time);
    void itsAthanTime(PrayerTimes::TimeID timeID);
    void onAthanFinished();
private:
    AthanTrayWidget *m_trayWidget;
    static NotificationCenter *m_instance;
};

#endif // NOTIFICATIONCENTER_H
