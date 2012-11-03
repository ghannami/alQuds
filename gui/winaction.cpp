#include "winaction.h"

WinAction::WinAction(WinWidget *xWinWidget, QString xText, QIcon xIcon) :
    QAction(xIcon, xText, xWinWidget), mWinWidget(xWinWidget)
{
    connect(this, SIGNAL(triggered()), this , SLOT(OnClicked()));
}

WinAction::~WinAction()
{

}

void WinAction::OnClicked()
{
    emit clicked(mWinWidget);
}
