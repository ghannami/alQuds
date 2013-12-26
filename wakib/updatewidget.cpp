#include "updatewidget.h"
#include "ui_updatewidget.h"
#include <QtGui>
#include "../alquds/webservices/downloadmanager.h"
#include <QDomDocument>
#include "zipzap.h"
#include <wakiblauncher.h>
#include "../alquds/version.h"
#include "../alquds/settings/pathsettings.h"

UpdateWidget::UpdateWidget(WakibLauncher *launcher) :
    mLauncher(launcher), ui(new Ui::UpdateWidget)
{
    ui->setupUi(this);
    //ui->progressBar->setHidden(true);

#if defined(Q_OS_WIN)
    mCastUrl = "http://alquds.googlecode.com/files/wincast.xml";

#elif defined(Q_OS_MAC)
    mCastUrl = "http://alquds.googlecode.com/files/maccast.xml";
#endif

    DownloadManager *request = new DownloadManager;
    request->Download(mCastUrl);
    connect(request, SIGNAL(DownloadFinished(QByteArray)), this, SLOT(castFileDownloaded(QByteArray)));
    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(onUpdateClicked()));
    connect(ui->laterButton, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
    connect(ui->skipButton, SIGNAL(clicked()), this, SLOT(onSkipClicked()));
    connect(ui->relaunchButton, SIGNAL(clicked()), mLauncher , SIGNAL(relaunchAll()));
    ui->relaunchButton->setHidden(true);

    ui->successIcon->setHidden(true);
    setWindowTitle(tr("Alquds updater v. %1").arg(V_VERSION));
}

UpdateWidget::~UpdateWidget()
{
    delete ui;
}

bool UpdateWidget::isUpdateAvailable(QDomDocument xDoc)
{
    if(xDoc.firstChildElement().firstChildElement("version").isNull())
        return false;

    int tMajor = xDoc.firstChildElement().firstChildElement("version").attribute("major").toInt();
    int tMinor = xDoc.firstChildElement().firstChildElement("version").attribute("minor").toInt();
    int tBuild = xDoc.firstChildElement().firstChildElement("version").attribute("build").toInt();
    if(tMajor > V_VER_MAJOR || tMinor > V_VER_MINOR || tBuild > V_VER_BUILD)
        return true;

    return false;
}

void UpdateWidget::closeEvent(QCloseEvent *event)
{
    mLauncher->launchAlquds();
    QWidget::closeEvent(event);
}

void UpdateWidget::onUpdateClicked()
{
    ui->updateButton->setEnabled(false);
    ui->skipButton->setEnabled(false);
    QUrl url(mUpdateFileUrl);
    if(!url.isValid())
        close();
    ui->progressBar->setVisible(true);

    DownloadManager *request = new DownloadManager;
    request->Download(mUpdateFileUrl);
    connect(request, SIGNAL(DownloadFinished(QByteArray)), this, SLOT(updateFileDownloaded(QByteArray)));
    connect(request, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(updateProgressBar(qint64,qint64)));
}

void UpdateWidget::onCancelClicked()
{
    close();
}

void UpdateWidget::onSkipClicked()
{
    close();
}

void UpdateWidget::castFileDownloaded(QByteArray xData)
{
    ui->progressBar->setHidden(true);
    QDomDocument tDoc("xml");
    tDoc.setContent(xData);
    ui->titelLabel->setText("<b>"+tDoc.firstChildElement().firstChildElement().firstChildElement("title").text()+"</b>");
    ui->descriptionLabel->setText(tDoc.firstChildElement().firstChildElement().firstChildElement("description").text());

    mUpdateFileUrl = "http://alquds.googlecode.com/files/";
    mUpdateFileUrl += tDoc.firstChildElement().firstChildElement().firstChildElement("downloads").firstChildElement("file").firstChildElement("name").text().trimmed();
    if(!isUpdateAvailable(tDoc))
        close();
}

void UpdateWidget::updateFileDownloaded(QByteArray xData)
{
    QTemporaryFile file;
     if (file.open()) {
         file.write(xData);
         if(ZipZap::UnzipTo(&file, PathSettings::instance()->updateFilesPath().absolutePath()+"/"))
         {
             ui->updateButton->setHidden(true);
             ui->skipButton->setHidden(true);
             ui->laterButton->setHidden(true);
             ui->relaunchButton->setVisible(true);
             ui->successIcon->setVisible(true);
             return;
         }
     }
     close();
}

void UpdateWidget::updateProgressBar(qint64 bytesReceived, qint64 bytesTotal)
{
    ui->progressBar->setMaximum(bytesTotal);
    ui->progressBar->setValue(bytesReceived);
}
