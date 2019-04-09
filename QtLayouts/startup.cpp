#include "startup.h"
#include "View/mainwindow.h"
#include "Model/settings.h"
#include "Model/provider.h"
#include "ViewModel/mainviewmanager.h"
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
    static auto STYLE_PREFIX = QStringLiteral(":/styles/");

    Startup::Startup() : 
        QObject(nullptr),                
        m_MainWindow( *new MainWindow(nullptr) ),
        m_mainViewManager(new MainViewManager(this,Provider::GetSettingsAsSingleton(),m_MainWindow))
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
            if(!res_dir.exists())
            {
                //ToDo Stop complaining and cut the process                
                abort();
            }
            //dark orrange qss
            Settings& currentSetting = Provider::GetSettingsAsSingleton();

            if(currentSetting.getCurrentStyle() == "default")
                return;

            QString fileName("%1.qss");
            fileName = fileName.arg(currentSetting.getCurrentStyle());
            
            QString path =res_dir.filePath(QString("%1/%2").arg(currentSetting.getCurrentStyle()).arg(fileName));
            
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
        
        // QTranslator translator;        
        
        // //get the language from settings ...
        // Settings& currentSetting = Provider::GetSettingsAsSingleton();
        // QString lang("%1.qm");
        // lang = lang.arg(currentSetting.getCurrentLanguage());
        // bool bResult = translator.load(lang);
        // if(!bResult)
        // {
        //    QMessageBox::information(nullptr,tr("Message"),tr("Could not load language file"));
        // }
        // else
        // {
        //     //Why it's not working ?
        //     m_MainWindow.changeTranslation(translator,lang);
        // }
    }
     

    void Startup::show() const
    {
        //Progress bar will be usefull 
        loadStyles();
        //loadLanguages();
        //Progress bar will be usefull 

        m_MainWindow.show();
    }
}



