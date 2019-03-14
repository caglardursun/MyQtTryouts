#include "settings.h"
#include "settings.h"
#include <QObject>


namespace Ps
{
    static auto RESOURCE_PREFIX = QStringLiteral("");
    Settings::Settings(QObject * parent, QString filename)
        : QObject (parent),
          m_fileName(filename)
    {

    }

    QString Settings::ReadJsonFile()
    {
        auto defalt_Settings =  ReadFromInternalResource();
    }

    QString Settings::ReadFromInternalResource()
    {

    }
}
