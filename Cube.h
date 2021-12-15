// Linked to the Model

#ifndef CUBE_H
#define CUBE_H

#include "CubeFace.h"
#include <vector>
#include <QImage>
#include <algorithm>

enum RotationDirection
{
    CLOCKWISE,
    COUNTERCLOCKWISE
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

    Cube getBaseCube();
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
    QVector<CubeFace> coreCubeFaces;

    int currentFaceID = 0;

    static QVector<CubeFace> convertCoreToRotated(QVector<CubeFace> original, int targetFaceID);
    static QVector<CubeFace> convertRotatedToCore(QVector<CubeFace> rotated, int currentFaceID);
};
#endif // CUBE_H
