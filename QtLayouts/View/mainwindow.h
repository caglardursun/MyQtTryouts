#pragma once

#include <QMainWindow>
#include <QtWidgets>
#include <QTranslator>
#include "toolbar.h"
#include "Model/provider.h"
#include "Model/settings.h"

using namespace Miracle;

namespace Ui 
{
    class MainWindow;
}



class MainWindow : public QMainWindow
    {
        Q_OBJECT


        public:
            explicit MainWindow(QWidget *parent);
            ~MainWindow();        
            void changeTranslation(QTranslator& translator,const QString& fileName);
        private:
            Ui::MainWindow *ui;
            void Init();
            void createLanguageMenu();
            void loadLanguage(const QString& rLanguage);
            void createDock();

            QTranslator m_translator; // contains the translations for this application
            QTranslator m_translatorQt; // contains the translations for qt
            QString m_langPath;
            QString m_currLang; // contains the currently loaded language

        protected:
            // this event is called, when a new translator is loaded or the system language is changed
            void changeEvent(QEvent*);

        protected slots:
            // this slot is called by the language menu actions
            void slotLanguageChanged(QAction* action);
            //QList<ToolBar*> toolBars;  
};

