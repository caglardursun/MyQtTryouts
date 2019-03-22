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

        QString getApplicationName() const { return m_applicationName; }
        QString getAppShortName() const { return m_appShortName; }
        QString getHostName() const { return m_hostName; }
        quint16 getPortNumber() const { return m_portNumber; }
        int getShortWaitMs() const { return  m_shortWaitMs; }
        int getLongWaitMs() const { return m_longWaitMs; }
        QStringListModel& getCommandsAsModel() const { return m_modelCommands; }
        QString GetPwCommand() const { return m_pwCommand; }

    signals:
        void NotifyStatusMessage(QString message);

    private:
        QString m_applicationName;
        QString m_appShortName;
        QString m_hostName;
        int m_portNumber;
        int m_longWaitMs;
        int m_shortWaitMs;        
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
        void WriteDefaultsToStdConfigFile(QFile& stdConfigFile,const QString& settings);

        explicit Settings(const Settings& rhs) = delete;
        Settings& operator = (const Settings& rhs) = delete;
    };

}
#endif // SETTINGS_H


