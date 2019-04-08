#include "mainviewer.h"
#include "ui_mainviewer.h"

MainViewer::MainViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainViewer)
{
    ui->setupUi(this);
}

MainViewer::~MainViewer()
{
    delete ui;
}
