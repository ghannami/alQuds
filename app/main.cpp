#include <qtsingleapplication.h>
#include "app.h"

int main(int argc, char **argv)
{
    QtSingleApplication instance(argc, argv);
    if (instance.sendMessage("Wake up!"))
        return 0;
    App app;
    app.laodApplication();
    QObject::connect(&instance, SIGNAL(messageReceived(const QString&)),
                     &app, SLOT(activeApplication()));
    return instance.exec();
}
