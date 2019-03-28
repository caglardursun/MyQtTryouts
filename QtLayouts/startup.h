#pragma once
#include <QObject>


namespace Miracle
{

    class MainWindow;
    class Startup final : public QObject
    {
        Q_OBJECT
        public:
            Startup();
            ~Startup();
            void show() const;
        private: 
            void loadStyles() const;
        private:
            MainWindow& m_MainWindow;
    };
}



