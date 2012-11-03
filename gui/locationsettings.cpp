#include "locationsettings.h"
#include "ui_locationsettings.h"
#include "../tools/settings.h"
#include "webservices/downloadmanager.h"
#include <QDomDocument>
#include <QTreeWidgetItem>
#include "../prayertimes/prayertimes.hpp"

LocationSettings::LocationSettings(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::LocationSettings)
{
    ui->setupUi(this);
    ui->cityEdit->setText(Settings::instance()->city());
    ui->countryEdit->setText(Settings::instance()->country());
    ui->latitudeEdit->setValue(Settings::instance()->latitude());
    ui->longitudeEdit->setValue(Settings::instance()->longitude());
    ui->timezoneEdit->setValue(Settings::instance()->timezone());
    ui->useSystemTZEdit->setChecked(Settings::instance()->useSystemTimezone());
    ui->timezoneEdit->setDisabled(ui->useSystemTZEdit->isChecked());
    //ui->resultView->setHidden(true);
    connect(ui->latitudeEdit, SIGNAL(valueChanged(double)), Settings::instance(), SLOT(setLatitude(double)));
    connect(ui->longitudeEdit, SIGNAL(valueChanged(double)), Settings::instance(), SLOT(setLongitude(double)));
    connect(ui->timezoneEdit, SIGNAL(valueChanged(double)), Settings::instance(), SLOT(setTimezone(double)));
    connect(ui->cityEdit, SIGNAL(textChanged(QString)), Settings::instance(), SLOT(setCity(QString)));
    connect(ui->countryEdit, SIGNAL(textChanged(QString)), Settings::instance(), SLOT(setCountry(QString)));
    connect(ui->useSystemTZEdit, SIGNAL(toggled(bool)), Settings::instance(), SLOT(setUseSystemTimezone(bool)));
    connect(ui->useSystemTZEdit, SIGNAL(toggled(bool)), ui->timezoneEdit, SLOT(setDisabled(bool)));

    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(OnSearchClicked()));
    connect(ui->resultView, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(OnLocationItemClicked(QTreeWidgetItem*)));

    ui->calcMethEdit->addItem(tr("Ithna Ashari"), PrayerTimes::Jafari);
//    ui->calcMethEdit->addItem(tr("University of Islamic Sciences, Karachi"), PrayerTimes::Karachi);
    ui->calcMethEdit->addItem(tr("Karachi"), PrayerTimes::Karachi);
//    ui->calcMethEdit->addItem(tr("Islamic Society of North America (ISNA)"), PrayerTimes::ISNA);
    ui->calcMethEdit->addItem(tr("ISNA"), PrayerTimes::ISNA);
//    ui->calcMethEdit->addItem(tr("Muslim World League (MWL)"), PrayerTimes::MWL);
    ui->calcMethEdit->addItem(tr("Muslim World League"), PrayerTimes::MWL);
    ui->calcMethEdit->addItem(tr("Umm al-Qura"), PrayerTimes::Makkah);
    ui->calcMethEdit->addItem(tr("Egyptian"), PrayerTimes::Egypt);
    ui->calcMethEdit->setCurrentIndex(Settings::instance()->calculationMethod());
    connect(ui->calcMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(OnMethodChanged(int)));

    ui->adjMethEdit->addItem(tr("No adjustment"), PrayerTimes::None);
    ui->adjMethEdit->addItem(tr("Middle of night"), PrayerTimes::MidNight);
    ui->adjMethEdit->addItem(tr("1/7th of night"), PrayerTimes::OneSeventh);
    ui->adjMethEdit->addItem(tr("Angle/60th of night"), PrayerTimes::AngleBased);
    ui->adjMethEdit->setCurrentIndex(Settings::instance()->adjustingMethod());
    connect(ui->adjMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(OnAdjustChanged(int)));

    ui->asrMethEdit->addItem(tr("Shafii, Maliki, Hanbali"), PrayerTimes::Shafii);
    ui->asrMethEdit->addItem(tr("Hanafi"), PrayerTimes::Hanafi);
    ui->asrMethEdit->setCurrentIndex(Settings::instance()->asrMethod());
    connect(ui->asrMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(OnAsrMethodChanged(int)));

    ui->dhurMinutesEdit->setValue(Settings::instance()->dhuhrMinutes());
    connect(ui->dhurMinutesEdit, SIGNAL(valueChanged(double)), Settings::instance(), SLOT(setDhuhrMinutes(double)));
}

LocationSettings::~LocationSettings()
{
    delete ui;
}

void LocationSettings::OnSearchClicked()
{
    if(ui->findCityEdit->text().isEmpty())
        return;
    DownloadManager * tDownload = new DownloadManager;
    connect(tDownload, SIGNAL(DownloadFinished(QByteArray)),this, SLOT(OnGeoDownloaded(QByteArray)));
    tDownload->Download(QString("http://api.geonames.org/search?name=%1&style=FULL&username=%2").arg(ui->findCityEdit->text()).arg("aziz"));

    ui->resultView->setVisible(true);
}

void LocationSettings::OnGeoDownloaded(QByteArray xData)
{
    QDomDocument doc("citysettings");
    doc.setContent(xData) ;
    QDomElement tLocationElement = doc.documentElement().firstChildElement("geoname");
    ui->resultView->clear();
    //ui->verticalLayout->removeItem(ui->verticalSpacer);
    int i = 0;
    while(!tLocationElement.isNull())
    {
        QTreeWidgetItem *locationItem = new QTreeWidgetItem();
        locationItem->setText(0,tLocationElement.firstChildElement("name").text());
        locationItem->setText(1,tLocationElement.firstChildElement("adminName1").text());
        locationItem->setText(2,tLocationElement.firstChildElement("countryName").text());
        locationItem->setText(3,tLocationElement.firstChildElement("lat").text());
        locationItem->setText(4,tLocationElement.firstChildElement("lng").text());
        locationItem->setText(5,tLocationElement.firstChildElement("timezone").attribute("gmtOffset"));

        ui->resultView->insertTopLevelItem(i++, locationItem);
        tLocationElement = tLocationElement.nextSiblingElement("geoname");
    }
    ui->resultView->resizeColumnToContents(0);
    ui->resultView->resizeColumnToContents(1);
    ui->resultView->resizeColumnToContents(2);
}

void LocationSettings::OnLocationItemClicked(QTreeWidgetItem *xItem)
{
    if(!xItem)
        return;

    ui->cityEdit->setText(xItem->text(0));
    ui->countryEdit->setText(xItem->text(2));
    ui->latitudeEdit->setValue(xItem->text(3).toDouble());
    ui->longitudeEdit->setValue(xItem->text(4).toDouble());
    ui->timezoneEdit->setValue(xItem->text(5).toDouble());
}

void LocationSettings::OnMethodChanged(int xIndex)
{
    Settings::instance()->setCalculationMethod(ui->calcMethEdit->itemData(xIndex).toInt());
}

void LocationSettings::OnAdjustChanged(int xIndex)
{
    Settings::instance()->setAdjustingMethod(ui->adjMethEdit->itemData(xIndex).toInt());
}

void LocationSettings::OnAsrMethodChanged(int xIndex)
{
    Settings::instance()->setAsrMethod(ui->asrMethEdit->itemData(xIndex).toInt());
}
