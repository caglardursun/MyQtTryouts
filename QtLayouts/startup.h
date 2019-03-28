#pragma once
#include <QObject>


namespace Miracle
{

    class MainWindow;
    class QApplication;

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
    };
}



