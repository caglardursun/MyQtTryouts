#include <QString>
#include "Model/settings.h"
#include "Model/logger.h"
#include "provider.h"
#include "utils.h"


namespace Miracle
{

    static QString SETTINGS_FILE = QStringLiteral("settings.json");
    static QString LOG_FILE = QStringLiteral("log.txt");

    std::unique_ptr<Settings> Provider::m_instanceSettings = nullptr;
    std::unique_ptr<Logger> Provider::m_instanceLogger = nullptr;

    Settings& Provider::GetSettingsAsSingleton()
    {
        if(m_instanceSettings == nullptr)
        {
            m_instanceSettings  = Utils::make_unique<Settings>(nullptr, SETTINGS_FILE);
        }

        return *m_instanceSettings;
    }

    Logger& Provider::GetLoggerAsSingleton()
    {
        if(m_instanceLogger == nullptr)
        {
            m_instanceLogger  = Utils::make_unique<Logger>(nullptr, SETTINGS_FILE);
        }

        return *m_instanceLogger;
    }


} // namespace
