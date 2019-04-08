#include "mainviewer.h"
#include "ui_mainviewer.h"

MainViewer::MainViewer(QWidget *parent, QString& filePath) :
    QWidget(parent),
    ui(new Ui::MainViewer),
    m_filePath(filePath)
{
    ui->setupUi(this);        
}

MainViewer::~MainViewer()
{
    delete ui;
}
