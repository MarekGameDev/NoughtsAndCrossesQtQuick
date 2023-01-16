#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "game.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    Game game;    // Create the application core with signals and slots

    QQmlApplicationEngine engine;
    engine.addImportPath("./gggg");
    QQmlContext *context = engine.rootContext();

    /* We load the object into the context to establish the connection,
     * and also define the name "appCore" by which the connection will occur
     * */
    context->setContextProperty("game", &game);

//    const QUrl url(QStringLiteral("qrc:/NoughtsAndCrosses2/main.qml"));
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
