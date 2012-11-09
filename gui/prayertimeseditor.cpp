#include "prayertimeseditor.h"
#include "ui_prayertimeseditor.h"
#include "../settings/locationsettings.h"
#include "../prayertimes/prayertimes.hpp"

PrayerTimesEditor::PrayerTimesEditor(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::PrayerTimesEditor)
{
    ui->setupUi(this);
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
    connect(ui->calcMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(OnMethodChanged(int)));

    ui->adjMethEdit->addItem(tr("No adjustment"), PrayerTimes::None);
    ui->adjMethEdit->addItem(tr("Middle of night"), PrayerTimes::MidNight);
    ui->adjMethEdit->addItem(tr("1/7th of night"), PrayerTimes::OneSeventh);
    ui->adjMethEdit->addItem(tr("Angle/60th of night"), PrayerTimes::AngleBased);
    ui->adjMethEdit->setCurrentIndex(LocationSettings::instance()->adjustingMethod());
    connect(ui->adjMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(OnAdjustChanged(int)));

    ui->asrMethEdit->addItem(tr("Shafii, Maliki, Hanbali"), PrayerTimes::Shafii);
    ui->asrMethEdit->addItem(tr("Hanafi"), PrayerTimes::Hanafi);
    ui->asrMethEdit->setCurrentIndex(LocationSettings::instance()->asrMethod());
    connect(ui->asrMethEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(OnAsrMethodChanged(int)));

    ui->dhurMinutesEdit->setValue(LocationSettings::instance()->dhuhrMinutes());
    connect(ui->dhurMinutesEdit, SIGNAL(valueChanged(double)), LocationSettings::instance(), SLOT(setDhuhrMinutes(double)));

}

PrayerTimesEditor::~PrayerTimesEditor()
{
    delete ui;
}

void PrayerTimesEditor::OnMethodChanged(int xIndex)
{
    LocationSettings::instance()->setCalculationMethod(ui->calcMethEdit->itemData(xIndex).toInt());
}

void PrayerTimesEditor::OnAdjustChanged(int xIndex)
{
    LocationSettings::instance()->setAdjustingMethod(ui->adjMethEdit->itemData(xIndex).toInt());
}

void PrayerTimesEditor::OnAsrMethodChanged(int xIndex)
{
    LocationSettings::instance()->setAsrMethod(ui->asrMethEdit->itemData(xIndex).toInt());
}
