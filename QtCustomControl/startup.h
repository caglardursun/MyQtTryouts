#ifndef STARTUP_H
#define STARTUP_H
#include <QObject>
#include <QWidget>
#include <View/mainwindow.h>
#include <QDockWidget>

namespace Miracle{
    
    class Startup final : public QObject
    {
        Q_OBJECT
        public:
            Startup();
            ~Startup();
            void show() const;

        private:
            MainWindow& m_MainWindow;
    };
}
#endif // STARTUP_H


