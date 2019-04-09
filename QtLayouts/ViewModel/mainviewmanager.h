#pragma once
#include <QObject>
#include "Model/settings.h"
#include "Model/logger.h"
#include "Model/provider.h"
#include "View/mainviewer.h"
#include "View/mainwindow.h"

namespace Miracle
{
    
    class MainViewManager : public QObject
    {
        Q_OBJECT

        private:
            Settings& m_Settings;
            MainWindow& m_mainwindow;
        public:
            MainViewManager(QObject* parent,Settings& config,MainWindow& mainwindow);
            ~MainViewManager();
    };

}


