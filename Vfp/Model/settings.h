#ifndef SETTINGS_H
#define SETTINGS_H
#include <QWidget>
#include <QObject>

class QString;
class QStringListModel;
class QJsonParseError;
class QJsonObject;
class QFile;
class QDir;
class QJsonArray;

namespace Ps{

    typedef std::pair<QJsonObject, QJsonParseError> JsonObjErrorPair;

    class Settings : public QObject
    {
        Q_OBJECT
    public:
        explicit Settings(QObject * parent, QString filename);
        void ParseJsonData();
        JsonObjErrorPair GetJsonObject(const QString& rawJson);
    signals:
        void NotifyStatusMessage(QString message);

    private:
        QString m_applicationName;
        QString m_appShortName;
        QString m_hostName;
        int m_portNumber;
        int m_waitMs;
        int m_readWaitMs;        
        QStringListModel& m_modelCommands;
        QString m_pwCommand;

    private:
        QString m_fileName;
        void SendErrorMessage(const QString& msg);
        QString ReadJsonFile();
        QString ReadFromInternalResource();
        void SetupCommands(QJsonObject json_obj);
        QDir OpenConfigDirectory();
        void ShowJsonParseError(QJsonParseError json_error);
        //void ReadStyleFile();

        explicit Settings(const Settings& rhs) = delete;
        Settings& operator = (const Settings& rhs) = delete;
    };

}
#endif // SETTINGS_H


