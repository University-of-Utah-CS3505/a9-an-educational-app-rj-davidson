#include "RubiksEdu.h"
#include "Model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    RubiksEdu w(nullptr, &m);
    w.show();
    return a.exec();
}
