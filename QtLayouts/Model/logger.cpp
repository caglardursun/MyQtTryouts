#include "logger.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDateTime>
#include "utils.h"

namespace Miracle 
{

    Logger::Logger(QObject* parent,const QString fileName)
        : QObject (parent),
        m_fileName(fileName),
        m_showDate(true)
    {
                
        if (!m_fileName.isEmpty()) 
        {
            m_file = new QFile;
            m_file->setFileName(fileName);
            m_file->open(QIODevice::Append | QIODevice::Text);
        }

    }

    Logger::~Logger()
    {
        if (m_file != 0)
            m_file->close();

        Utils::DestructorMsg(this);
    }

    void Logger::Log(const QString message)
    {
        QString text = message;

        if (m_showDate)
        {
            text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text;
        }
            

        QTextStream output(m_file);
        output.setCodec("UTF-8");

        if (m_file != 0) 
        {
            output << text;
        }

    }    

    void Logger::Error(QObject *value)
    {
        
        QString text("Class : %1 Function : %2");
        text = text.arg(value->metaObject()->className()).arg(Q_FUNC_INFO);
        

        if (m_showDate)
        {
            text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text;
        }
            

        QTextStream output(m_file);
        output.setCodec("UTF-8");

        if (m_file != 0) 
        {
            output << text;
        }
    }

    void Logger::Error(QString message)
    {
         QString text("");

        if (m_showDate)
        {
            text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text;
        }
            

        QTextStream output(m_file);
        output.setCodec("UTF-8");

        if (m_file != 0) 
        {
            output << text;
        }
    }

    void Logger::Message(QString msg)
    {
         
    }

}