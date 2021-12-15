// Linked to the Model

#ifndef CUBE_H
#define CUBE_H

#include "CubeFace.h"
#include <vector>
#include <QImage>
#include <algorithm>

enum RotationDirection {
    CLOCKWISE, COUNTERCLOCKWISE
};

class Cube
{
public:
    Cube();
    Cube(QVector<CubeFace> &newCubeFaces);//used for Model3DView

    void move(int);

    void moveF(RotationDirection dir);
    void moveU(RotationDirection dir);
    void moveD(RotationDirection dir);
    void moveL(RotationDirection dir);
    void moveR(RotationDirection dir);

    // Getters
    CubeFace getFace(int);
    QVector<CubeFace> getCube();
    int getCurrentFace();

    // Setters
    void setCurrentFace(int);

    // used to transform data in Model3DCube
    void setCubeFaces(QVector<CubeFace> newCubeFaces);

    // Solved Check
    bool isComplete();

    // Converts Cube to List of QImages
    QVector<QImage> toQImageList();

private:
    QVector<CubeFace> cubeFaces;
    QVector<CubeFace> firstCross;
    QVector<CubeFace> firstCorners;
    QVector<CubeFace> neighbors;
    QVector<CubeFace> oppositeCross;
    QVector<CubeFace> finalCorners;
    int currentFace;

    static QVector<CubeFace> rotateToFace(QVector<CubeFace> original, int faceID);
};
#endif // CUBE_H
