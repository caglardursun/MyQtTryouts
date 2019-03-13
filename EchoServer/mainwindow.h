#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QTcpServer;
class QTcpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushStartButton_clicked();
    void on_pushStopButton_clicked();
private:
    Ui::MainWindow *ui;
    QTcpServer* m_server;
    QTcpSocket* m_socket;
    bool StartServer();
    void StopServer();
    void ExchangeData();
    void EchoReadData();
};

#endif // MAINWINDOW_H
