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
        //Load language from settings        
        loadLanguage(m_Settings.getCurrentLanguage());
        createDock();            
        createLanguageMenu();    
    }

    

    void MainWindow::createDock()
    {
        dock= new QDockWidget(tr("Left"), this);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea); 
        listWidget= new QListWidget(dock);
        
        listWidget->addItems(QStringList()
            << tr("L1")
            << tr("L2")
            << tr("L3")
            << tr("L4")
            << tr("L5")
            << tr("L6"));

        //Allow left right and bottom
        dock->setWidget(listWidget);

        dock2=new QDockWidget(tr("Right"), this);
        listWidget2 = new QListWidget(dock2);
        listWidget2->addItems(QStringList()
            << tr("R1")
            << tr("R2")
            << tr("R3")
            << tr("R4")
            << tr("R5")
            );
        dock2->setWidget(listWidget2);
        
        addDockWidget(Qt::LeftDockWidgetArea, dock);        
        addDockWidget(Qt::RightDockWidgetArea, dock2); 
    }

    void MainWindow::changeEvent(QEvent* event)
    {

         if(0 != event) {
          switch(event->type()) {
            // this event is send if a translator is loaded
            case QEvent::LanguageChange:
                {
                    ui->retranslateUi(this);                    
                }
            break;
             case QEvent::LocaleChange:
            {
                
                loadLanguage(m_Settings.getCurrentLanguage());
            }         
          }//end of switch

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

        //Settings& settings = Provider::GetSettingsAsSingleton();
        QString defaultLocale = m_Settings.getCurrentLanguage();
        //defaultLocale.truncate(defaultLocale.lastIndexOf('_')); // e.g. "de"

        m_langPath = QApplication::applicationDirPath();
        //m_langPath.append("/languages");
        QDir dir(m_langPath);
        QStringList fileNames = dir.entryList(QStringList("*.qm"));

        for (int i = 0; i < fileNames.size(); ++i) 
        {
            // get locale extracted by filename
            QString locale;
            locale = fileNames[i]; // "tr_TR.qm"
            locale.truncate(locale.lastIndexOf('.')); // "tr_TR"

            QString lang = QLocale::languageToString(QLocale(locale).language());
            
            QIcon ico(QString(":/images/"+ locale +".png"));

            QAction *action = new QAction(ico, lang, this);
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
        delete listWidget;
        delete listWidget2;
        delete dock;                
        delete dock2;
        
        
    }

    void MainWindow::on_actionClose_triggered()
    {
        QApplication::quit();
    }
