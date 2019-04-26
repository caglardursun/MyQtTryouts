#pragma once

#include <QWidget>
#include <QScrollBar>

#include "miracleviewer.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_imageButton_clicked();
        void AdjustScrollBar(QScrollBar* scroolBar, double factor);

    private:
        Ui::MainWindow *ui;
};


