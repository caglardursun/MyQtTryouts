#pragma once

#include <QMainWindow>
#include <QtWidgets>
#include <QTranslator>
#include <QTabBar>
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
            QDockWidget* m_dock;    
            QDockWidget* m_dock2;
            //QDockWidget* m_mainDock;

            QListWidget* m_listWidget;
            QListWidget* m_listWidget2;                        

        protected:            
            void changeEvent(QEvent*);
            QTabWidget *tabWidget;

        protected slots:            
            void slotLanguageChanged(QAction* action);            
        private slots:            
            void on_actionClose_triggered();
};

