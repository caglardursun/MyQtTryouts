#pragma once

#include <QMainWindow>
#include <QtWidgets>
#include <QTranslator>
#include "Model/provider.h"
#include "Model/settings.h"
#include "View/basewindow.h"

using namespace Miracle;

namespace Ui 
{
    class MainWindow;
}


class MainWindow : public QMainWindow, public BaseWindow
    {
        Q_OBJECT


        public:
            explicit MainWindow(QWidget *parent);
            ~MainWindow();            
        private:
            Ui::MainWindow *ui;
            void Init();
            void createLanguageMenu();            
            void createDock();        
        private:
            QDockWidget* dock;    
            QDockWidget* dock2;

            QListWidget* listWidget;
            QListWidget* listWidget2;

        protected:            
            void changeEvent(QEvent*);
            // Settings& m_Settings;

        protected slots:            
            void slotLanguageChanged(QAction* action);            
        private slots:            
            void on_actionClose_triggered();
};

