#pragma once
#include <QObject>
#include "Model/settings.h"
#include "Model/logger.h"
#include "Model/provider.h"

namespace Miracle
{
    
    class MainViewManager : public QObject
    {
        Q_OBJECT;

        private:
            Settings& m_Settings;
        public:
            MainViewManager(QObject* parent,Settings& config);
            ~MainViewManager();
    };

}


