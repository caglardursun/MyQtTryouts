#include "mainwindow.h"
#include "ui_mainwindow.h"

Miracle::MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Miracle::MainWindow::~MainWindow()
{
    delete ui;
}
