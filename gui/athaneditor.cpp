#include "athaneditor.h"
#include "ui_athaneditor.h"
#include "../settings/athansettings.h"
#include <QtGui>
#include "prayertimes/prayertimes.hpp"
#include "multimedia/athanplayer.h"

AthanEditor::AthanEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AthanEditor)
{
    ui->setupUi(this);
    readAthanFiles();
    connect(ui->fajrBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectFajrFile(int)));
    connect(ui->dhurBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectDhurFile(int)));
    connect(ui->asrBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectAsrFile(int)));
    connect(ui->maghribBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectMaghribFile(int)));
    connect(ui->ishaBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectIshaFile(int)));
    mPlayer = new AthanPlayer(this);

    connect(ui->playFajr, SIGNAL(clicked()), mPlayer, SLOT(playFajrAthan()));
    connect(ui->playDhur, SIGNAL(clicked()), mPlayer, SLOT(playDhurAthan()));
    connect(ui->playAsr, SIGNAL(clicked()), mPlayer, SLOT(playAsrAthan()));
    connect(ui->playMaghrib, SIGNAL(clicked()), mPlayer, SLOT(playMaghribAthan()));
    connect(ui->playIsha, SIGNAL(clicked()), mPlayer, SLOT(playIshaAthan()));

    connect(ui->stopFajr, SIGNAL(clicked()), mPlayer, SLOT(stopAthan()));
    connect(ui->stopDhur, SIGNAL(clicked()), mPlayer, SLOT(stopAthan()));
    connect(ui->stopAsr, SIGNAL(clicked()), mPlayer, SLOT(stopAthan()));
    connect(ui->stopMaghrib, SIGNAL(clicked()), mPlayer, SLOT(stopAthan()));
    connect(ui->stopIsha, SIGNAL(clicked()), mPlayer, SLOT(stopAthan()));

    ui->enableSilent->setChecked(AthanSettings::instance()->silentMode());
    connect(ui->enableSilent, SIGNAL(toggled(bool)), AthanSettings::instance(), SLOT(setSilentMode(bool)));
    ui->playDua->setChecked(AthanSettings::instance()->playDua());
    connect(ui->playDua, SIGNAL(toggled(bool)), AthanSettings::instance(), SLOT(setPlayDua(bool)));
}

AthanEditor::~AthanEditor()
{
    delete ui;
}

void AthanEditor::readAthanFiles()
{
    ui->fajrBox->clear();
    QFileInfo tFileInfo(AthanSettings::instance()->fajrFile());
    ui->fajrBox->addItem(tFileInfo.fileName());
    ui->fajrBox->insertSeparator(1);
    ui->fajrBox->addItem("Select...", PrayerTimes::Fajr);

    ui->dhurBox->clear();
    tFileInfo = QFileInfo(AthanSettings::instance()->dhurFile());
    ui->dhurBox->addItem(tFileInfo.fileName());
    ui->dhurBox->insertSeparator(1);
    ui->dhurBox->addItem("Select...", PrayerTimes::Dhuhr);

    ui->asrBox->clear();
    tFileInfo = QFileInfo(AthanSettings::instance()->asrFile());
    ui->asrBox->addItem(tFileInfo.fileName());
    ui->asrBox->insertSeparator(1);
    ui->asrBox->addItem("Select...", PrayerTimes::Asr);

    ui->maghribBox->clear();
    tFileInfo = QFileInfo(AthanSettings::instance()->maghribFile());
    ui->maghribBox->addItem(tFileInfo.fileName());
    ui->maghribBox->insertSeparator(1);
    ui->maghribBox->addItem("Select...", PrayerTimes::Maghrib);

    ui->ishaBox->clear();
    tFileInfo = QFileInfo(AthanSettings::instance()->ishaFile());
    ui->ishaBox->addItem(tFileInfo.fileName());
    ui->ishaBox->insertSeparator(1);
    ui->ishaBox->addItem("Select...", PrayerTimes::Isha);


}

void AthanEditor::selectFajrFile(int xIndex)
{
    if(ui->fajrBox->itemData(xIndex) != PrayerTimes::Fajr)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        AthanSettings::instance()->setFajrFile(tFileName);
    }
    readAthanFiles();
}

void AthanEditor::selectDhurFile(int xIndex)
{
    if(ui->dhurBox->itemData(xIndex) != PrayerTimes::Dhuhr)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        AthanSettings::instance()->setDhurFile(tFileName);
    }
    readAthanFiles();
}

void AthanEditor::selectAsrFile(int xIndex)
{
    if(ui->asrBox->itemData(xIndex) != PrayerTimes::Asr)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        AthanSettings::instance()->setAsrFile(tFileName);
    }
    readAthanFiles();
}

void AthanEditor::selectMaghribFile(int xIndex)
{
    if(ui->maghribBox->itemData(xIndex) != PrayerTimes::Maghrib)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        AthanSettings::instance()->setMaghribFile(tFileName);
    }
    readAthanFiles();
}

void AthanEditor::selectIshaFile(int xIndex)
{
    if(ui->ishaBox->itemData(xIndex) != PrayerTimes::Isha)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        AthanSettings::instance()->setIshaFile(tFileName);
    }
    readAthanFiles();
}
