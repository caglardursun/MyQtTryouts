#include "mainviewmanager.h"
#include "View/mainwindow.h"
#include "utils.h"

namespace Miracle
{

    MainViewManager::MainViewManager(QObject* parent,Settings& config,MainWindow& mainwindow)
        :QObject(parent),
        m_Settings(config),
        m_mainwindow(mainwindow)        
    {

    }

    MainViewManager::~MainViewManager()
    {
        Utils::DestructorMsg(this);
    }

}