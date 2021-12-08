#ifndef VIEW3DCUBE_H
#define VIEW3DCUBE_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainterPath>
#include <QRectF>
#include <QSize>
#include <QDebug>
#include <QImage>
#include <QByteArray>
#include <QVector>
#include <iostream>
#include <QString>
#include <QPushButton>

#include "Cube.h"
#include "CubeController.h"
#include "TutorialBrowser.h"

using namespace std;

/*
 * controller tells view to update
 *
 * the view tels the controller when there is user action
*
*In real time the 3d cube will change with the main 1d cube
*
*It will also change with the button's changing up, right, left 180deg accordingly
*
*the view will need to know which faces are viewed and hidden of itself from buttons actions
*/
class View3DCube
{
public:
    View3DCube(QWidget *parent = nullptr,CubeController *controller=nullptr);
 //   ~View3DCube();
public slots:
    void open2DCubeWindow();
    void updateBtnClicked(string dir);

private slots:



private:
//    Ui::Cube2dWindow *ui;
    QGraphicsScene *scene1;
    QGraphicsPathItem *itemRLeft;
    QGraphicsPathItem *itemRRight;
    QGraphicsPathItem *itemRTop;

    QVector<QGraphicsPathItem*> vctrTester;//Tester only will need to be deleted when all of the face vectors are being saved into their own vectors
    QVector<QGraphicsPathItem*> vctrFace0;
    QVector<QGraphicsPathItem*> vctrFace1;
    QVector<QGraphicsPathItem*> vctrFace2;
    QVector<QGraphicsPathItem*> vctrFace3;
    QVector<QGraphicsPathItem*> vctrFace4;
    QVector<QGraphicsPathItem*> vctrFace5;



    QPainterPath path1;
    QPainterPath path2;
    QPainterPath path3;

    void createLeftOfCube();
    void createRightOfCube();
    void createTopOfCube();

   void createBtnConnection();

   void leftPushBtnClicked();
   void rightPushBtnClicked();
   void upPushBtnClicked();
};

#endif // VIEW3DCUBE_H
