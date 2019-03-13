#include "setuptab.h"
#include "ui_setuptab.h"


SetupTab::SetupTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetupTab)
{
    ui->setupUi(this);    

}

SetupTab::~SetupTab()
{
    delete ui;
}
