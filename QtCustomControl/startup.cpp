#include "startup.h"


namespace Miracle{

    Startup::Startup() : 
        QObject(nullptr),
        m_MainWindow(*new MainWindow(nullptr))
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



