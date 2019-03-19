#include "startup.h"
#include "View/mainview.h"
#include "View/setuptab.h"
#include "Model/settings.h"
#include "utils.h"
#include <QFile>
#include <QDir>

namespace Ps {

    static auto STYLE_PREFIX = QStringLiteral(":/styles");

    Startup::Startup(): QObject (nullptr),
        m_setupTab(*new SetupTab(nullptr)),
        m_mainView(*new MainView(nullptr,m_setupTab))
    {
        Settings m_Settings(this,"settings.json");
        m_Settings.ParseJsonData();
        
        //ApplyStyles();
       
    }

    void Startup::loadStyles() const
    {

            QDir res_dir(STYLE_PREFIX);
            if(!res_dir.exists()){
                //ToDo Stop complaining and cut the process                
                abort();
            }
            //dark orrange qss
            QString fileName("darkorange.qss");
            QString path =res_dir.filePath(fileName);
            Utils::Message(fileName);
            Utils::Message(path);

            QFile res_file(path);
            if(res_file.open(QFile::ReadOnly))
            {
                QString StyleSheet = QLatin1String(res_file.readAll());
                m_mainView.setStyleSheet(StyleSheet);
            }           
    }

    Startup::~Startup()
    {
        Utils::DestructorMsg(this);
        delete  &m_mainView;
    }

    void Startup::show() const {
        loadStyles();
        m_mainView.show();
        
    }
}
