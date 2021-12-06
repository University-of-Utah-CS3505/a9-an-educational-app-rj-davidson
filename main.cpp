#include "RubiksEdu.h"
#include "Model.h"
#include "Window2dCube.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtGui>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QApplication a(argc, argv);
    Model m;
    Window2DCube cube2DWindow;
    RubiksEdu w(nullptr, &m,&cube2DWindow);
    //Window3DCube s(nullptr);
    //s.show();


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Window3DCube.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    w.setFixedSize(w.size());
    w.show();

    app.exec();
   return a.exec();
    //return app.exec();
}
