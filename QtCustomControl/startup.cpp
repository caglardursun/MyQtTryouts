#include "startup.h"


namespace Miracle{
    const QString dockRight("Left");

    Startup::Startup() : 
        QObject(nullptr),
        m_MainWindow( *new MainWindow(nullptr,
        *new QDockWidget(dockRight,nullptr) ) )
    {		
    }

    Startup::~Startup()
    {
        delete &m_MainWindow;
    }

    void Startup::show() const
    {
        m_MainWindow.show();
    }
}



