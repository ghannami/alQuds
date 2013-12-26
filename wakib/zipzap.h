#ifndef ZIPZAP_H
#define ZIPZAP_H
#include <QString>

class QFile;

class ZipZap
{
public:
    ZipZap();
    static bool UnzipTo(const QString zipfile, const QString outputdir);
    static bool UnzipTo(QFile *zipfile, const QString outputdir);
};

#endif // ZIPZAP_H
