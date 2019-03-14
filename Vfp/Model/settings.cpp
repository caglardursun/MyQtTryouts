#include "settings.h"
#include <QObject>
#include <QDir>
#include <QFile>
#include "utils.h"

namespace Ps
{
    //resource okunurken string literal json node una erişiyor.
    static auto RESOURCE_PREFIX = QStringLiteral(":/json");
    Settings::Settings(QObject * parent, QString filename)
        : QObject (parent),
          m_fileName(filename)
    {
        ReadJsonFile();
    }

    QString Settings::ReadJsonFile()
    {
        auto defalt_Settings =  ReadFromInternalResource();
        Utils::Msg(defalt_Settings);
        return defalt_Settings;
    }

    QString Settings::ReadFromInternalResource()
    {
            QDir res_dir(RESOURCE_PREFIX);
            if(!res_dir.exists()){
                //ToDo Send Error message
                return "";
            }

            auto path =res_dir.filePath(m_fileName);
            QFile res_file(path);
            if(!res_file.open(QFile::ReadOnly | QFile::Text))
            {
                return "";
            }
            QString settings = res_file.readAll();

            return settings;
    }
}
