#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);    
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    
    QTranslator translator;
    if(translator.load("./lang_en"))
    {
            
    }else
    {
        app.installTranslator(&translator);
    }
    

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
