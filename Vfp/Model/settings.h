#ifndef SETTINGS_H
#define SETTINGS_H
#include <QWidget>



class QString;
class QStringListModel;
class QJsonParseError;
class QJsonObject;
class QFile;
class QDir;

namespace Ps{

    class Settings : public QObject
    {
        Q_OBJECT
    public:
        explicit Settings(QObject * parent, QString filename);

    private:
        QString m_fileName;
        QString ReadJsonFile();
        explicit Settings(const Settings& rhs) = delete;
        Settings& operator = (const Settings& rhs) = delete;
    };

}
#endif // SETTINGS_H


