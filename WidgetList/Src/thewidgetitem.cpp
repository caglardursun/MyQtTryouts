#include "thewidgetitem.h"
#include "ui_thewidgetitem.h"

#include <QStyleOption>
#include <QPainter>


thewidgetitem::thewidgetitem(QWidget *parent) :
    QWidget(parent),
    
    ui(new Ui::thewidgetitem)
{
    ui->setupUi(this);    
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

thewidgetitem::~thewidgetitem()
{
    delete ui;
}

void thewidgetitem::SetColor(QColor& color)
{    
    ui->widget->setColor(color);
}


