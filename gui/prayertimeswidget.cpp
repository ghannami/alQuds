#include "prayertimeswidget.h"
#include "ui_prayertimeswidget.h"
#include "../prayertimes/athanmanager.h"
#include "../tools/settings.h"
#include <QDebug>
#include <QStandardItemModel>

PrayerTimesWidget::PrayerTimesWidget(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::PrayerTimesWidget)
{
    ui->setupUi(this);
    mAthanManager = new AthanManager(this);
    connect(Settings::instance(), SIGNAL(locationChanged()), this, SLOT(updateTimes()));
    connect(Settings::instance(), SIGNAL(prayerConfigChanged()), this, SLOT(updateTimes()));

    updateTimes();
}

PrayerTimesWidget::~PrayerTimesWidget()
{
    delete ui;
}

void PrayerTimesWidget::updateTimes()
{
    ui->fajrTime->setText(mAthanManager->getFajr().toString("hh:mm"));
    ui->shurukTime->setText(mAthanManager->getSunrise().toString("hh:mm"));
    ui->dhurTime->setText(mAthanManager->getDhuhr().toString("hh:mm"));
    ui->asrTime->setText(mAthanManager->getAsr().toString("hh:mm"));
    ui->maghribTime->setText(mAthanManager->getMaghrib().toString("hh:mm"));
    ui->ishaTime->setText(mAthanManager->getIsha().toString("hh:mm"));

//    ui->untilTime->setText(mAthanManager->untilNextPrayer().toString());
//    if(mAthanManager->getNextPrayerTime() == PrayerTimes::Fajr)
//        ui->fajrIcon->setPixmap(QPixmap(":/icons/12/active.png"));
//    else ui->fajrIcon->setPixmap(QPixmap(""));

//    if(mAthanManager->getNextPrayerTime() == PrayerTimes::Sunrise)
//        ui->shurukIcon->setPixmap(QPixmap(":/icons/12/active.png"));
//    else ui->shurukIcon->setPixmap(QPixmap(""));

//    if(mAthanManager->getNextPrayerTime() == PrayerTimes::Dhuhr)
//        ui->dhurIcon->setPixmap(QPixmap(":/icons/12/active.png"));
//    else ui->dhurIcon->setPixmap(QPixmap(""));

//    if(mAthanManager->getNextPrayerTime() ==  PrayerTimes::Asr)
//        ui->asrIcon->setPixmap(QPixmap(":/icons/12/active.png"));
//    else ui->asrIcon->setPixmap(QPixmap(""));

//    if(mAthanManager->getNextPrayerTime() ==  PrayerTimes::Maghrib)
//        ui->maghribIcon->setPixmap(QPixmap(":/icons/12/active.png"));
//    else ui->maghribIcon->setPixmap(QPixmap(""));

//    if(mAthanManager->getNextPrayerTime() ==   PrayerTimes::Isha)
//        ui->ishaIcon->setPixmap(QPixmap(":/icons/12/active.png"));
//    else ui->ishaIcon->setPixmap(QPixmap(""));
}
