#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QKeyEvent>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    private:
        QGraphicsScene* m_scene;        

    private:
        Ui::MainWindow* ui;
    private slots:
        void onFileLoadPushClicked();

};

#endif // MAINWINDOW_H
