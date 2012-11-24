#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include <QObject>
#include <QPluginLoader>

class Launcher;
class PluginLoader : public QPluginLoader
{
public:
    PluginLoader(QObject *parent = 0);
    void loadLauncher(QString fileName);
    void activateWindow();

private:
    Launcher *mAlquds;

};

#endif // PLUGINLOADER_H
