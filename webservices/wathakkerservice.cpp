#include "wathakkerservice.h"
#include "downloadmanager.h"
#include <QDebug>
#include "QTimer"

WathakkerService::WathakkerService()
{
    mBaseUrl = "http://www.wathakker.info";
}

void WathakkerService::requestRandomHadith(int mSec)
{
    if(mSec != 0)
    {
        mRondomHadithTimer = new QTimer(this);
        connect(mRondomHadithTimer, SIGNAL(timeout()), this, SLOT(requestRandomHadith()));
        mRondomHadithTimer->start(mSec);
    }
    requestRandomHadith();
}
void WathakkerService::requestRandomHadith()
{

    DownloadManager *request = new DownloadManager;
    request->Download(mBaseUrl+"/outdoor_strip_hadith.html");
    connect(request, SIGNAL(DownloadFinished(QByteArray)), this, SLOT(responseRandomHadith(QByteArray)));
}

void WathakkerService::responseRandomHadith(QByteArray xData)
{
    xData.remove(0, xData.indexOf("<table"));

//    qDebug()<<"WathakkerService::responseRandomHadith: "<<xData;
//    qDebug()<<"WathakkerService::responseRandomHadith: "<<xData.indexOf("<table");

    QDomDocument tDataDoc;
    tDataDoc.setContent(xData);
//    qDebug()<<"WathakkerService::responseRandomHadith: "<<tDataDoc.toString();

    QDomDocument tDoc("XML");

    QDomElement tRoot = tDoc.createElement("services");
    QDomElement tContent = tDoc.createElement("content");
    tRoot.appendChild(tContent);
    tDoc.appendChild(tRoot);

    tContent.appendChild(tDoc.createTextNode(tDataDoc.firstChildElement().firstChildElement("tr").nextSiblingElement("tr").text()));

    emit responseXML(tDoc);
//    qDebug()<<"WathakkerService::responseRandomHadith: "<<tDoc.toString();

}
