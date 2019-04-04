#pragma once 
#include <QObject>
#include <QWidget>
#include <QTranslator>

class BaseWindow
{    

    public:
        
    protected:
        
        QTranslator m_translator; // contains the translations for this application
        QTranslator m_translatorQt; // contains the translations for qt
        QString m_langPath;
        QString m_currLang; // contains the currently loaded language
        void changeTranslation(QTranslator& translator,const QString& fileName);
        void loadLanguage(const QString& rLanguage);
    public:
        BaseWindow();
        ~BaseWindow();
};


