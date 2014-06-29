#include "athantraywidget.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include "athanmanager.h"
#include <QPushButton>
#include "athansettings.h"
#include <QStyleOption>
#include <QPainter>
#include <QStyle>

AthanTrayWidget::AthanTrayWidget(QWidget *parent) :
    QWidget(parent)
{
    Qt::WindowFlags wFlags;
#ifdef Q_OS_WIN
    wFlags = Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool;
#else
    wFlags = Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint;
#endif

    setWindowFlags(wFlags);
    setFixedSize(250,80);
    QDesktopWidget * desktop = QApplication::desktop();
    QRect screen = desktop->availableGeometry(this);
    move(screen.bottomRight().x() - width() - 2, screen.bottomRight().y() - height()-2);

    m_textLabel = new QLabel("until next prayer",this);
    m_timeLabel = new QLabel("00:00", this);
    m_playButton = new QPushButton(this);
    m_playButton->setIconSize(QSize(24,24));
    m_playButton->setIcon(QIcon(":/icons/32/speaker-mute.png"));
    m_playButton->setMaximumSize(32,32);
    m_playButton->setCheckable(true);
    m_playButton->setObjectName("AthanTrayWidget_playButton");

    QHBoxLayout *mLay = new QHBoxLayout;
    mLay->addWidget(m_playButton);
    mLay->addWidget(m_textLabel);
    mLay->addWidget(m_timeLabel);

    setLayout(mLay);
    connect(m_playButton, SIGNAL(toggled(bool)), this, SLOT(onPlayClicked(bool)));
    connect(AthanSettings::instance(), SIGNAL(silentModeChanged(bool)), this, SLOT(onPlayClicked(bool)));

    setAutoFillBackground(true);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

void AthanTrayWidget::itsAthanTime(PrayerTimes::TimeID timeID)
{
    QString sText;
    sText += tr("calling for");
    sText +=" ";
    sText += AthanManager::prayerTimeByName(timeID);
    m_textLabel->setText(sText);
    m_timeLabel->clear();
}

void AthanTrayWidget::itsBeforAthan(PrayerTimes::TimeID id, QTime time)
{
    QString sText;
    sText += tr("until");
    sText +=" ";
    sText += AthanManager::prayerTimeByName(id);
    m_textLabel->setText(sText);
    m_timeLabel->setText(time.toString());
}

void AthanTrayWidget::onPlayClicked(bool v)
{
    if(AthanSettings::instance()->silentMode() != v)
        AthanSettings::instance()->setSilentMode(v);
    if(m_playButton->isChecked() != v)
        m_playButton->setChecked(v);
}

void AthanTrayWidget::paintEvent(QPaintEvent *)
 {
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }
