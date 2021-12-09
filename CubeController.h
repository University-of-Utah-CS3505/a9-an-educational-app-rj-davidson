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

    void update3DCubeScene();//unused
    void makeNew3DCube(QGraphicsScene *scene);//unused

    //currently used
    void updateUserRotation(const string &dirRotate);
    void update3DCube(std::vector<char> &visibleFaces);


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
    void rotationCube(const string &dirRotate);
    void new3DCube(QGraphicsScene *scene);
    void on_cube3DdataUpdated(std::vector<char> &visibleFaceData);
};

#endif // CUBECONTROLLER_H
