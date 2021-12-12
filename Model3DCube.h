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

    enum yAxis{ up, down };
    enum xAxis{ deg0, deg90, deg180, deg270 };
    void setOrientation(yAxis yPos, xAxis xPos);

public slots:
    //controller tells model when to update the qImage qvector data for the 1d cube
    //In real time the 3d cube will change with the main 1d cube
    void update3DCube(Cube const &cube); //cube is const so that 3D cube does not modify 1D cube data on accident
    void update3DOrientation(const string &dirRotate);

signals:
    //the cube controller will tell what to display at the same time as the mainwindow cube
    //model notifies whats the controller does with the data for the 3dcube specefic data
    void notify3DCubeView(QVector<CubeFace> &visibleFaces);
    void notify3DCubeViewSimple(std::vector<char> &visibleFaces);


private:

    //controller tells model when to update the qImage qvector data for the 1d cube
    std::vector<QImage> vctrFaces1DCube;


    //temp data model with one color per face to make sure buttons are rotating cube correctly
    std::vector<char> cube3DFaceData = {'y', 'r', 'w', 'o', 'g', 'b'};

    std::vector<char> visibleFacesSimple;
    QVector<CubeFace> visibleFaces;

    Cube cubeCopyOf1D;
    Cube cube3D;

    void convertCube1DtoCube3D();
    //int conversionMap[6] = {2,1,3,4,0,5}; //cubeStyle0
    //int conversionMap[6] = {0,2,5,4,1,3}; //cubeStyle6
    int conversionMap[6] = {1,0,3,5,2,4}; //cubeStyle6
    //int conversionMap[6] = {0,1,2,3,4,5};

    // the model will need to know the visible faces
    void updateVisibleFaces();
    int getRightVisibleFacePosition();


    // the model will need to save the 3dcube orientation

    //Data for orientation code
    yAxis yAxisPosition = up;
    xAxis xAxisPosition = deg90;

    void rotate_right();
    void rotate_left();
    void rotate_up();

    void helper_decrease_angle();
    void helper_increase_angle();

    //orientation test functions
    void printOrientation();

    int cubeStyle = 0;




};

#endif // MODEL3DCUBE_H
