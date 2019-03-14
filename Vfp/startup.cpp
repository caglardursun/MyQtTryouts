#include "startup.h"
#include "View/mainview.h"
#include "View/setuptab.h"
#include "Model/settings.h"
#include "utils.h"

namespace Ps {

    Startup::Startup(): QObject (nullptr),
        m_setupTab(*new SetupTab(nullptr)),
        m_mainView(*new MainView(nullptr,m_setupTab))
    {
        Settings m_Settings(this,"settings.json");
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
