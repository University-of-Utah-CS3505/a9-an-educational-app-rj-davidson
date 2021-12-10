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
    Cube(int);
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
    std::vector<CubeFace> getCube();
    int getCurrentFace();

    // Setters
    void setCurrentFace(int);

    // used to transform data in Model3DCube
    void setCube(QVector<CubeFace> newCubeFaces);

    // Solved Check
    bool isComplete();

    // Converts Cube to List of QImages
    std::vector<QImage> toQImageList();

private:
    std::vector<CubeFace> cubeFaces;
    std::vector<CubeFace> firstCross;
    std::vector<CubeFace> firstCorners;
    std::vector<CubeFace> neighbors;
    std::vector<CubeFace> oppositeCross;
    std::vector<CubeFace> finalCorners;
    int currentFace;

};
#endif // CUBE_H
