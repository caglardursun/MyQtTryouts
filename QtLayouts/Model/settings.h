#pragma once

#include <QWidget>
#include <QObject>
#include <QJsonParseError>


class QString;
class QStringListModel;

class QJsonObject;
class QFile;
class QDir;
class QJsonArray;

namespace Miracle
{

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
        QString getCurrentLanguage() const {return m_currentLanguage; }
        QString getCurrentStyle() const {return m_currentStyle; }
        

    signals:
        void NotifyStatusMessage(QString message);

    private:
        QString m_applicationName;
        QString m_appShortName;
        QString m_currentLanguage;
        QString m_currentStyle;
    
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



