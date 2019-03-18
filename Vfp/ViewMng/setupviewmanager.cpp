#include "setupviewmanager.h"
#include "View/setuptab.h"
#include "Model/settings.h"
#include "utils.h"

namespace Ps
{
    SetupViewManager::SetupViewManager(QObject *parent,
                                   SetupTab &tab,
                                   ControlTab &controlTab,                                   
                                   Settings &config) :
        QObject(parent),
        m_setupTab(tab),
        m_controlTab(controlTab)        
        {

        }

        SetupViewManager::~SetupViewManager()
        {
            Utils::DestructorMsg(this);
        }

}