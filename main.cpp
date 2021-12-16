/*
 * Lacking Ideas - Rubiks Educational App
 * CS 3505 - A9 - An Education App
 * @authors: Robert Davidson
 *           Orion Santiago
 *           Ronnie Koe
 *           Maiko Tuitupou
 *           Elizabeth Thomas
 *           Alex Gill
 * main.cpp
*/

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
    RubiksEdu w(nullptr, &m);
    w.setFixedSize(w.size());
    w.show();

    return a.exec();
}
