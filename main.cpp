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
    Cube2dWindow cube2dWindow;
    TutorialBrowser tutorial;
    RubiksEdu w(nullptr,&m,&cube2dWindow,&tutorial);

    w.setFixedSize(w.size());
    w.show();

   return a.exec();
}
