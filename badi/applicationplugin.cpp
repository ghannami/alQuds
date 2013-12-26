#include "applicationplugin.h"
#include  <QtPlugin>

ApplicationPlugin::ApplicationPlugin()
{

}

Application* ApplicationPlugin::createApplication(int argc, char **argv)
{
    return new Application(argc, argv);
}

Q_EXPORT_PLUGIN2(pluginloaderlauncher, ApplicationPlugin);
