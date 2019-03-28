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
        explicit MainWindow(QWidget *parent);
        ~MainWindow();        
       
    private:
        Ui::MainWindow *ui;
    };
}
