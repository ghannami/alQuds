#ifndef WEBPARSER_H
#define WEBPARSER_H
#include <QObject>

class WebParser : public QObject
{
    Q_OBJECT

public:
    WebParser(QObject *parent = 0);

public slots:
    void fileDownloaded(QByteArray xData);
private:

};

#endif // WEBPARSER_H
