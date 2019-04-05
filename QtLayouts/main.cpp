#include "startup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        Miracle::Startup startup;
        //Exit implimentation
        QObject::connect(&a, &QApplication::lastWindowClosed, &a, &QApplication::quit);

        startup.show();
        
        return a.exec();
}
