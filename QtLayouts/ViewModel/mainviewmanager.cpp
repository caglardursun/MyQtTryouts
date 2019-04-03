#include "mainviewmanager.h"
#include "View/mainwindow.h"
#include "utils.h"

namespace Miracle
{

    MainViewManager::MainViewManager(QObject* parent,Settings& config)
        :QObject(nullptr),
        m_Settings(config)        
    {

    }

    MainViewManager::~MainViewManager()
    {
        Utils::DestructorMsg(this);
    }

}