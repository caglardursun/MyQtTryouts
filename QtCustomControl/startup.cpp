#include "startup.h"


namespace Miracle{

    Startup::Startup() : 
        QObject(nullptr),
        m_MainWindow(*new MainWindow(nullptr))
    {
		QString str("adsdsaasd %1");
		str.arg("dsadsadasadsdsa");
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



