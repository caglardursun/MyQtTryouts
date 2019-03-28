#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Miracle
{

    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)               
    {
        ui->setupUi(this);


        auto dock = new QDockWidget(tr("Left"), this);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea); 
          
        QListWidget& listWidget(*new QListWidget(dock));        
        
        listWidget.addItems(QStringList()
            << "L1"
            << "L2"
            << "L3"
            << "L4"
            << "L5"
            << "L6");
        //Allow left right and bottom
        dock->setWidget(&listWidget);


        auto dock2 = new QDockWidget(tr("Right"), this);
        auto list2 = new QListWidget(dock2);
        list2->addItems(QStringList()
            << "R1"
            << "R2"
            << "R3"
            << "R4"
            << "R5"
            );
        dock2->setWidget(list2);

        addDockWidget(Qt::LeftDockWidgetArea, dock);        
        addDockWidget(Qt::RightDockWidgetArea, dock2);
        
    }

    MainWindow::~MainWindow()
    {        
        
        delete ui;
    }

}

