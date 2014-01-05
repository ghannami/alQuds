#include "homewidget.h"
#include "ui_homewidget.h"
#include "athanmanager.h"
#include "locationsettings.h"
#include "wathakkerservice.h"

HomeWidget::HomeWidget(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::HomeWidget)
{
    ui->setupUi(this);
    mAthanManager = new AthanManager(this);
    connect(LocationSettings::instance(), SIGNAL(locationChanged()), this, SLOT(updateTimes()));
    connect(LocationSettings::instance(), SIGNAL(prayerConfigChanged()), this, SLOT(updateTimes()));

    connect(mAthanManager, SIGNAL(updateNextPrayer(PrayerTimes::TimeID)), this, SLOT(updateNextPrayerTime(PrayerTimes::TimeID)));
    connect(mAthanManager, SIGNAL(updateUntilNextTime(PrayerTimes::TimeID, QTime)), this, SLOT(updateUntilNextTime(PrayerTimes::TimeID, QTime)));
    connect(mAthanManager, SIGNAL(athanTime(PrayerTimes::TimeID)), this, SLOT(itsAthanTime(PrayerTimes::TimeID)));
    connect(mAthanManager, SIGNAL(itsPrayerTime(PrayerTimes::TimeID)), this, SLOT(itsPrayerTime(PrayerTimes::TimeID)));
    connect(mAthanManager, SIGNAL(beforAthan(PrayerTimes::TimeID, QTime)), this, SLOT(itsBeforAthan(PrayerTimes::TimeID, QTime)));

    mPrayerLabels.insert(PrayerTimes::Fajr, ui->fajrLabel);
    mPrayerLabels.insert(PrayerTimes::Dhuhr, ui->dhurLabel);
    mPrayerLabels.insert(PrayerTimes::Asr, ui->asrLabel);
    mPrayerLabels.insert(PrayerTimes::Maghrib, ui->maghribLabel);
    mPrayerLabels.insert(PrayerTimes::Isha, ui->ishaLabel);

    mPrayerTimesLabels.insert(PrayerTimes::Fajr, ui->fajrTime);
    mPrayerTimesLabels.insert(PrayerTimes::Dhuhr, ui->dhurTime);
    mPrayerTimesLabels.insert(PrayerTimes::Asr, ui->asrTime);
    mPrayerTimesLabels.insert(PrayerTimes::Maghrib, ui->maghribTime);
    mPrayerTimesLabels.insert(PrayerTimes::Isha, ui->ishaTime);

    updateTimes();
    updateNextPrayerTime(mAthanManager->nextPrayerTime());
/*
    QPixmap bg(":/images/quds-moschee.png");
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);
    setAutoFillBackground(true);
    setPalette(p);
*/
//    WathakkerService *mWathakkertService = new WathakkerService();
//    mWathakkertService->requestRandomHadith(300000);
//    connect(mWathakkertService, SIGNAL(responseXML(QDomDocument)), this, SLOT(updateServiceContent(QDomDocument)));
    ui->serviceBox->setHidden(true);
}

HomeWidget::~HomeWidget()
{
    delete ui;
}

void HomeWidget::updateTimes()
{
    ui->fajrTime->setText(mAthanManager->getFajr().toString("hh:mm"));
    ui->shurukTime->setText(mAthanManager->getSunrise().toString("hh:mm"));
    ui->dhurTime->setText(mAthanManager->getDhuhr().toString("hh:mm"));
    ui->asrTime->setText(mAthanManager->getAsr().toString("hh:mm"));
    ui->maghribTime->setText(mAthanManager->getMaghrib().toString("hh:mm"));
    ui->ishaTime->setText(mAthanManager->getIsha().toString("hh:mm"));

    updateLocation();
}

void HomeWidget::updateNextPrayerTime(PrayerTimes::TimeID xTimeID)
{
    foreach(QLabel *label, mPrayerLabels)
        label->setFont(QFont());
    foreach(QLabel *label, mPrayerTimesLabels)
        label->setFont(QFont());
    ui->nextPrayerLabel->setText(tr("The next prayer is")+": "+ mAthanManager->prayerTimeByName(xTimeID)+ " " +mAthanManager->nextPrayerTime());
    QFont font;
    font.setBold(true);
    mPrayerLabels.value(xTimeID)->setFont(font);
    mPrayerTimesLabels.value(xTimeID)->setFont(font);
}

void HomeWidget::updateUntilNextTime(PrayerTimes::TimeID, QTime xTime)
{
    ui->untilTimeLabel->setText(xTime.toString());
    ui->dateLabel->setText(QDate::currentDate().toString("dddd, dd. MMMM yyyy"));
}

void HomeWidget::updateLocation()
{
    ui->locationLabel->setText(LocationSettings::instance()->country() + ", "+ LocationSettings::instance()->city());
}

void HomeWidget::updateServiceContent(QDomDocument xDoc)
{
    if(!xDoc.firstChildElement().firstChildElement("content").text().isEmpty())
    {
        ui->serviceContent->setText(xDoc.firstChildElement().firstChildElement("content").text());
        ui->serviceBox->setVisible(true);
    }
}

void HomeWidget::itsAthanTime(PrayerTimes::TimeID xTimeID)
{
    ui->nextPrayerLabel->setText(tr("Calling for")+" "+mAthanManager->prayerTimeByName(xTimeID));
    ui->untilTimeLabel->setPixmap(QPixmap(":icons/32/speaker.png"));
}

void HomeWidget::itsBeforAthan(PrayerTimes::TimeID, QTime xTime)
{
    ui->untilTimeLabel->setText(xTime.toString());
}

void HomeWidget::itsPrayerTime(PrayerTimes::TimeID xTimeID)
{
    ui->nextPrayerLabel->setText(tr("it´s")+ " "+mAthanManager->prayerTimeByName(xTimeID)+ tr(" prayer time"));
    ui->untilTimeLabel->setText(" ");

}
