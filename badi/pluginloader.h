#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include <QObject>
#include <QPluginLoader>

class PluginLoader : public QPluginLoader
{
public:
    PluginLoader(QObject *parent = 0);
    void loadLauncher(QString fileName);
};

#endif // PLUGINLOADER_H
