#include "RubiksEdu.h"

#include "CubeController.h"
#include "Cube2dWindow.h"
#include "TutorialBrowser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);
    CubeController m;
    TutorialBrowser tutorial;
    RubiksEdu w(nullptr,&m,&tutorial);

    w.setFixedSize(w.size());
    w.show();

//    For testing purposes of the 2d cube
//    Cube2dWindow cube2dWindow;
//    Cube2dWindow c(nullptr,&m);
//    c.show();

   return a.exec();
}
