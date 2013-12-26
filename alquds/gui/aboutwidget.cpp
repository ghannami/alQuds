#include "aboutwidget.h"
#include "ui_aboutwidget.h"

AboutWidget::AboutWidget(QWidget *parent) :
    WinWidget(parent),
    ui(new Ui::AboutWidget)
{
    ui->setupUi(this);
//
}

AboutWidget::~AboutWidget()
{
    delete ui;
}
