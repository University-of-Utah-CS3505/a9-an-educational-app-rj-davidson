#ifndef CUBECONTROLLER_H
#define CUBECONTROLLER_H

#include <QWidget>
#include <QImage>
#include <vector>

#include "Cube.h"
#include "ViewCube.h"
#include "View3DCube.h"
#include "Model3DCube.h"

class CubeController: public QWidget
{
    Q_OBJECT
public:
    explicit CubeController(QWidget *parent = nullptr);
signals:
    void updateCube(std::vector<QImage>);
    void update3DCubeScene(QGraphicsScene *scene,QGraphicsPathItem *itemRLeft,QGraphicsPathItem *itemRRight,QGraphicsPathItem *itemRTop);
    void updateUserRotation(string dirRotate);
private:
    Cube userCube;



    void setupAndRandomizeCube();
    void setUpFirstCross();
    void setUpFirstCorners();
    void setUpNeighbors();
    void setUpBottomCross();
    void setUpFinalCorners();

    //3d cube stuff
    Model3DCube cube3D;
    View3DCube  cube3DView;

    QVector<QGraphicsPathItem*> vctrTester;//Tester only will need to be deleted when all of the face vectors are being saved into their own vectors
    QGraphicsScene *scene;
    QGraphicsPathItem *itemRLeft;
    QGraphicsPathItem *itemRRight;
    QGraphicsPathItem *itemRTop;
    float cubeSize = 120;
    float eSize = cubeSize / 3; //size of each element
    // (0,0) is at bottom piont on cube
    // so left view is negative, right view is positive
    float xScale = 0.866025403784; //cos(30deg)
    float yScale = 0.5;		//sin(30deg)
    float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;
    void create3DCubeView(); //void open2DCubeWindow();
    void createLeftOfCube();
    void createRightOfCube();
    void createTopOfCube();

public:
    void setEduMode(int);

public slots:
    void switchFace(int);
    void MoveCube(int);
    void rotationCube(string dirRotate);
};

#endif // CUBECONTROLLER_H
