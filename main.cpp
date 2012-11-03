#include <QApplication>
#include <QTextCodec>
#include "./gui/mainwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));

    QApplication a(argc, argv);
    a.setApplicationName("Al Quds");
    a.setApplicationVersion("2.01");
    a.setOrganizationName("Ghannami");
    MainWindow m;
    m.show();
    return a.exec();
}
