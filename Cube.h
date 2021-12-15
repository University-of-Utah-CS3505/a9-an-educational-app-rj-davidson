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
    Cube(QVector<CubeFace> &cubeFaces, bool flipBackFace);

    void setCubeFaces(QVector<CubeFace> newCubeFaces, bool flipBackFace);

    void flipBackFace();

    void moveF(RotationDirection dir);
    void moveU(RotationDirection dir);
    void moveD(RotationDirection dir);
    void moveL(RotationDirection dir);
    void moveR(RotationDirection dir);

    QVector<CubeFace> getAllFaces();
    CubeFace getFace(int);
    int getCurrentFaceID();
    void setCurrentFaceID(int);

    // Solved Check
    bool isSolved();

    // Converts Cube to List of QImages
    QVector<QImage> toQImageList();

private:
    QVector<CubeFace> rotatedCubeFaces;
    QVector<CubeFace> baseCubeFaces;
    int currentFaceID = 0;

    static QVector<CubeFace> rotateToFace(QVector<CubeFace> original, int faceID);
};
#endif // CUBE_H
