#ifndef ATHANEDITOR_H
#define ATHANEDITOR_H

#include "winwidget.h"

namespace Ui {
class AthanEditor;
}
class AthanPlayer;

class AthanEditor : public WinWidget
{
    Q_OBJECT
    
public:
    explicit AthanEditor(QWidget *parent = 0);
    ~AthanEditor();

public slots:
    void readSettings();
    void saveSettings();
    void initAthanFiles();
    void onFieldsChanged();

    void selectIshaFile(int xIndex);
    void selectMaghribFile(int xIndex);
    void selectAsrFile(int xIndex);
    void selectDhurFile(int xIndex);
    void selectFajrFile(int xIndex);

    void onSilentModeChanged(bool);

    void playFajrAthan();
    void playDhurAthan();
    void playAsrAthan();
    void playMaghribAthan();
    void playIshaAthan();


private:
    Ui::AthanEditor *ui;
    AthanPlayer *mPlayer;

    QString mFajrFile;
    QString mDuhrFile;
    QString mAsrFile;
    QString mMaghribFile;
    QString mIshaFile;
};

#endif // ATHANEDITOR_H
