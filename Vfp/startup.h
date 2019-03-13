#ifndef STARTUP_H
#define STARTUP_H
#include <QObject>

namespace Ps {

class MainView;
    class SetupTab;

    class Startup : public QObject
    {
        Q_OBJECT
    public:
        Startup();
        ~Startup();
        void show() const;
    private:
        SetupTab& m_setupTab;
        MainView& m_mainView;

        explicit Startup(const Startup& rhs) = delete;
        Startup& operator = (const Startup&rhs) = delete;

    };
}
#endif // STARTUP_H


