#pragma once
#include <QObject>

namespace Ps {

class MainView;
    class SetupTab;

    class Startup final : public QObject
    {
        Q_OBJECT
    public:
        Startup();
        ~Startup();
        void show() const;
        
    private:
        void loadStyles() const;
    private:
        SetupTab& m_setupTab;
        MainView& m_mainView;
        
        explicit Startup(const Startup& rhs) = delete;
        Startup& operator = (const Startup&rhs) = delete;

    };
}



