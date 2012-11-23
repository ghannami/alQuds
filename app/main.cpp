#include <QtGui>
#include <QPluginLoader>
#include "../badi/launcher.h"

//! [0]
int main(int argv, char *args[])
{
    QApplication app(argv, args);

    QPluginLoader pluginLoader;
#ifdef Q_WS_WIN
    pluginLoader.setFileName("badi.dll");
#elif Q_WS_MAC
    pluginLoader.setFileName("libbadi.dylib");
#endif

    if(!pluginLoader.load())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("Error");
        msg->setText(pluginLoader.errorString());
        msg->exec();
        exit(0);
    }
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
        Launcher *launcher = qobject_cast<Launcher *>(plugin);
        if (launcher)
        {
            launcher->launch();
        }
    }
    return app.exec();
}
//! [0]
