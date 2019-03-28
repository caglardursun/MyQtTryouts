#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Miracle
{

    MainWindow::MainWindow(QWidget *parent, QDockWidget& dockWidget) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        m_dock(dockWidget)        
    {
        ui->setupUi(this);
           
        m_dock.setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);   
        QListWidget& listWidget(*new QListWidget(&m_dock));        
        
        listWidget.addItems(QStringList()
            << "L1"
            << "L2"
            << "L3"
            << "L4"
            << "L5"
            << "L6");
        //Allow left right and bottom
        m_dock.setWidget(&listWidget);


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

        addDockWidget(Qt::RightDockWidgetArea, dock2);
        addDockWidget(Qt::LeftDockWidgetArea, &m_dock);        
    }

    MainWindow::~MainWindow()
    {        
        
        delete ui;
    }

}

