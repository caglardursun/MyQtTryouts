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
            << "A1"
            << "A2"
            << "A3"
            << "A4"
            << "A5"
            << "A6");
        //Allow left right and bottom
        m_dock.setWidget(&listWidget);


            auto dock2 = new QDockWidget(tr("Paragraphs"), this);
            auto list2 = new QListWidget(dock2);
            list2->addItems(QStringList()
            << "Thank you for your payment which we have received today."
            << "Your order has been dispatched and should be with you "
               "within 28 days."
            << "We have dispatched those items that were in stock. The "
               "rest of your order will be dispatched once all the "
               "remaining items have arrived at our warehouse. No "
               "additional shipping charges will be made."
            << "You made a small overpayment (less than $5) which we "
               "will keep on account for you, or return at your request."
            << "You made a small underpayment (less than $1), but we have "
               "sent your order anyway. We'll add this underpayment to "
               "your next bill."
            << "Unfortunately you did not send enough money. Please remit "
               "an additional $. Your order will be dispatched as soon as "
               "the complete amount has been received."
            << "You made an overpayment (more than $5). Do you wish to "
               "buy more items, or should we return the excess to you?");
            dock2->setWidget(list2);
            addDockWidget(Qt::RightDockWidgetArea, dock2);
        
        addDockWidget(Qt::RightDockWidgetArea, &m_dock);
    }

    MainWindow::~MainWindow()
    {        
        
        delete ui;
    }

}

