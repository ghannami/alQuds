#include "prayertimeswidget.h"
#include "ui_prayertimeswidget.h"
#include "../prayertimes/athanmanager.h"
#include "../tools/settings.h"
#include <QDebug>
#include <QStandardItemModel>

PrayerTimesWidget::PrayerTimesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrayerTimesWidget)
{
    ui->setupUi(this);
    mAthanManager = new AthanManager(this);
    mModel = new QStandardItemModel(6, 2);
    mModel->setHeaderData(0, Qt::Horizontal, tr("Prayer"));
    mModel->setHeaderData(1, Qt::Horizontal, tr("Time"));
    ui->tableView->setModel(mModel);

    connect(Settings::instance(), SIGNAL(locationChanged()), this, SLOT(updateModel()));
    connect(Settings::instance(), SIGNAL(prayerConfigChanged()), this, SLOT(updateModel()));

    updateModel();
}

PrayerTimesWidget::~PrayerTimesWidget()
{
    delete ui;
}

void PrayerTimesWidget::updateModel()
{
    int i=0;
    mModel->setItem(i, 0, new QStandardItem(tr("Fajr")));
    mModel->setItem(i++, 1, new QStandardItem(mAthanManager->getFajr().toString()));
    mModel->setItem(i, 0, new QStandardItem(tr("Shuruk")));
    mModel->setItem(i++, 1, new QStandardItem(mAthanManager->getSunrise().toString()));
    mModel->setItem(i, 0, new QStandardItem(tr("Dhur")));
    mModel->setItem(i++, 1, new QStandardItem(mAthanManager->getDhuhr().toString()));
    mModel->setItem(i, 0, new QStandardItem(tr("Asr")));
    mModel->setItem(i++, 1, new QStandardItem(mAthanManager->getAsr().toString()));
    mModel->setItem(i, 0, new QStandardItem(tr("Marghib")));
    mModel->setItem(i++, 1, new QStandardItem(mAthanManager->getMaghrib().toString()));
    mModel->setItem(i, 0, new QStandardItem(tr("Isha")));
    mModel->setItem(i++, 1, new QStandardItem(mAthanManager->getIsha().toString()));
}
