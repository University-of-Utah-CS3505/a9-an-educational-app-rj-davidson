#include "RubiksEdu.h"
#include "Model.h"
#include "window3dcube.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Window3DCube cube3DWindow;
    RubiksEdu w(nullptr, &m,&cube3DWindow);
    //Window3DCube s(nullptr);
    //s.show();
    w.show();
    return a.exec();
}
