#include "startup.h"
#include "View/mainwindow.h"
#include "Model/settings.h"
#include "Model/provider.h"
#include "utils.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>


namespace Miracle
{
    const QString dockRight("Right");
    const QString lockLeft("Left");
    static auto STYLE_PREFIX = QStringLiteral(":/styles");

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

    void Startup::loadStyles() const
    {

            //wrt. settings we will load the qss file

            QDir res_dir(STYLE_PREFIX);
            if(!res_dir.exists()){
                //ToDo Stop complaining and cut the process                
                abort();
            }
            //dark orrange qss
            QString fileName("darkorange.qss");
            QString path =res_dir.filePath(fileName);
            
            QFile res_file(path);
            if(res_file.open(QFile::ReadOnly))
            {
                QString StyleSheet = QLatin1String(res_file.readAll());
                m_MainWindow.setStyleSheet(StyleSheet);
            }           

    }
     

    void Startup::show() const
    {
        loadStyles();
        m_MainWindow.show();
    }
}



