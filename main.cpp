#include "RubiksEdu.h"
#include "Model.h"
#include "Cube2dWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);

    Model m;
    Cube2dWindow cube2dWindow;
    RubiksEdu w(nullptr,&m,&cube2dWindow);

    w.setFixedSize(w.size());
    w.show();

   return a.exec();
}
