#pragma once
#include <QObject>
#include <QApplication>
#include "View/mainwindow.h"
namespace Miracle
{


    class MainViewManager;
    class Startup final : public QObject
    {
        Q_OBJECT
        public:
            Startup();
            ~Startup();
            void show() const;
        private: 
            void loadStyles() const;
            void loadLanguages() const;            
        private:
            MainWindow& m_MainWindow;
            MainViewManager* m_mainViewManager;            
    };
}



