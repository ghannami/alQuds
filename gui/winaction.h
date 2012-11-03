#ifndef WINACTION_H
#define WINACTION_H

#include <QAction>
#include "winwidget.h"

class WinAction : public QAction
{
    Q_OBJECT
public:
    explicit WinAction(WinWidget *xWinWidget, QString xText, QIcon xIcon = QIcon());
    ~WinAction();

signals:
    void clicked(WinWidget* );
public slots:
    void OnClicked();
private:
    WinWidget *mWinWidget;
};

#endif // WINACTION_H
