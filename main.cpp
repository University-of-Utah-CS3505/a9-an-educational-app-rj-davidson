#include "RubiksEdu.h"

#include "CubeController.h"
#include "TutorialBrowser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);
    CubeController m;
    RubiksEdu w(nullptr,&m);

    w.setFixedSize(w.size());
    w.show();


   return a.exec();
}
