#pragma once
#include <memory>

namespace Miracle 
{

    class Settings;
    class Logger;
    class Provider final
    {
        public:
            Provider();
            static Settings& GetSettingsAsSingleton();
            static Logger& GetLoggerAsSingleton();

        private:
            static std::unique_ptr<Settings> m_instanceSettings;            
            static std::unique_ptr<Logger> m_instanceLogger;

            explicit Provider(const Provider& rhs);
            Provider& operator= (const Provider& rhs);
    };

}