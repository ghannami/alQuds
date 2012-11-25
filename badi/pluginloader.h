#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include <QObject>
#include <QPluginLoader>

class Launcher;
class PluginLoader : public QPluginLoader
{
    Q_OBJECT

public:
    PluginLoader(QObject *parent = 0);
    void loadLauncher(QString fileName);

public slots:
    void activateWindow();
    void relaunchAll();

private:
    Launcher *mAlquds;

};

#endif // PLUGINLOADER_H
