#include "locationeditor.h"
#include "ui_locationeditor.h"
#include "../settings/locationsettings.h"
#include "../webservices/downloadmanager.h"
#include <QDomDocument>
#include <QTreeWidgetItem>
#include "../prayertimes/prayertimes.hpp"

LocationEditor::LocationEditor(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::LocationEditor)
{
    ui->setupUi(this);
    //ui->resultView->setHidden(true);

    connect(ui->useSystemTZEdit, SIGNAL(toggled(bool)), ui->timezoneEdit, SLOT(setDisabled(bool)));
    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(OnSearchClicked()));
    connect(ui->resultView, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(OnLocationItemClicked(QTreeWidgetItem*)));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveLocation()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(readLocation()));
    connect(ui->latitudeEdit, SIGNAL(valueChanged(double)), this, SLOT(onValueChanged()));
    connect(ui->longitudeEdit, SIGNAL(valueChanged(double)), this, SLOT(onValueChanged()));
    connect(ui->cityEdit, SIGNAL(textChanged(QString)), this, SLOT(onValueChanged()));
    connect(ui->countryEdit, SIGNAL(textChanged(QString)), this, SLOT(onValueChanged()));
    connect(ui->timezoneEdit, SIGNAL(valueChanged(double)), this, SLOT(onValueChanged()));
    connect(ui->useSystemTZEdit, SIGNAL(toggled(bool)), this, SLOT(onValueChanged()));
    readLocation();
}

LocationEditor::~LocationEditor()
{
    delete ui;
}

void LocationEditor::readLocation()
{
    ui->cityEdit->setText(LocationSettings::instance()->city());
    ui->countryEdit->setText(LocationSettings::instance()->country());
    ui->latitudeEdit->setValue(LocationSettings::instance()->latitude());
    ui->longitudeEdit->setValue(LocationSettings::instance()->longitude());
    ui->timezoneEdit->setValue(LocationSettings::instance()->timezone());
    ui->useSystemTZEdit->setChecked(LocationSettings::instance()->useSystemTimezone());
    ui->timezoneEdit->setDisabled(ui->useSystemTZEdit->isChecked());
    ui->saveButton->setDisabled(true);
}

void LocationEditor::saveLocation()
{
    LocationSettings::instance()->setLatitude(ui->latitudeEdit->value());
    LocationSettings::instance()->setLongitude(ui->longitudeEdit->value());
    LocationSettings::instance()->setTimezone(ui->timezoneEdit->value());
    LocationSettings::instance()->setCity(ui->cityEdit->text());
    LocationSettings::instance()->setCountry(ui->countryEdit->text());
    LocationSettings::instance()->setUseSystemTimezone(ui->useSystemTZEdit->isChecked());
    ui->saveButton->setDisabled(true);
}

void LocationEditor::OnSearchClicked()
{
    if(ui->findCityEdit->text().isEmpty())
        return;
    DownloadManager * tDownload = new DownloadManager;
    connect(tDownload, SIGNAL(DownloadFinished(QByteArray)),this, SLOT(OnGeoDownloaded(QByteArray)));
    tDownload->Download(QString("http://api.geonames.org/search?name=%1&style=FULL&username=%2").arg(ui->findCityEdit->text()).arg("aziz"));

    ui->resultView->setVisible(true);
}

void LocationEditor::OnGeoDownloaded(QByteArray xData)
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

void LocationEditor::OnLocationItemClicked(QTreeWidgetItem *xItem)
{
    if(!xItem)
        return;

    ui->cityEdit->setText(xItem->text(0));
    ui->countryEdit->setText(xItem->text(2));
    ui->latitudeEdit->setValue(xItem->text(3).toDouble());
    ui->longitudeEdit->setValue(xItem->text(4).toDouble());
    ui->timezoneEdit->setValue(xItem->text(5).toDouble());
}

void LocationEditor::onValueChanged()
{
    ui->saveButton->setEnabled(true);
}
