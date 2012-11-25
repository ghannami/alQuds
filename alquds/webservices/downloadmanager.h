#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

class DownloadManager: public QObject
{
    Q_OBJECT

public:
    DownloadManager();
    void Download(QString url);

public slots:
    void OnDownloadFinished(QNetworkReply *reply);

signals:
    void DownloadFinished(QByteArray);
    void downloadProgress(qint64,qint64);
private:
    QNetworkAccessManager * manager;

};

#endif // DOWNLOADMANAGER_H
