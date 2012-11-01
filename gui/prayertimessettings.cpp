#include "prayertimessettings.h"
#include "ui_prayertimessettings.h"

PrayerTimesSettings::PrayerTimesSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrayerTimesSettings)
{
    ui->setupUi(this);
}

PrayerTimesSettings::~PrayerTimesSettings()
{
    delete ui;
}
