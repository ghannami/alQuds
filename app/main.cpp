#include <qtsingleapplication.h>
#include "app.h"

class Application : public QtSingleApplication
{
public:

    Application(int argc, char **argv)
        :QtSingleApplication(argc,argv)
    {
        myApp = new App();
        myApp->laodApplication();
        QObject::connect(this, SIGNAL(messageReceived(const QString&)),
                         myApp, SLOT(activeApplication()));
    }

    bool event(QEvent *event)
    {
        switch (event->type()) {
        case QEvent::ApplicationActivate:
            myApp->activeApplication();
        default:
            return QtSingleApplication::event(event);
        }
    }

private:
    App *myApp;
};

int main(int argc, char **argv)
{
    Application instance(argc, argv);
    if (instance.sendMessage("Wake up!"))
        return 0;
    return instance.exec();
}
//int main(int argc, char **argv)
//{
//    QtSingleApplication instance(argc, argv);
//    if (instance.sendMessage("Wake up!"))
//        return 0;
//    App app;
//    app.laodApplication();
//    QObject::connect(&instance, SIGNAL(messageReceived(const QString&)),
//                     &app, SLOT(activeApplication()));
//    return instance.exec();
//}
