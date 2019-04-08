#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "View/mainviewer.h"
#include <QIcon>


    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),   
        BaseWindow(),                    
        ui(new Ui::MainWindow)               
    {
        tabWidget = new QTabWidget;
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setDocumentMode(true);

        connect(tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(slotCloseTab(int)));


        ui->setupUi(this);
        Init();               
    }

    void MainWindow::slotCloseTab(int index)
    {
        tabWidget->removeTab(index);
        delete tabWidget->widget(index);
    }

    void MainWindow::Init()
    {              
        //Load language from settings        
        loadLanguage(m_Settings.getCurrentLanguage());
        createDock();            
        createLanguageMenu();  
        // m_mainTabList = new QList<MainTab*>();
        //setCentralWidget();
    }

        
    void MainWindow::createDock()
    {
        // m_mainTab = new MainTab(this);
        // setCentralWidget(m_mainTab);

        setCentralWidget(tabWidget);


        m_dock= new QDockWidget(tr("Left"), this);
        m_dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea ); 
        m_listWidget= new QListWidget(m_dock);
        
        m_listWidget->addItems(QStringList()
            << tr("L1")
            << tr("L2")
            << tr("L3")
            << tr("L4")
            << tr("L5")
            << tr("L6"));

        //Allow left right and bottom
        m_dock->setWidget(m_listWidget);

        m_dock2=new QDockWidget(tr("Right"), this);
        m_dock2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea ); 
        m_listWidget2 = new QListWidget(m_dock2);
        m_listWidget2->addItems(QStringList()
            << tr("R1")
            << tr("R2")
            << tr("R3")
            << tr("R4")
            << tr("R5")
            );
        m_dock2->setWidget(m_listWidget2);
        
        addDockWidget(Qt::LeftDockWidgetArea, m_dock);        
        addDockWidget(Qt::RightDockWidgetArea, m_dock2); 

    }

    void MainWindow::changeEvent(QEvent* event)
    {

         if(nullptr != event) {
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
        QStringList files = dir.entryList(QStringList("*.qm"));

        for (int i = 0; i < files.size(); ++i) 
        {
            // get locale extracted by filename
            QString locale;
            locale = files[i]; // "tr_TR.qm"
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
        if(nullptr != action)
        {
            // load the language dependant on the action content
            loadLanguage(action->data().toString());
            setWindowIcon(action->icon());
        }        
    }

    MainWindow::~MainWindow()
    {        
        delete ui;                
        delete tabWidget;
        delete m_listWidget;
        delete m_listWidget2;
        delete m_dock;                
        delete m_dock2;
    }



void MainWindow::on_actionClose_triggered()
{
     QApplication::quit();
}

void MainWindow::on_action_New_triggered()
{
    QFileDialog dialog;
    dialog.setNameFilter(tr("Images (*.png *.tif *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QStringList files;
    if (dialog.exec())
        files = dialog.selectedFiles();

    for(int i = 0; i < files.count(); i++)
    {
        QFileInfo fi(files[0]);        
        MainViewer* mv = new MainViewer(this);
        mv->Load(files[i]);
        tabWidget->addTab(mv,fi.fileName());
    }    
}
