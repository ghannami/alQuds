#ifndef ATHANEDITOR_H
#define ATHANEDITOR_H

#include <QWidget>

namespace Ui {
class AthanEditor;
}
class AthanPlayer;

class AthanEditor : public QWidget
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
