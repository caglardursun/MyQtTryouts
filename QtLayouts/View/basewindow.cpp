    #include "basewindow.h"
    #include <QApplication>
    #include "utils.h"

    BaseWindow::BaseWindow():
        m_Settings(Provider::GetSettingsAsSingleton())           
    {
        loadLanguage(m_Settings.getCurrentLanguage());
    }

    BaseWindow::~BaseWindow()
    {
        //QObject modek
        //Utils::DestructorMsg(this);
    }

    void BaseWindow::changeTranslation(QTranslator& translator, const QString& fileName)
    {
        //qApp macro nun tanımı kullanıldı bire bir
        QApplication* pApp = (static_cast<QApplication *>(QCoreApplication::instance()));
        pApp->removeTranslator(&translator);
        
        if(translator.load(fileName,QCoreApplication::applicationDirPath()))
        {            
                pApp->installTranslator(&translator);            
        }       
    }


    void BaseWindow::loadLanguage(const QString& rLanguage)
    {
            if(m_currLang != rLanguage) 
            {
                changeTranslation(m_translator, QString("%1.qm").arg(rLanguage));
                changeTranslation(m_translatorQt, QString("%1.qm").arg(rLanguage));                    
                //ui->statusBar->showMessage(tr("Current Language changed to %1").arg(rLanguage));            
            }
    }