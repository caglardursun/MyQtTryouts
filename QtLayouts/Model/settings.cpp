#include <QObject>
#include <QDir>
#include <QFile>
//Qt Utility header different from ours
#include <utility>
//EOF Qt Utility header
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QStringListModel>
#include <QStandardPaths>
#include <QMessageBox>

#include "settings.h"
#include "utils.h"

namespace Miracle
{
    //resource okunurken string literal json node una erişiyor.
    static auto RESOURCE_PREFIX = QStringLiteral(":/json");
    static const int PW_COMMAND_INDEX = 5;

    Settings::Settings(QObject * parent, QString filename)
        : QObject (parent),          
        m_fileName(filename),
        m_applicationName("Miracle Colorway"),
        m_appShortName("Colorway"),                
        m_currentStyle("darkorange"),
        m_currentLanguage("tr_TR")
    {        
        ParseJsonData();
    }



    void Settings::ParseJsonData()
    {
        auto raw_json = ReadJsonFile();
        if(raw_json.size() == 0)
            return;

        auto json_result = GetJsonObject(raw_json);

        auto json_error = json_result.second;
        if(json_error.error != QJsonParseError::NoError)
        {
            //Show Error ...    
            ShowJsonParseError(json_error);
        }

        QJsonObject json_obj = json_result.first;
        m_applicationName = json_obj["applicationName"].toString();
        m_appShortName = json_obj["applicationShortName"].toString();     
        m_currentLanguage = json_obj["currentLanguage"].toString();
        m_currentStyle = json_obj["currentStyle"].toString();

    }

     

    JsonObjErrorPair Settings::GetJsonObject(const QString& rawJson)
    {
        QJsonParseError json_parse_error;
        QJsonDocument json_doc = QJsonDocument::fromJson(rawJson.toUtf8(), &json_parse_error);
        QJsonObject json_obj = json_doc.object();

        return std::make_pair(json_obj, json_parse_error);
    }

    

    QString Settings::ReadJsonFile()
    {
        auto default_Settings =  ReadFromInternalResource();        

        QDir config_dir = OpenConfigDirectory();
        auto path = config_dir.filePath(m_fileName);

        QFile std_file(path);

        if(std_file.exists())
        {
            if(!std_file.open( QFile::ReadOnly | QFile::Text))
            {
                SendErrorMessage(tr("Could not open %1").arg(path));
                return default_Settings;            
            }
            else
            {
                WriteDefaultsToStdConfigFile(std_file,default_Settings);
            }
        }else
        {
                        
            WriteDefaultsToStdConfigFile(std_file, default_Settings);
        }

        return default_Settings;
    }

    void Settings::WriteDefaultsToStdConfigFile(QFile& stdConfigFile,const QString& settings)
    {
        int length = settings.length();
        if (!stdConfigFile.open(QFile::WriteOnly|QFile::Text))
        {
            SendErrorMessage(tr("Could not open file to write %1").arg(stdConfigFile.fileName()));
        }
        else
        {
            qint64 bytes_written = stdConfigFile.write(qPrintable(settings),length);
            if (bytes_written != length)
            {
            SendErrorMessage(tr("Could not write default settings to %1").arg(stdConfigFile.fileName()));
            if (!stdConfigFile.remove())
            {
                SendErrorMessage(tr("Coudt not remove configuration file. Please delete %1").arg(stdConfigFile.fileName()));
            }
            }
            stdConfigFile.close();
        }
    }

    QDir Settings::OpenConfigDirectory()
    {
        QDir config_dir(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation));
        if (!config_dir.exists())
        {
            QDir dir;
            if (!dir.mkdir(config_dir.path()))
            {
                SendErrorMessage(tr("Could not create configuration directory"));
                abort();
            }
        }
        
        return config_dir;
    }



    QString Settings::ReadFromInternalResource()
    {
            QDir res_dir(RESOURCE_PREFIX);
            if(!res_dir.exists()){
                //ToDo Send Error message
                SendErrorMessage(tr("Resource directory not found"));
                return "";
            }

            auto path =res_dir.filePath(m_fileName);
            
            QFile res_file(path);
            

            if(!res_file.open(QFile::ReadOnly | QFile::Text))
            {
                SendErrorMessage(tr("Cound not open internal resource %1").arg(path));

                return "";
            }

            QString settings = res_file.readAll();            
            return settings;
    }

    void Settings::ShowJsonParseError(QJsonParseError json_error)
    {
        
        QString msg = tr("Error parsing JSON settings file.\n");
        msg.append(json_error.errorString());
        QMessageBox::critical(0,tr("VFP"),msg);
    }

    void Settings::SendErrorMessage(const QString& msg)
    {

        /*
        IMO emit is neither syntactic sugar nor a simple keyword in the sense that

        It generates code,
        It helps the connect mechanism recognize that indeed it is a signal, and
        It makes your signal part of a "bigger" system, where signals and 
        responses (slots) can be executed synchronously or asynchronously, or 
        queued, depending on where and how the signal got emitted. This is an 
        extremely useful feature of the signal/slot system.

        */
        emit NotifyStatusMessage(msg);
    }

    
}
