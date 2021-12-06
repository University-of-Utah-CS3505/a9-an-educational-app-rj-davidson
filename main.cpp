#include "RubiksEdu.h"
#include "Model.h"
#include "Window2dCube.h"
#include "Cube2dWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);
    Model m;
    Window2DCube cube2DWindow;
    RubiksEdu w(nullptr, &m,&cube2DWindow);

    w.setFixedSize(w.size());
    w.show();

    Cube2dWindow cube2dWindow(nullptr);
    cube2dWindow.show();


   return a.exec();
}
