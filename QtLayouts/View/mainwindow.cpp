#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>

    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)               
    {
        ui->setupUi(this);
        Init();       
    }

    void MainWindow::Init()
    {   
        createDock();    
        createLanguageMenu();       

        Settings& setting = Provider::GetSettingsAsSingleton(); 
        loadLanguage(setting.getCurrentLanguage());
    }

    void MainWindow::createDock()
    {
         auto dock = new QDockWidget(tr("Left"), this);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea); 
        QListWidget& listWidget(*new QListWidget(dock));
        
        listWidget.addItems(QStringList()
            << tr("L1")
            << tr("L2")
            << tr("L3")
            << tr("L4")
            << tr("L5")
            << tr("L6"));
        //Allow left right and bottom
        dock->setWidget(&listWidget);


        auto dock2 = new QDockWidget(tr("Right"), this);
        auto list2 = new QListWidget(dock2);
        list2->addItems(QStringList()
            << tr("R1")
            << tr("R2")
            << tr("R3")
            << tr("R4")
            << tr("R5")
            );
        dock2->setWidget(list2);

        addDockWidget(Qt::LeftDockWidgetArea, dock);        
        addDockWidget(Qt::RightDockWidgetArea, dock2); 
    }

    void MainWindow::changeEvent(QEvent* event)
    {

         if(0 != event) {
          switch(event->type()) {
            // this event is send if a translator is loaded
            case QEvent::LanguageChange:
                ui->retranslateUi(this);
            break;
             case QEvent::LocaleChange:
            {
                QString locale = Provider::GetSettingsAsSingleton().getCurrentLanguage();                
                loadLanguage(locale);
            }
          }
         }

        QMainWindow::changeEvent(event);

    }

    void MainWindow::createLanguageMenu()
    {
        QActionGroup* langGroup = new QActionGroup(ui->menuLanguage);
        langGroup->setExclusive(true);

        connect(langGroup, SIGNAL (triggered(QAction *)), this, SLOT (slotLanguageChanged(QAction *)));

        // format systems language
        //QString defaultLocale = QLocale::system().name(); // e.g. "de_DE"

        Settings& settings = Provider::GetSettingsAsSingleton();
        QString defaultLocale = settings.getCurrentLanguage();
        //defaultLocale.truncate(defaultLocale.lastIndexOf('_')); // e.g. "de"

        m_langPath = QApplication::applicationDirPath();
        //m_langPath.append("/languages");
        QDir dir(m_langPath);
        QStringList fileNames = dir.entryList(QStringList("*.qm"));

        for (int i = 0; i < fileNames.size(); ++i) 
        {
            // get locale extracted by filename
            QString locale;
            locale = fileNames[i]; // "türkçe.qm"
            locale.truncate(locale.lastIndexOf('.')); // "türkçe"
            //locale.remove(0, locale.indexOf('.') + 1); // "de"

            //QString lang = QLocale::languageToString(QLocale(locale).language());
            
            QIcon ico(QString(":/"+ locale +".png"));

            QAction *action = new QAction(ico, locale, this);
            action->setCheckable(true);
            action->setData(locale);

            ui->menuLanguage->addAction(action);
            langGroup->addAction(action);

            // set default translators and language checked
            if (defaultLocale == locale)
            {
                action->setChecked(true);
            }
        }
    }

    void MainWindow::loadLanguage(const QString& rLanguage)
    {
            if(m_currLang != rLanguage) {
            
            // m_currLang = rLanguage;
            // QLocale locale = QLocale(m_currLang);
            // QLocale::setDefault(locale);
            //QString languageName = QLocale::languageToString(locale.language());

            changeTranslation(m_translator, QString("%1.qm").arg(rLanguage));
            changeTranslation(m_translatorQt, QString("%1.qm").arg(rLanguage));

            // switchTranslator(m_translator, QString("%1.qm").arg(rLanguage));
            // switchTranslator(m_translatorQt, QString("%1.qm").arg(rLanguage));
            ui->statusBar->showMessage(tr("Current Language changed to %1").arg(rLanguage));
            }
    }

    void MainWindow::slotLanguageChanged(QAction* action)
    {
        if(0 != action) 
        {
            // load the language dependant on the action content
            loadLanguage(action->data().toString());
            setWindowIcon(action->icon());
        }

        //menuLanguage
    }

    MainWindow::~MainWindow()
    {        
        delete ui;
    }

    
     // we create the menu entries dynamically, dependent on the existing translations.
  
   void MainWindow::changeTranslation(QTranslator& translator, const QString& fileName)
   {
       qApp->removeTranslator(&translator);
       if(translator.load(fileName,QCoreApplication::applicationDirPath()))
       {
            QApplication::instance()->installTranslator(&translator);
            qApp->installTranslator(&translator);
            //ui->retranslateUi(this);    
            //Init();      
       }       
       
   }
    


