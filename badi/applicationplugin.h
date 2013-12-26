#ifndef APPLICATIONPLUGIN_H
#define APPLICATIONPLUGIN_H
#include "application.h"

class ApplicationPlugin : public QObject
{
public:
    ApplicationPlugin();
    Application *createApplication(int argc, char **argv);

};

#endif // APPLICATIONPLUGIN_H
