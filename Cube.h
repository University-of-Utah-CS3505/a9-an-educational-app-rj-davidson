/*
 * Lacking Ideas - Rubiks Educational App
 * CS 3505 - A9 - An Education App
 * @authors: Robert Davidson
 *           Orion Santiago
 *           Ronnie Koe
 *           Maiko Tuitupou
 *           Elizabeth Thomas
 *           Alex Gill
 * Cube.h
*/

#ifndef CUBE_H
#define CUBE_H

#include "CubeFace.h"
#include <vector>
#include <QImage>
#include <algorithm>

// Which direction the cube is being rotated
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

    // Setter
    void setCubeFaces(QVector<CubeFace> newCubeFaces, bool flipBackFace);

    void flipBackFace();

    // Moves/rotations
    void moveF(RotationDirection dir);
    void moveU(RotationDirection dir);
    void moveD(RotationDirection dir);
    void moveL(RotationDirection dir);
    void moveR(RotationDirection dir);

    // Getters
    Cube getBaseCube();
    QVector<CubeFace> getAllFaces();
    CubeFace getFace(int);
    int getCurrentFaceID();
    void setCurrentFaceID(int);

    // Solved Check
    bool isSolved();
    void setSolverFunction(std::function<bool(Cube)>);

    // Converts Cube to List of QImages
    QVector<QImage> toQImageList();

private:
    QVector<CubeFace> rotatedCubeFaces;
    QVector<CubeFace> coreCubeFaces;

    int currentFaceID = 0;
    std::function<bool(Cube)> cubeSolverFunc = [](Cube c) -> bool {
        for(CubeFace face : c.coreCubeFaces) {
            if(!face.complete()) {
                return false;
            }
        }
        return true;
    };

    static QVector<CubeFace> convertCoreToRotated(QVector<CubeFace> original, int targetFaceID);
    static QVector<CubeFace> convertRotatedToCore(QVector<CubeFace> rotated, int currentFaceID);
};
#endif // CUBE_H
