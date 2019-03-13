#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>

static const int PORT_NUMBER = 23;
static const int WAIT_FOR_DATA_MS = 200;//ms

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_server(new QTcpServer(this)),
    m_socket(nullptr)
{
    ui->setupUi(this);
    ui->pushStopButton->setEnabled(false);
    connect(m_server,&QTcpServer::newConnection, this,&MainWindow::ExchangeData);	
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushStartButton_clicked()
{
    if(StartServer())
    {
        ui->pushStartButton->setEnabled(false);
        ui->pushStopButton->setEnabled(true);
    }

}

void MainWindow::on_pushStopButton_clicked()
{
    StopServer();
    ui->pushStartButton->setEnabled(true);
    ui->pushStopButton->setEnabled(false);
}

bool MainWindow::StartServer()
{
    bool result = m_server->listen(QHostAddress::Any, PORT_NUMBER);

    if(!result){
        QMessageBox::critical(this,tr("Echo Server"),tr("Unable to start server %1")
                              .arg(m_server->errorString()));
        return false;
    }
    return  true;
}

void MainWindow::StopServer()
{
    m_server->close();
    if(m_socket != nullptr && m_socket->isOpen())
    {
        m_socket->close();
    }
}

void MainWindow::ExchangeData()
{
    m_socket = m_server->nextPendingConnection();
    if(m_socket->isOpen())
    {
        connect(m_socket, &QTcpSocket::readyRead, this, &MainWindow::EchoReadData);
    }
}

void MainWindow::EchoReadData()
{
    m_socket->write("<echoserver>\n");
    QString result;
    while(!m_socket->atEnd())
    {
        result.append(m_socket->readAll());
        m_socket->waitForReadyRead(WAIT_FOR_DATA_MS);
    }
    m_socket->write(qPrintable(result));
    m_socket->write("\n</echoserver>");
}


