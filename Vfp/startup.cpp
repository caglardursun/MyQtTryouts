#include "startup.h"
#include "View/mainview.h"
#include "View/setuptab.h"
#include "Model/settings.h"
#include "utils.h"
#include <QFile>

namespace Ps {

    static auto STYLE_PREFIX = QStringLiteral(":/style");

    Startup::Startup(): QObject (nullptr),
        m_setupTab(*new SetupTab(nullptr)),
        m_mainView(*new MainView(nullptr,m_setupTab))
    {
        Settings m_Settings(this,"settings.json");
        m_Settings.ParseJsonData();
        
        //ApplyStyles();
        QFile File(":/styles/darkorange.qss");
        if(File.open(QFile::ReadOnly))
        {
            QString StyleSheet = QLatin1String(File.readAll());
            m_mainView.setStyleSheet(StyleSheet);
        }
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
