#ifndef STARTUP_H
#define STARTUP_H
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
        SetupTab& m_setupTab;
        MainView& m_mainView;


        //void ApplyStyles() const;

        explicit Startup(const Startup& rhs) = delete;
        Startup& operator = (const Startup&rhs) = delete;

    };
}
#endif // STARTUP_H


