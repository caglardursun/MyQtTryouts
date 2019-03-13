#include "startup.h"
#include "View/mainview.h"
#include "View/setuptab.h"
#include "utils.h"

namespace Ps {

    Startup::Startup(): QObject (nullptr),
        m_setupTab(*new SetupTab(nullptr)),
        m_mainView(*new MainView(nullptr,m_setupTab))
    {
    }
    Startup::~Startup()
    {
        Utils::DestructorMsg(this);
        delete  &m_mainView;
    }

    void Startup::show() const {
        m_mainView.show();
    }
}
