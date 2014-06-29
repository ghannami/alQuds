#ifndef ATHANTRAYWIDGET_H
#define ATHANTRAYWIDGET_H

#include <QWidget>
#include "prayertimes.hpp"

class QLabel;
class QPushButton;

class AthanTrayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AthanTrayWidget(QWidget *parent = 0);
    void itsAthanTime(PrayerTimes::TimeID timeID);
    void itsBeforAthan(PrayerTimes::TimeID id, QTime time);
    virtual void paintEvent(QPaintEvent *);

signals:

public slots:
    void onPlayClicked(bool v);

private:
    QLabel *m_textLabel;
    QLabel *m_timeLabel;
    QPushButton *m_playButton;

};

#endif // ATHANTRAYWIDGET_H
