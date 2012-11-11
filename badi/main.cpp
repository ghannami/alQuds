#include <QtGui>
#include "pluginloader.h"

//! [0]
int main(int argv, char *args[])
{
    QApplication app(argv, args);

    PluginLoader pluginLoader;

    return app.exec();
}
//! [0]

