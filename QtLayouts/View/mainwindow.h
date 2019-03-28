#pragma once

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
        explicit MainWindow(QWidget *parent,QDockWidget& dockWidget);
        ~MainWindow();        
       QDockWidget& m_dock;
    private:
        Ui::MainWindow *ui;
    };
}
