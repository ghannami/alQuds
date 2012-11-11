#ifndef UPDATEWIDGET_H
#define UPDATEWIDGET_H

#include <QWidget>

class WakibLauncher;

namespace Ui {
class UpdateWidget;
}

class UpdateWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit UpdateWidget(WakibLauncher *launcher);
    ~UpdateWidget();
    
public slots:
    void onUpdateClicked();
    void onCancelClicked();
    void onSkipClicked();
    void castFileDownloaded(QByteArray xData);
    void updateFileDownloaded(QByteArray xData);
    void launchProgramm();
    void updateProgressBar(qint64 bytesReceived, qint64 bytesTotal);
private:
    Ui::UpdateWidget *ui;
    QString mCastUrl;
    QString mUpdateFileUrl;
    WakibLauncher *mLauncher;
};

#endif // UPDATEWIDGET_H
