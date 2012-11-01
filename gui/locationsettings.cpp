#include "locationsettings.h"
#include "ui_locationsettings.h"
#include "../tools/settings.h"
#include "webservices/downloadmanager.h"
#include <QDomDocument>
#include <QTreeWidgetItem>

LocationSettings::LocationSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocationSettings)
{
    ui->setupUi(this);
    ui->cityEdit->setText(Settings::instance()->city());
    ui->countryEdit->setText(Settings::instance()->country());
    ui->latitudeEdit->setValue(Settings::instance()->latitude());
    ui->longitudeEdit->setValue(Settings::instance()->longitude());
    ui->timezoneEdit->setValue(Settings::instance()->timezone());
    ui->useSystemTZEdit->setChecked(Settings::instance()->useSystemTimezone());

    ui->resultView->setHidden(true);
    connect(ui->latitudeEdit, SIGNAL(valueChanged(double)), Settings::instance(), SLOT(setLatitude(double)));
    connect(ui->longitudeEdit, SIGNAL(valueChanged(double)), Settings::instance(), SLOT(setLongitude(double)));
    connect(ui->timezoneEdit, SIGNAL(valueChanged(double)), Settings::instance(), SLOT(setTimezone(double)));
    connect(ui->cityEdit, SIGNAL(textChanged(QString)), Settings::instance(), SLOT(setCity(QString)));
    connect(ui->countryEdit, SIGNAL(textChanged(QString)), Settings::instance(), SLOT(setCountry(QString)));
    connect(ui->useSystemTZEdit, SIGNAL(toggled(bool)), Settings::instance(), SLOT(setUseSystemTimezone(bool)));

    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(OnSearchClicked()));
}

LocationSettings::~LocationSettings()
{
    delete ui;
}

void LocationSettings::OnSearchClicked()
{
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
    ui->verticalLayout->removeItem(ui->verticalSpacer);
    int i = 0;
    while(!tLocationElement.isNull())
    {
        QTreeWidgetItem *locationItem = new QTreeWidgetItem();
        locationItem->setText(0,tLocationElement.firstChildElement("name").text());
        locationItem->setText(1,tLocationElement.firstChildElement("adminName1").text());
        locationItem->setText(2,tLocationElement.firstChildElement("countryName").text());
        locationItem->setText(3,tLocationElement.firstChildElement("lng").text());
        locationItem->setText(4,tLocationElement.firstChildElement("lat").text());
        //locationItem->setText(0,tLocationElement.firstChildElement("timezone").attribute("gmtOffset");
        ui->resultView->insertTopLevelItem(i++, locationItem);

        tLocationElement = tLocationElement.nextSiblingElement("geoname");
    }
}
