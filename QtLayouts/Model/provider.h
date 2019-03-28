#pragma once
#include <memory>

namespace Miracle 
{

    class Settings;
    class Provider final
    {
        public:
            Provider();
            static Settings& GetSettingsAsSingleton();

        private:
            static std::unique_ptr<Settings> m_instanceSettings;            

            explicit Provider(const Provider& rhs);
            Provider& operator= (const Provider& rhs);
    };

}