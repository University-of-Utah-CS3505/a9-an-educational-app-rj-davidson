#include "mainwindow.h"
//#include "rubiksedu.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Model m;
    //RubiksEdu w(nullptr, &m);
    w.show();
    return a.exec();
}
