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
    void cubeComplete(bool); // emits true if the cube is completely solved

    //cube3Dview signals
    void updateUserRotation(const string &dirRotate);
    void update3DCubeViewSimple(std::vector<char> &visibleFaces);
    void update3DCubeView(QVector<CubeFace> &visibleFaces);
    void cube1DUpdated(Cube &cube); //needs to be emitted every time 1D cube is updated so 3D cube can stay in sync

    void complete(bool);

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


public:
    void setEduMode(int);

public slots:
    void switchFace(int);
    void MoveCube(int);

    //cube3Dview slots
    void rotationCube(const string &dirRotate);
    void on_cube3DdataUpdated(std::vector<char> &visibleFaceData);
    void checkCompletion();
};

#endif // CUBECONTROLLER_H
