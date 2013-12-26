#include "webparser.h"
#include "downloadmanager.h"
#include <QDebug>

WebParser::WebParser(QObject *parent)
    :QObject(parent)
{
    DownloadManager *request = new DownloadManager;
    request->Download("http://ar.islamway.com/collection/213");
    connect(request, SIGNAL(DownloadFinished(QByteArray)), this, SLOT(fileDownloaded(QByteArray)));
}

void WebParser::fileDownloaded(QByteArray xData)
{
    qDebug()<<"WebParser::fileDownloaded "<<xData;
}
