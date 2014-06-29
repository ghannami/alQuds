#include "athanmanager.h"
#include "location.h"
#include "prayertimes.hpp"
#include "locationsettings.h"
#include "mediamanager.h"
#include "notificationcenter.h"
#include <QDebug>

AthanManager::AthanManager(QObject *parent)
    :QObject(parent)
{
    mLocation = new Location(this);

    mOneSecondTimer = new QTimer(this);

    connect(this, SIGNAL(athanTime(PrayerTimes::TimeID)), MediaManager::instance(), SLOT(playAthan(PrayerTimes::TimeID)));
    connect(MediaManager::instance(), SIGNAL(athanFinished()), this, SLOT(onAthanFinished()));
    connect(MediaManager::instance(), SIGNAL(athanFinished()), NotificationCenter::instance(), SLOT(onAthanFinished()));

    connect(mOneSecondTimer, SIGNAL(timeout()), this,  SLOT(oneSecondTimeOut()));
    mOneSecondTimer->start(1000);
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

QTime AthanManager::getPrevTime()
{
    return mLocation->getPrayerTimes()[prevPrayerTime()];
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

PrayerTimes::TimeID AthanManager::prevPrayerTime()
{
    QTime tCurrTime = QTime::currentTime();

    if(tCurrTime > getFajr() && tCurrTime <= getDhuhr())
        return PrayerTimes::Fajr;

    if(tCurrTime > getDhuhr() && tCurrTime <= getAsr())
        return PrayerTimes::Dhuhr;

    if(tCurrTime > getAsr() && tCurrTime <= getMaghrib())
        return PrayerTimes::Asr;

    if(tCurrTime > getMaghrib() && tCurrTime <= getIsha())
        return PrayerTimes::Maghrib;

    if(tCurrTime > getIsha() || tCurrTime <= getFajr())
        return PrayerTimes::Isha;
}

void AthanManager::oneSecondTimeOut()
{    
    QTime start(0,0,0);
    QTime untilTime = untilNextPrayer();
    int diffNext = start.secsTo(untilTime);

    QTime passedTime = passedPrevPrayer();
    int diffPrev = start.secsTo(passedTime);

    if(diffNext == 1)
        m_state = AthanTime;
    else if(diffNext <= 30 * 60)
        m_state = BeforAthan;
    else if(diffPrev <= 20 * 60)
    {
        if(m_state != PlayingAthan)
            m_state = PrayerTime;
    }
    else{
        if(m_state != PlayingAthan)
            m_state = NextPrayer;
    }

    updateState();
}

void AthanManager::onAthanFinished()
{
    m_state = AthanFinished;
    emit athanFinished();
}

QTime AthanManager::passedPrevPrayer()
{
    QTime tPrevTime = getPrevTime();
    QTime tPassedTime(0,0,0);
    return tPassedTime.addSecs(tPrevTime.secsTo(QTime::currentTime()));
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

void AthanManager::updateState()
{
    switch(m_state)
    {
    case BeforAthan:
        emit beforAthan(nextPrayerTime(), untilNextPrayer());
        break;
    case AthanTime:
        emit athanTime(nextPrayerTime());
        m_state = PlayingAthan;
        break;
    case PrayerTime:
        emit itsPrayerTime(prevPrayerTime());
        break;
    case NextPrayer:
        if(m_currNextPrayer != nextPrayerTime())
            emit updateNextPrayer(nextPrayerTime());
        emit updateUntilNextTime(nextPrayerTime(), untilNextPrayer());
        break;
    }
}
