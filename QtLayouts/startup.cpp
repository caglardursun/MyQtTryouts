#include "startup.h"
#include "View/mainwindow.h"
#include "Model/settings.h"
#include "Model/provider.h"
#include "utils.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QObject>
#include <QCoreApplication>
#include <QTranslator>

namespace Miracle
{
    const QString dockRight("Right");
    const QString dockLeft("Left");
    static auto STYLE_PREFIX = QStringLiteral(":/styles");

    Startup::Startup() : 
        QObject(nullptr),        
        m_MainWindow( *new MainWindow(nullptr) )
    {		
        
    }
    //Layout düzenlemeleri burada olacak ayarlara göre startup da 
    //stiller 
    //layout pozisyonları
    //ayarlanacak
    Startup::~Startup()
    {
        delete &m_MainWindow;
    }

    //parametrelerden okunacak şekilde düzenlenecek
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
    //nasıl olacak düşün ??? 
    void Startup::loadLanguages() const
    {
        QCoreApplication* app = QCoreApplication::instance();
        

        QTranslator translator;
        
        //get the language from settings ...
        bool bResult = translator.load("Turkish.qm");
        if(!bResult)
        {
           
        }
        else
        {
            app->installTranslator(&translator);
        }
    }
     

    void Startup::show() const
    {
        //Progress bar will be usefull 
        loadStyles();
        loadLanguages();
        //Progress bar will be usefull 
        
        m_MainWindow.show();
    }
}



