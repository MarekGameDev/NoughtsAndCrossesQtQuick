#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "game.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    Game game;

    QQmlApplicationEngine engine;
    engine.addImportPath("./gggg");
    QQmlContext *context = engine.rootContext();

    context->setContextProperty("game", &game);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
