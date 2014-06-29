#include "notificationcenter.h"
#include "athantraywidget.h"
#include <QTime>

NotificationCenter *NotificationCenter::m_instance = 0;

NotificationCenter::NotificationCenter(QObject *parent) :
    QObject(parent)
{
    m_trayWidget = new AthanTrayWidget();
    m_trayWidget->hide();
}

NotificationCenter *NotificationCenter::instance()
{
    if(m_instance == 0)
        m_instance = new NotificationCenter();
    return m_instance;
}

void NotificationCenter::itsBeforAthan(PrayerTimes::TimeID id, QTime time)
{
    m_trayWidget->itsBeforAthan(id, time);
    m_trayWidget->show();
}

void NotificationCenter::itsAthanTime(PrayerTimes::TimeID timeID)
{
    m_trayWidget->itsAthanTime(timeID);
    m_trayWidget->show();
}

void NotificationCenter::onAthanFinished()
{
    m_trayWidget->hide();
}
