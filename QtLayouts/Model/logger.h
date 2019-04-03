#pragma once 
#include <QWidget>
#include <QObject>
#include <QFile>

namespace Miracle
{           
    class Logger : QObject
    {
        Q_OBJECT;
        public:
            explicit Logger(QObject* parent,const QString fileName);
            ~Logger();
        public:            
            void Log(const QString message);            
            void Error(QObject *value);
            void Error(const QString message);
            void setShowDateTime(bool value);

        private:
            void Message(QString message);
            const QString m_fileName;  
            bool m_showDate;  
            QFile *m_file;
 
    };

}