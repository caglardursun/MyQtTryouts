#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include "thewidgetitem.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_colorList(new QList<QColor>()),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_colorList;
}

void MainWindow::on_pushClickButton_clicked()
{
    GenerateColors();

    // QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    // ui->listWidget->addItem (listWidgetItem);
    // thewidgetitem *theWidgetItem = new thewidgetitem;
    // QColor color(255,0,125);
    // theWidgetItem->SetColor(color);
    // //Making sure that the listWidgetItem has the same size as the TheWidgetItem
    // listWidgetItem->setSizeHint (theWidgetItem->sizeHint());
    // //Finally adding the itemWidget to the list
    // ui->listWidget->setItemWidget(listWidgetItem, theWidgetItem);

    for(int i=0;i <m_colorList->count();i++)
    {
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem (listWidgetItem);
        thewidgetitem *theWidgetItem = new thewidgetitem;
        QColor color = m_colorList->at(i);
        theWidgetItem->SetColor(color);
        //Making sure that the listWidgetItem has the same size as the TheWidgetItem
        listWidgetItem->setSizeHint (theWidgetItem->sizeHint());
        //Finally adding the itemWidget to the list
        ui->listWidget->setItemWidget(listWidgetItem, theWidgetItem);
    }

}



void MainWindow::GenerateColors()
{
    //Random generate the colors
    for(int i=0;i <155;i++)
    {
        int r = 64 * i % 255;
        int g = 128 + i %255 ;
        int b = 0 + i % 255;

        m_colorList->append(QColor::fromRgb(r,g,b));
    }
}