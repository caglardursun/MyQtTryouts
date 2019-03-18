#ifndef UTILS_H
#define UTILS_H
#include <QObject>

namespace Ps {
    class Utils
    {
    public:
        Utils();
        static void DestructorMsg(QString value);
        static void DestructorMsg(QObject *value);
        static void Message(QString value);
    private:
    };
}
#endif // UTILS_H


