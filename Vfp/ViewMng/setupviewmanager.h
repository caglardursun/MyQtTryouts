#pragma once
#include <QObject>

namespace Ps
{

class SetupTab;
class ControlTab;
class Settings;

class SetupViewManager : public QObject
{
    Q_OBJECT
public:
    explicit SetupViewManager(QObject *parent,
                              SetupTab& tab,
                              ControlTab& controlTab,                              
                              Settings& config);

    ~SetupViewManager();

private:
    SetupTab& m_setupTab;
    ControlTab& m_controlTab;

    explicit SetupViewManager(const SetupViewManager& rhs);
    SetupViewManager& operator= (const SetupViewManager& rhs);
};

} // namespace

