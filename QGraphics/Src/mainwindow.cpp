#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton , SIGNAL (clicked()), this, SLOT (onFileLoadPushClicked()));
    // m_scene = new QGraphicsScene();
    // ui->graphicsView->setScene(m_scene);

    
}
MainWindow::~MainWindow()
{
    delete ui;
    
}

void MainWindow::onFileLoadPushClicked()
{
    QString p = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.jpeg *.jpg *.tif)"));

    //QImage image(p);

    ui->graphicsView->Load(p);
    
    // QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));    
    // item->setFlag(QGraphicsItem::ItemIsMovable);
    // m_scene->addItem(item);
    // ui->graphicsView->show();
}
