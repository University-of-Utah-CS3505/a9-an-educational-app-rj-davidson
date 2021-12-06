#include "RubiksEdu.h"
#include "CubeController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CubeController m;
    RubiksEdu w(nullptr, &m);
    w.show();
    return a.exec();
}
