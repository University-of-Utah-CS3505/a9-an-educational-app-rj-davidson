#ifndef CUBECONTROLLER_H
#define CUBECONTROLLER_H

#include <QWidget>
#include <QImage>
#include <vector>

#include "Cube.h"
#include "ViewCube.h"
#include "Model3DCube.h"



class CubeController: public QWidget
{
    Q_OBJECT
public:
    explicit CubeController(QWidget *parent = nullptr);

signals:
    void updateCube(std::vector<QImage>);
    void update3DCubeScene();
    void updateUserRotation(string dirRotate);
    void makeNew3DCube(QGraphicsScene *scene);

private:
    Cube userCube;

    //3d cube stuff
    Model3DCube cube3D;



    void setupAndRandomizeCube();
    void setUpFirstCross();
    void setUpFirstCorners();
    void setUpNeighbors();
    void setUpBottomCross();
    void setUpFinalCorners();


    void create3DCubeView(); //void open2DCubeWindow();


public:
    void setEduMode(int);

public slots:
    void switchFace(int);
    void MoveCube(int);
    void rotationCube(string dirRotate);
    void new3DCube(QGraphicsScene *scene);
};

#endif // CUBECONTROLLER_H
