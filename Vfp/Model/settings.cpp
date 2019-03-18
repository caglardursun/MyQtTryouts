#include "settings.h"
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

#include "utils.h"

namespace Ps
{
    //resource okunurken string literal json node una erişiyor.
    static auto RESOURCE_PREFIX = QStringLiteral(":/json");
    static const int PW_COMMAND_INDEX = 5;

    Settings::Settings(QObject * parent, QString filename)
        : QObject (parent),          
        m_fileName(filename),
        m_applicationName(""),
        m_appShortName(""),
        m_hostName("127.0.0.1"),
        m_portNumber(555102),        
        m_modelCommands(* new QStringListModel(this))
          
    {        
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

        auto json_obj = json_result.first;
        m_applicationName = json_obj["applicationName"].toString();
        m_appShortName = json_obj["applicationShortName"].toString();
        m_hostName = json_obj["hostName"].toString();
        m_portNumber = json_obj["port"].toInt();
        m_waitMs = json_obj["tcpLongWaitMs"].toInt();
        m_readWaitMs = json_obj["tcpShortWaitMs"].toInt();
        SetupCommands(json_obj);

    }

    

    JsonObjErrorPair Settings::GetJsonObject(const QString& rawJson)
    {
        QJsonParseError json_parse_error;
        QJsonDocument json_doc = QJsonDocument::fromJson(rawJson.toUtf8(), &json_parse_error);
        QJsonObject json_obj = json_doc.object();

        return std::make_pair(json_obj, json_parse_error);
    }

    void Settings::SetupCommands(QJsonObject json_obj)
    {
        auto cmd_Array = json_obj["commands"].toArray();
        QStringList cmd_list;

        for(auto item: cmd_Array)
        {
            cmd_list.append(item.toString());
        }
        m_modelCommands.setStringList(cmd_list);

         QModelIndex index = m_modelCommands.index(PW_COMMAND_INDEX);
        QVariant test_cmd = m_modelCommands.data(index, Qt::DisplayRole);
        //qDebug() << "Test command" << test_cmd.toString();
        Utils::Message(tr("Test Command %1 ").arg(test_cmd.toString()));

        if (PW_COMMAND_INDEX < cmd_list.size())
        {
            m_pwCommand = cmd_list[PW_COMMAND_INDEX];
        }
        else
        {
            NotifyStatusMessage(tr("Unable to get pulse width command."));
        }
    }

    QString Settings::ReadJsonFile()
    {
        auto default_Settings =  ReadFromInternalResource();

        //QDir config_dir = OpenConfigurationDirectory();

        //Utils::Msg(default_Settings);

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
        }

        return default_Settings;
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

    //We will keep going on ..
    // void Settings::ReadStyleFile()
    // {
    //     QDir style_dir(STYLE_PREFIX);
    //     if(!style_dir.exists()){
    //             //ToDo Send Error message
    //             SendErrorMessage(tr("Style bullshit happened"));
    //             return;
    //     }

        
    // }

    QString Settings::ReadFromInternalResource()
    {
            QDir res_dir(RESOURCE_PREFIX);
            if(!res_dir.exists()){
                //ToDo Send Error message
                SendErrorMessage(tr("Some bullshit happened"));
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
            //Utils::Message(settings);
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
