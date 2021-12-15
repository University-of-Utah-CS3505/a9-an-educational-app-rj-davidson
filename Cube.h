// Linked to the Model

#ifndef CUBE_H
#define CUBE_H

#include "CubeFace.h"
#include <vector>
#include <QImage>
#include <algorithm>

class Cube
{
public:
    Cube();
    Cube(QVector<CubeFace> &newCubeFaces);//used for Model3DView

    void move(int);

    // Left Controls
    void leftTop();
    void leftBttm();

    // Bottom Controls
    void bttmLeft();
    void bttmRight();

    // Right Controls
    void rightBttm();
    void rightTop();

    // Top Controls
    void topRight();
    void topLeft();

    // Rotation Controls
    void counterClockwiseMove();
    void clockwiseMove();

    // Moves
    void g0Clockwise();
    void g0CounterClockwise();
    void r1Clockwise();
    void r1CounterClockwise();
    void y2Clockwise();
    void y2CounterClockwise();
    void w3Clockwise();
    void w3CounterClockwise();
    void o4Clockwise();
    void o4CounterClockwise();
    void b5Clockwise();
    void b5CounterClockwise();

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

};
#endif // CUBE_H
