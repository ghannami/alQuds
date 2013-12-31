#include "athanmanager.h"
#include "location.h"
#include "prayertimes.hpp"
#include "locationsettings.h"
#include "mediamanager.h"
#include <QDebug>
#include "athantraywidget.h"

AthanManager::AthanManager(QObject *parent)
    :QObject(parent)
{
    mLocation = new Location(this);

    mOneSecondTimer = new QTimer(this);
    mItsPrayerTimer = new QTimer(this);

    connect(this, SIGNAL(athanTime(PrayerTimes::TimeID)), MediaManager::instance(), SLOT(playAthan(PrayerTimes::TimeID)));

    connect(mOneSecondTimer, SIGNAL(timeout()), this,  SLOT(oneSecondTimeOut()));
    mNextPrayer = nextPrayerTime();
    mOneSecondTimer->start(1000);

    connect(mItsPrayerTimer, SIGNAL(timeout()), this , SLOT(onItsPrayerTimeOut()));

    m_trayWidget = new AthanTrayWidget();
    //m_trayWidget->hide();
    m_trayWidget->show();
    m_isPrayerTime= false;
    m_prayerDuration = 20 * 60 * 1000;
}

QTime AthanManager::getFajr()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Fajr];
}

QTime AthanManager::getAsr()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Asr];
}

QTime AthanManager::getDhuhr()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Dhuhr];
}

QTime AthanManager::getIsha()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Isha];
}

QTime AthanManager::getMaghrib()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Maghrib];
}

QTime AthanManager::getSunrise()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Sunrise];
}

QTime AthanManager::getSunset()
{
    return mLocation->getPrayerTimes()[PrayerTimes::Sunset];
}

QTime AthanManager::getNextTime()
{
    return mLocation->getPrayerTimes()[nextPrayerTime()];
}

PrayerTimes::TimeID AthanManager::nextPrayerTime()
{
    QTime tCurrTime = QTime::currentTime();

    if(tCurrTime > getFajr() && tCurrTime <= getDhuhr())
        return PrayerTimes::Dhuhr;

    if(tCurrTime > getDhuhr() && tCurrTime <= getAsr())
        return PrayerTimes::Asr;

    if(tCurrTime > getAsr() && tCurrTime <= getMaghrib())
        return PrayerTimes::Maghrib;

    if(tCurrTime > getMaghrib() && tCurrTime <= getIsha())
        return PrayerTimes::Isha;

    if(tCurrTime > getIsha() || tCurrTime <= getFajr())
        return PrayerTimes::Fajr;
}

void AthanManager::oneSecondTimeOut()
{
    if(!m_isPrayerTime)
    {
        QTime start(0,0,0);
        QTime untilTime = untilNextPrayer();
        int diff = start.secsTo(untilTime);

        if(diff == 1)
        {
            itsPrayerTime();
        }
        else
        {
            emit updateUntilNextTime(untilTime);
            if(diff == 30)
            {
                m_trayWidget->setPrayer(nextPrayerTime());
                m_trayWidget->setTime(untilTime.toString("mm:ss"));
                m_trayWidget->show();
            }
            if(diff <30)
            {
                m_trayWidget->setTime(untilTime.toString("mm:ss"));
            }
        }

        if(mNextPrayer != nextPrayerTime())
        {
            mNextPrayer = nextPrayerTime();
            emit updateNextPrayer(mNextPrayer);
        }
    }
    else
    {
        QTime sTime(0,0);
        m_trayWidget->setTime(sTime.addMSecs(m_prayerDuration - mItsPrayerTimer->remainingTime()).toString("mm:ss"));
    }
}

void AthanManager::onItsPrayerTimeOut()
{
    m_isPrayerTime = false;
//    m_trayWidget->hide();
    m_trayWidget->show();
}

QTime AthanManager::untilNextPrayer()
{
    QTime tNextTime = getNextTime();
    QTime tUntilTime(0,0,0);
    return tUntilTime.addSecs(QTime::currentTime().secsTo(tNextTime));
}

QString AthanManager::prayerTimeByName(PrayerTimes::TimeID xTimeID)
{
    if(xTimeID == PrayerTimes::Fajr)
        return tr("Fajr");
    else if(xTimeID == PrayerTimes::Dhuhr)
        return tr("Dhuhr");
    else if(xTimeID == PrayerTimes::Asr)
        return tr("Asr");
    else if(xTimeID == PrayerTimes::Maghrib)
        return tr("Maghrib");
    else if(xTimeID == PrayerTimes::Isha)
        return tr("Isha");
}

void AthanManager::itsPrayerTime()
{
    m_isPrayerTime = true;

    emit athanTime(mNextPrayer);
    mItsPrayerTimer->start(m_prayerDuration);
    m_trayWidget->itsPrayerTime(mNextPrayer);
    QTime sTime(0,0);
    m_trayWidget->setTime(sTime.toString("mm:ss"));
}
