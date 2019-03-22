#ifndef UTILS_H
#define UTILS_H
#include <QObject>
#include <memory>


namespace Ps {
    class Utils
    {
    public:
        Utils();
        static void DestructorMsg(QString value);
        static void DestructorMsg(QObject *value);     
        //template unique pointer 4 singleton 
        template <typename T, typename... Args>
        static std::unique_ptr<T> make_unique(Args&&... args){
            return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
        }
    private:
    };
}
#endif // UTILS_H


