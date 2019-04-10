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
                void createViewMenu();
                void createLanguageMenu();            
                void createDock();        
                            
            protected:            
                void changeEvent(QEvent*);
                QTabWidget *tabWidget;

            protected slots:            
                void slotLanguageChanged(QAction* action);   
                void slotViewChanged(QAction* action);         
            private slots:            
                void on_actionClose_triggered();            
                void on_action_New_triggered();
                void slotCloseTab(int index);                
    };

