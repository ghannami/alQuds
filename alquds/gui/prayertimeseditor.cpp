#include "prayertimeseditor.h"
#include "ui_prayertimeseditor.h"
#include "locationsettings.h"
#include "prayertimes.hpp"
#include "generalsettings.h"

PrayerTimesEditor::PrayerTimesEditor(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::PrayerTimesEditor)
{
    ui->setupUi(this);
    readFields();
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(readFields()));
    connect(ui->adjMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(onFieldChanged()));
    connect(ui->asrMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(onFieldChanged()));
    connect(ui->calcMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(onFieldChanged()));
    connect(ui->dhurMinutesEdit, SIGNAL(valueChanged(double)), this, SLOT(onFieldChanged()));
    ui->startWithSys->setChecked(GeneralSettings::instance()->startWithSystem());
    connect(ui->startWithSys, SIGNAL(toggled(bool)), this, SLOT(onStartWithSysChanged(bool)));
}

PrayerTimesEditor::~PrayerTimesEditor()
{
    delete ui;
}

void PrayerTimesEditor::readFields()
{
    ui->calcMethEdit->clear();

    ui->calcMethEdit->addItem(tr("Ithna Ashari"), PrayerTimes::Jafari);
//    ui->calcMethEdit->addItem(tr("University of Islamic Sciences, Karachi"), PrayerTimes::Karachi);
    ui->calcMethEdit->addItem(tr("Karachi"), PrayerTimes::Karachi);
//    ui->calcMethEdit->addItem(tr("Islamic Society of North America (ISNA)"), PrayerTimes::ISNA);
    ui->calcMethEdit->addItem(tr("ISNA"), PrayerTimes::ISNA);
//    ui->calcMethEdit->addItem(tr("Muslim World League (MWL)"), PrayerTimes::MWL);
    ui->calcMethEdit->addItem(tr("Muslim World League"), PrayerTimes::MWL);
    ui->calcMethEdit->addItem(tr("Umm al-Qura"), PrayerTimes::Makkah);
    ui->calcMethEdit->addItem(tr("Egyptian"), PrayerTimes::Egypt);
    ui->calcMethEdit->setCurrentIndex(LocationSettings::instance()->calculationMethod());

    ui->adjMethEdit->clear();
    ui->adjMethEdit->addItem(tr("No adjustment"), PrayerTimes::None);
    ui->adjMethEdit->addItem(tr("Middle of night"), PrayerTimes::MidNight);
    ui->adjMethEdit->addItem(tr("1/7th of night"), PrayerTimes::OneSeventh);
    ui->adjMethEdit->addItem(tr("Angle/60th of night"), PrayerTimes::AngleBased);
    ui->adjMethEdit->setCurrentIndex(LocationSettings::instance()->adjustingMethod());

    ui->asrMethEdit->clear();
    ui->asrMethEdit->addItem(tr("Shafii, Maliki, Hanbali"), PrayerTimes::Shafii);
    ui->asrMethEdit->addItem(tr("Hanafi"), PrayerTimes::Hanafi);
    ui->asrMethEdit->setCurrentIndex(LocationSettings::instance()->asrMethod());

    ui->dhurMinutesEdit->setValue(LocationSettings::instance()->dhuhrMinutes());

    ui->saveButton->setDisabled(true);
}

void PrayerTimesEditor::saveSettings()
{
    LocationSettings::instance()->setCalculationMethod(ui->calcMethEdit->itemData(ui->calcMethEdit->currentIndex()).toInt());
    LocationSettings::instance()->setAdjustingMethod(ui->adjMethEdit->itemData(ui->adjMethEdit->currentIndex()).toInt());
    LocationSettings::instance()->setAsrMethod(ui->asrMethEdit->itemData(ui->asrMethEdit->currentIndex()).toInt());
    LocationSettings::instance()->setDhuhrMinutes(ui->dhurMinutesEdit->value());
    GeneralSettings::instance()->setStartWithSystem(ui->startWithSys->isChecked());

    ui->saveButton->setDisabled(true);
}

void PrayerTimesEditor::onFieldChanged()
{
    ui->saveButton->setEnabled(true);
}

void PrayerTimesEditor::onStartWithSysChanged(bool v)
{
    //GeneralSettings::instance()->setStartWithSystem(v);
    ui->saveButton->setEnabled(true);
}
