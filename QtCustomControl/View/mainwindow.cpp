#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Miracle
{

    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        m_dock(*new QDockWidget(tr("Test Docking"),this))        
    {
        ui->setupUi(this);
        m_dock.setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);   
        QListWidget& listWidget(*new QListWidget(&m_dock));        
        
        //Allow left right and bottom
        m_dock.setWidget(&listWidget);
        addDockWidget(Qt::RightDockWidgetArea, &m_dock);
    }

    MainWindow::~MainWindow()
    {        
        
        delete ui;
    }

}

