#include "athaneditor.h"
#include "ui_athaneditor.h"
#include "../settings/athansettings.h"
#include <QtGui>
#include <QtWidgets>
#include "../prayertimes/prayertimes.hpp"
#include "../multimedia/athanplayer.h"

AthanEditor::AthanEditor(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::AthanEditor)
{
    ui->setupUi(this);

    connect(ui->fajrBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectFajrFile(int)));
    connect(ui->dhurBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectDhurFile(int)));
    connect(ui->asrBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectAsrFile(int)));
    connect(ui->maghribBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectMaghribFile(int)));
    connect(ui->ishaBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectIshaFile(int)));

    mPlayer = new AthanPlayer();

    connect(ui->playFajr, SIGNAL(clicked()), this, SLOT(playFajrAthan()));
    connect(ui->playDhur, SIGNAL(clicked()), this, SLOT(playDhurAthan()));
    connect(ui->playAsr, SIGNAL(clicked()), this, SLOT(playAsrAthan()));
    connect(ui->playMaghrib, SIGNAL(clicked()), this, SLOT(playMaghribAthan()));
    connect(ui->playIsha, SIGNAL(clicked()), this, SLOT(playIshaAthan()));

    connect(ui->enableSilent, SIGNAL(toggled(bool)), this, SLOT(onFieldsChanged()));
    connect(ui->playDua, SIGNAL(toggled(bool)), this, SLOT(onFieldsChanged()));

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(readSettings()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), ui->saveButton, SLOT(setEnabled(bool)));

    //connect(AthanSettings::instance(), SIGNAL(silentModeChanged(bool)), this, SLOT(onSilentModeChanged(bool)));

    readSettings();
    ui->saveButton->setDisabled(true);

}

AthanEditor::~AthanEditor()
{
    delete ui;
}

void AthanEditor::readSettings()
{
    mFajrFile = AthanSettings::instance()->fajrFile();
    mDuhrFile = AthanSettings::instance()->dhurFile();
    mAsrFile  = AthanSettings::instance()->asrFile();
    mMaghribFile = AthanSettings::instance()->maghribFile();
    mIshaFile = AthanSettings::instance()->ishaFile();
    ui->enableSilent->setChecked(AthanSettings::instance()->silentMode());
    ui->playDua->setChecked(AthanSettings::instance()->playDua());

    initAthanFiles();

    ui->saveButton->setDisabled(true);
}

void AthanEditor::initAthanFiles()
{
    ui->fajrBox->clear();
    QFileInfo tFileInfo(mFajrFile);
    ui->fajrBox->addItem(tFileInfo.fileName());

    ui->fajrBox->insertSeparator(1);
    ui->fajrBox->addItem("Select...", PrayerTimes::Fajr);

    ui->dhurBox->clear();
    tFileInfo = QFileInfo(mDuhrFile);
    ui->dhurBox->addItem(tFileInfo.fileName());
    ui->dhurBox->insertSeparator(1);
    ui->dhurBox->addItem("Select...", PrayerTimes::Dhuhr);

    ui->asrBox->clear();
    tFileInfo = QFileInfo(mAsrFile);
    ui->asrBox->addItem(tFileInfo.fileName());
    ui->asrBox->insertSeparator(1);
    ui->asrBox->addItem("Select...", PrayerTimes::Asr);

    ui->maghribBox->clear();
    tFileInfo = QFileInfo(mMaghribFile);
    ui->maghribBox->addItem(tFileInfo.fileName());
    ui->maghribBox->insertSeparator(1);
    ui->maghribBox->addItem("Select...", PrayerTimes::Maghrib);

    ui->ishaBox->clear();
    tFileInfo = QFileInfo(mIshaFile);
    ui->ishaBox->addItem(tFileInfo.fileName());
    ui->ishaBox->insertSeparator(1);
    ui->ishaBox->addItem("Select...", PrayerTimes::Isha);

    ui->saveButton->setEnabled(true);
}

void AthanEditor::onFieldsChanged()
{
    ui->saveButton->setEnabled(true);
}

void AthanEditor::selectFajrFile(int xIndex)
{
    if(ui->fajrBox->itemData(xIndex) != PrayerTimes::Fajr)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        mFajrFile = tFileName;
    }
    initAthanFiles();
    ui->saveButton->setEnabled(true);
}

void AthanEditor::onSilentModeChanged(bool v)
{
    if(ui->enableSilent->isChecked() != v)
        ui->enableSilent->setChecked(v);
}

void AthanEditor::playFajrAthan()
{
    ui->playDhur->setChecked(false);
    ui->playAsr->setChecked(false);
    ui->playMaghrib->setChecked(false);
    ui->playIsha->setChecked(false);

    mPlayer->playFajrAthan(ui->playFajr->isChecked());
}

void AthanEditor::playDhurAthan()
{
    ui->playFajr->setChecked(false);
    ui->playAsr->setChecked(false);
    ui->playMaghrib->setChecked(false);
    ui->playIsha->setChecked(false);

    mPlayer->playDhurAthan(ui->playDhur->isChecked());
}

void AthanEditor::playAsrAthan()
{
    ui->playFajr->setChecked(false);
    ui->playDhur->setChecked(false);
    ui->playMaghrib->setChecked(false);
    ui->playIsha->setChecked(false);

    mPlayer->playAsrAthan(ui->playAsr->isChecked());
}

void AthanEditor::playMaghribAthan()
{
    ui->playFajr->setChecked(false);
    ui->playDhur->setChecked(false);
    ui->playAsr->setChecked(false);
    ui->playIsha->setChecked(false);

    mPlayer->playMaghribAthan(ui->playMaghrib->isChecked());
}

void AthanEditor::playIshaAthan()
{
    ui->playFajr->setChecked(false);
    ui->playDhur->setChecked(false);
    ui->playAsr->setChecked(false);
    ui->playMaghrib->setChecked(false);

    mPlayer->playIshaAthan(ui->playIsha->isChecked());
}

void AthanEditor::selectDhurFile(int xIndex)
{
    if(ui->dhurBox->itemData(xIndex) != PrayerTimes::Dhuhr)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        mDuhrFile = tFileName;
//        qDebug()<<"AthanEditor::selectDhurFile SELECTED FILE: "<<mDuhrFile;
    }
    initAthanFiles();
    ui->saveButton->setEnabled(true);
}

void AthanEditor::selectAsrFile(int xIndex)
{
    if(ui->asrBox->itemData(xIndex) != PrayerTimes::Asr)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        mAsrFile = tFileName;
    }
    initAthanFiles();
    ui->saveButton->setEnabled(true);
}

void AthanEditor::selectMaghribFile(int xIndex)
{
    if(ui->maghribBox->itemData(xIndex) != PrayerTimes::Maghrib)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        mMaghribFile = tFileName;
    }
    initAthanFiles();
    ui->saveButton->setEnabled(true);
}

void AthanEditor::selectIshaFile(int xIndex)
{
    if(ui->ishaBox->itemData(xIndex) != PrayerTimes::Isha)
        return;

    QString tFileName = QFileDialog::getOpenFileName();
    if(!tFileName.isEmpty())
    {
        mIshaFile = tFileName;
    }
    initAthanFiles();
    ui->saveButton->setEnabled(true);
}

void AthanEditor::saveSettings()
{
    AthanSettings::instance()->setFajrFile(mFajrFile);
    AthanSettings::instance()->setDhurFile(mDuhrFile);
    AthanSettings::instance()->setAsrFile(mAsrFile);
    AthanSettings::instance()->setMaghribFile(mMaghribFile);
    AthanSettings::instance()->setIshaFile(mIshaFile);

    AthanSettings::instance()->setSilentMode(ui->enableSilent->isChecked());
    AthanSettings::instance()->setPlayDua(ui->playDua->isChecked());

    ui->saveButton->setDisabled(true);

}
