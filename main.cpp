#include "RubiksEdu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RubiksEdu w;
    w.show();
    return a.exec();
}
