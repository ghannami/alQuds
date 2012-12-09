#ifndef UPDATEWIDGET_H
#define UPDATEWIDGET_H

#include <QWidget>
#include <QDomDocument>

class WakibLauncher;
class QTemporaryFile;

namespace Ui {
class UpdateWidget;
}

class UpdateWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit UpdateWidget(WakibLauncher *launcher);
    ~UpdateWidget();
    bool isUpdateAvailable(QDomDocument xDoc);

protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void onUpdateClicked();
    void onCancelClicked();
    void onSkipClicked();
    void castFileDownloaded(QByteArray xData);
    void updateFileDownloaded(QByteArray xData);
    void updateProgressBar(qint64 bytesReceived, qint64 bytesTotal);

private:
    Ui::UpdateWidget *ui;
    QString mCastUrl;
    QString mUpdateFileUrl;
    WakibLauncher *mLauncher;
};

#endif // UPDATEWIDGET_H
