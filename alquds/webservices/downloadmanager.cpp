#include "downloadmanager.h"
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>
#include <QDebug>

DownloadManager::DownloadManager()
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(OnDownloadFinished(QNetworkReply*)));
}

void DownloadManager::Download(QString url)
{
    //qDebug()<<"DownloadManager::doDownload "<<url;
    QNetworkReply *tReply = manager->get(QNetworkRequest(QUrl(url)));
    connect(tReply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));

    connect(tReply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
}

void DownloadManager::OnDownloadFinished(QNetworkReply *reply)
{
    //qDebug()<<"DownloadManager::OnDownloadFinished "<<reply->readAll();
    emit DownloadFinished(reply->readAll());
    reply->deleteLater();
}

void DownloadManager::slotError(QNetworkReply::NetworkError error)
{
    qDebug()<<"DownloadManager::slotError "<<error;
}
