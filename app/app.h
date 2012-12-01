#ifndef APP_H
#define APP_H

#include <QObject>
class Launcher;
class QPluginLoader;
class QTemporaryFile;

class App : public QObject
{
    Q_OBJECT
private:
    explicit App(QObject *parent = 0);

public:
    static App* instance();
    void laodApplication();
    void installUpdateFiles(QTemporaryFile *file);

public slots:
    void activeApplication();

private:
    Launcher *mLauncher;
    static App *mInstance;
    QPluginLoader *mPluginLoader;
};

#endif // APP_H
