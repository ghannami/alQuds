#ifndef PATHSETTINGS_H
#define PATHSETTINGS_H
#include <QObject>
#include <QDir>

class QSettings;

class PathSettings : public QObject
{
private:
    PathSettings();

public:
    static PathSettings *instance();
    QDir pluginsPath();
    QDir audioPath();
    QDir installationRootPath();
    QDir updateFilesPath();

private:
    static PathSettings *mInstance;
    QSettings *mSettings;
};

#endif // PATHSETTINGS_H
