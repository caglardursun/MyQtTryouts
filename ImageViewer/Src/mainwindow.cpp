#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QWidget>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)    
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AdjustScrollBar(QScrollBar* scroolBar, double factor)
{
    //Zoom in/out burada tetiklenecek
    //scroolBar->setValue(int( ui->imageLabel->GetScaleFactor() * scroolBar->value() + ( (factor - 1) * scroolBar->pageStep() /2 ) ));
}

void MainWindow::on_imageButton_clicked()
{
    QFileDialog fd;
    fd.setNameFilter(tr("Images (*.png *.tif *.jpg)"));
    fd.setViewMode(QFileDialog::Detail);
    QString file;
    fd.show();
    if(fd.exec())
        file = fd.selectedFiles().first();
    
    ui->imageLabel->Load(file);
}
