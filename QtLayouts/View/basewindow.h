    #pragma once 
    #include <QObject>
    #include <QWidget>
    #include <QTranslator>
    #include "Model/settings.h"
    #include "Model/logger.h"
    #include "Model/provider.h"

    using namespace Miracle;

    class BaseWindow
    {
        

        protected:
            Settings& m_Settings;
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


