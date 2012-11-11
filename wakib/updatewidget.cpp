#include "updatewidget.h"
#include "ui_updatewidget.h"
#include <QtGui>
#include "webservices/downloadmanager.h"
#include <QDomDocument>
#include "zipzap.h"
#include <wakiblauncher.h>

UpdateWidget::UpdateWidget(WakibLauncher *launcher) :
    mLauncher(launcher), ui(new Ui::UpdateWidget)
{
    ui->setupUi(this);
    //ui->progressBar->setHidden(true);

#if defined(Q_OS_WIN)
    mCastUrl = "http://ghannami.de/files/win/alqudscast.xml";

#elif defined(Q_OS_MAC)
    mCastUrl = "http://ghannami.de/files/mac/alqudscast.xml";
#endif

    DownloadManager *request = new DownloadManager;
    request->Download(mCastUrl);
    connect(request, SIGNAL(DownloadFinished(QByteArray)), this, SLOT(castFileDownloaded(QByteArray)));
    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(onUpdateClicked()));
    connect(ui->laterButton, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
    connect(ui->skipButton, SIGNAL(clicked()), this, SLOT(onSkipClicked()));
    connect(ui->relaunchButton, SIGNAL(clicked()), this , SLOT(launchProgramm()));

    ui->relaunchButton->setHidden(true);
    //ui->successIcon->setHidden(true);
}

UpdateWidget::~UpdateWidget()
{
    delete ui;
}

void UpdateWidget::onUpdateClicked()
{
    //connect(request, SIGNAL())
    ui->updateButton->setEnabled(false);
    ui->skipButton->setEnabled(false);
    ui->progressBar->setVisible(true);
    DownloadManager *request = new DownloadManager;
    request->Download(mUpdateFileUrl);
    connect(request, SIGNAL(DownloadFinished(QByteArray)), this, SLOT(updateFileDownloaded(QByteArray)));
    connect(request, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(updateProgressBar(qint64,qint64)));
}

void UpdateWidget::onCancelClicked()
{
    mLauncher->launchProgramm();
}

void UpdateWidget::onSkipClicked()
{
    mLauncher->launchProgramm();
}

void UpdateWidget::castFileDownloaded(QByteArray xData)
{
    ui->progressBar->setHidden(true);
    QDomDocument tDoc("xml");
    tDoc.setContent(xData);
    ui->titelLabel->setText("<b>"+tDoc.firstChildElement().firstChildElement().firstChildElement("item").firstChildElement("title").text()+"</b>");
    ui->descriptionLabel->setText(tDoc.firstChildElement().firstChildElement().firstChildElement("item").firstChildElement("description").text());

    mUpdateFileUrl = tDoc.firstChildElement().firstChildElement().firstChildElement("item").firstChildElement("enclosure").attribute("url");
}

void UpdateWidget::updateFileDownloaded(QByteArray xData)
{
    QTemporaryFile file;
         if (file.open()) {
             // file.fileName() returns the unique file name
             file.write(xData);
             if(ZipZap::UnzipTo(&file, QDir::currentPath()+"/"))
             {
                 ui->updateButton->setHidden(true);
                 ui->skipButton->setHidden(true);
                 ui->laterButton->setHidden(true);
                 ui->relaunchButton->setVisible(true);
                 ui->successIcon->setVisible(true);
             }
         }
}

void UpdateWidget::updateProgressBar(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBar->setMaximum(bytesTotal);
    ui->progressBar->setValue(bytesReceived);
}

void UpdateWidget::launchProgramm()
{
    mLauncher->launchProgramm();
}
