// Linked to the Model

#ifndef CUBE_H
#define CUBE_H

#include "CubeFace.h"
#include <vector>
#include <QImage>

class Cube
{
public:
    Cube();

    void move(int);

    // Left Controls
    void leftTop();
    void leftMid();
    void leftBttm();

    // Bottom Controls
    void bttmLeft();
    void bttmMid();
    void bttmRight();

    // Right Controls
    void rightBttm();
    void rightMid();
    void rightTop();

    // Top Controls
    void topRight();
    void topMid();
    void topLeft();

    // Getters
    CubeFace getFace(int); //TODO: Shoudl this return a CubeFace object?
    std::vector<CubeFace> getCube();

    // Setters
    void setCurrentFace(int);

    // Solved Check
    bool solved();

    // Converts Cube to List of QImages
    std::vector<QImage> toQImageList();

private:
    std::vector<CubeFace> cubeFaces;
    int currentFace;
};
#endif // CUBE_H
