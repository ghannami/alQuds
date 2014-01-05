#include "notificationcenter.h"
#include "athantraywidget.h"

NotificationCenter::NotificationCenter(QObject *parent) :
    QObject(parent)
{
    m_trayWidget = new AthanTrayWidget();
    //m_trayWidget->hide();
    m_trayWidget->show();

}

void NotificationCenter::untilNextTimeChanged()
{
    //m_trayWidget->setPrayer(nextPrayerTime());
    //m_trayWidget->setTime(untilTime.toString("mm:ss"));
    //m_trayWidget->show();
}
