#ifndef MODEL3DCUBE_H
#define MODEL3DCUBE_H

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
 * the model will need to know the way each face needs to look and keep track of the 3dcube orientation, and faces hidden and visible
 *
 * controller tells model when to update with qImage qvector data
 *
 * model notifies whats the controller does with the data for the 3dcube specefic data
*/
class Model3DCube
{
public:
    Model3DCube(QWidget *parent = nullptr,CubeController *controller=nullptr);
    ~Model3DCube();

private slots:

signals:
    //the cube controller will tell what to display at the same time as the mainwindow cube
    void update2DCubeView(std::vector<QImage>);


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

    void updateLeftCubeData();
    void updateRightCubeData();
    void updateTopCubeData();

    void updateHiddenFaces();

    float cubeSize = 120;

    float eSize = cubeSize / 3; //size of each element

    // (0,0) is at bottom piont on cube
    //
    // so left view is negative, right view is positive

    float xScale = 0.866025403784; //cos(30deg)

    float yScale = 0.5;		//sin(30deg)

    float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;

    void updateFace0(QImage f0,QImage scaled);
    void updateFace1(QImage f1,QImage scaled);
    void updateFace2(QImage f2,QImage scaled);
    void updateFace3(QImage f3,QImage scaled);
    void updateFace4(QImage f4,QImage scaled);
    void updateFace5(QImage f5,QImage scaled);
};

#endif // MODEL3DCUBE_H
