#ifndef GENERALSETTINGS_H
#define GENERALSETTINGS_H

class QSettings;

class GeneralSettings
{
private:
    GeneralSettings();

public:
    ~GeneralSettings();
    static GeneralSettings *instance();

    bool startWithSystem();
    void setStartWithSystem(bool v);
private:
    static GeneralSettings *mInstance;
    QSettings *mSettings;

};

#endif // GENERALSETTINGS_H
