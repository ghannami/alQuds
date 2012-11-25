#include "zipzap.h"
#include <QtGui>
#include <quazip/quazip.h>
#include <quazip/quazipfile.h>

ZipZap::ZipZap()
{
}

bool  ZipZap::UnzipTo( const QString zipfile, const QString outputdir )
{
    ///////////// const QString cartella = QDir::currentPath();
     /////////qDebug() << "### from unzzip function path " <<  QDir::currentPath();
   /////////// qDebug() << "### outputdir " <<  outputdir;
    //////////qDebug() << "### zipfile " <<  zipfile;
    char* suk;
    QuaZip zip(zipfile);
    bool extractsuccess = false;
    zip.open(QuaZip::mdUnzip);
    QuaZipFile file(&zip);
       for(bool more=zip.goToFirstFile(); more; more=zip.goToNextFile()) {
           file.open(QIODevice::ReadOnly);
           QString name = zip.getCurrentFileName();
                   name.prepend(outputdir);   /* extract to path ....... */
           QFile meminfo(name);
           QFileInfo infofile(meminfo);
           QDir dira(infofile.absolutePath());
           if ( dira.mkpath(infofile.absolutePath()) ) {
           /* dir is exist*/
           /////////qDebug() << "### name  " << name;
           /////qDebug() << "### namedir yes  " << infofile.absolutePath();

               QString fileqinfo = zip.getCurrentFileName();
                QByteArray fe = fileqinfo.toAscii();
                suk = fe.data();

                //qDebug() <<  "Processing..... " << suk << "\n";

               if ( meminfo.open(QIODevice::ReadWrite) ) {
               meminfo.write(file.readAll());   /* write */
               meminfo.close();
               extractsuccess = true;
               //////////RegisterImage(name);
               }
           } else {
             file.close();
             return false;
           }
           file.close(); // do not forget to close!
        }
    zip.close();

return extractsuccess;
}

bool  ZipZap::UnzipTo(QFile *zipfile, const QString outputdir )
{
    ///////////// const QString cartella = QDir::currentPath();
     /////////qDebug() << "### from unzzip function path " <<  QDir::currentPath();
   /////////// qDebug() << "### outputdir " <<  outputdir;
    //////////qDebug() << "### zipfile " <<  zipfile;
    char* suk;
    QuaZip zip(zipfile);
    bool extractsuccess = false;
    zip.open(QuaZip::mdUnzip);
    QuaZipFile file(&zip);
       for(bool more=zip.goToFirstFile(); more; more=zip.goToNextFile()) {
           file.open(QIODevice::ReadOnly);
           QString name = zip.getCurrentFileName();
                   name.prepend(outputdir);   /* extract to path ....... */
           QFile meminfo(name);
           QFileInfo infofile(meminfo);
           QDir dira(infofile.absolutePath());

//           qDebug()<<"name: "<<name<<" outputdir: "<<outputdir<<" infofile.absolutePath(): "<<infofile.absolutePath();
           if ( dira.mkpath(infofile.absolutePath()) ) {
           /* dir is exist*/
           /////////qDebug() << "### name  " << name;
//           /////qDebug() << "### namedir yes  " << infofile.absolutePath();

               QString fileqinfo = zip.getCurrentFileName();
                QByteArray fe = fileqinfo.toAscii();
                suk = fe.data();

                //qDebug() <<  "Processing..... " << suk << "\n";

               if ( meminfo.open(QIODevice::ReadWrite) ) {
               meminfo.write(file.readAll());   /* write */
               meminfo.close();
               extractsuccess = true;
               //////////RegisterImage(name);
               }
           } else {
             file.close();
             return false;
           }
           file.close(); // do not forget to close!
        }
    zip.close();

return extractsuccess;
}

//void ZipZap::UnzipTo(const QString zipfile, const QString outputdir)
