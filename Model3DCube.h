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

using namespace std;

/*
 * the model will need to know the way each face needs to look and keep track of the
 * 3dcube orientation, and faces hidden and visible
 *
 * controller tells model when to update the qImage qvector data for the 1d cube
 *
 * model notifies whats the controller does with the data for the 3dcube specefic data
*/
class Model3DCube: public QObject
{
    Q_OBJECT
public:
    Model3DCube();
   // Model3DCube(QWidget *parent=nullptr,CubeController *controller=nullptr);
    std::vector<QImage> getQImageList();

private slots:
    //controller tells model when to update the qImage qvector data for the 1d cube
    //In real time the 3d cube will change with the main 1d cube
    void update3DCube(std::vector<QImage>);

signals:
    //the cube controller will tell what to display at the same time as the mainwindow cube
    //model notifies whats the controller does with the data for the 3dcube specefic data
    void notify3DCubeView(std::vector<QImage> qImageList);


private:

    //controller tells model when to update the qImage qvector data for the 1d cube
    std::vector<QImage> vctrFaces1DCube;

    //this is 3d cube info data specefic
    QVector<QGraphicsPathItem*> vctrTester;//Tester only will need to be deleted when all of the face vectors are being saved into their own vectors
    QVector<QGraphicsPathItem*> vctrFace0;
    QVector<QGraphicsPathItem*> vctrFace1;
    QVector<QGraphicsPathItem*> vctrFace2;
    QVector<QGraphicsPathItem*> vctrFace3;
    QVector<QGraphicsPathItem*> vctrFace4;
    QVector<QGraphicsPathItem*> vctrFace5;

    // the model will need to know the faces hidden and visible
    void updateVisibleFace();
    void updateHiddenFaces();

    // the model will need to know the way each face needs to look
    void updateFace0(QImage f0,QImage scaled);
    void updateFace1(QImage f1,QImage scaled);
    void updateFace2(QImage f2,QImage scaled);
    void updateFace3(QImage f3,QImage scaled);
    void updateFace4(QImage f4,QImage scaled);
    void updateFace5(QImage f5,QImage scaled);

    // the model will need to save the 3dcube orientation
    void updateOrientation();




};

#endif // MODEL3DCUBE_H
