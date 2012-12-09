#include "../badi/application.h"
#include "../badi/applicationplugin.h"
#include "../badi/pluginloader.h"


int main(int argc, char **argv)
{
    QtSingleApplication *app = new QtSingleApplication(argc, argv);
    PluginLoader pluginLoader;
    QObject *plugin = pluginLoader.loadLauncher("badi");
    if(plugin)
    {
        ApplicationPlugin *appPlugin = dynamic_cast<ApplicationPlugin *>(plugin);
        app->closeAllWindows();
        delete app;
        app = appPlugin->createApplication(argc, argv);
        if(app)
        {
            if (app->sendMessage("Wake up!"))
                return 0;
            return app->exec();
        }
    }
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
