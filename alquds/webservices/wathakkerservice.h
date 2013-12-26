#ifndef WATHAKKERSERVICE_H
#define WATHAKKERSERVICE_H
#include <QObject>
#include <QString>
#include <QByteArray>
#include <QDomDocument>

class QTimer;

class WathakkerService : public QObject
{
    Q_OBJECT

public:
    WathakkerService();
    void requestRandomHadith(int mSec); //<! /brief int mSec the time on millisecond

public slots:
    void responseRandomHadith(QByteArray xData);
    void requestRandomHadith();

signals:
    void responseXML(QDomDocument);
private:
    QString mBaseUrl;
//    http://www.wathakker.info/outdoor_strip_hadith.html
    QTimer *mRondomHadithTimer;
};

#endif // WATHAKKERSERVICE_H
