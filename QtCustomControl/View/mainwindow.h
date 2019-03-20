#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

namespace Ui 
{
    class MainWindow;
}

namespace Miracle
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        //& m_listWidget;
        //QListWidget& m_rightList;
        QDockWidget& m_dock;
    private:
        Ui::MainWindow *ui;
    };
}

#endif // MAINWINDOW_H
