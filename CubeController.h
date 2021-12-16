#ifndef CUBECONTROLLER_H
#define CUBECONTROLLER_H

#include <QWidget>
#include <QImage>
#include <vector>

#include "Cube.h"
#include "ViewCube.h"
#include "Model3DCube.h"

class CubeController : public QWidget
{
    Q_OBJECT
public:
    explicit CubeController(QWidget *parent = nullptr);

signals:
    void updateCube(QVector<QImage>);

    // cube3Dview signals
    void updateUserRotation(const string &dirRotate);
    void update3DCubeViewSimple(QVector<char> &visibleFaces);
    void update3DCubeView(QVector<CubeFace> &visibleFaces);
    void cube1DUpdated(Cube &cube); // needs to be emitted every time 1D cube is updated so 3D cube can stay in sync

    void complete();

private:
    Cube userCube;
    Cube lastNontutorialCube;

    void setUserCube(Cube c);

    // 3d cube stuff
    Model3DCube cube3D;

public slots:
    void buildPredefinedCube(int cubeID);
    void buildRandomCube();
    void buildDebugCube();
    void buildSolvedCube();
    void switchFace(int);
    void MoveCube(int);

    // cube3Dview slots
    void reset3DCubeOrientation();
    void rotationCube(const string &dirRotate);
    void on_cube3DdataUpdated(QVector<char> &visibleFaceData);
};

#endif // CUBECONTROLLER_H
