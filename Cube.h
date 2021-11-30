// Linked to the Model

#ifndef CUBE_H
#define CUBE_H

#include "CubeFace.h"
#include <vector>

class Cube
{
public:
    Cube();

    // Left Controls
    void leftTop();
    void leftMid();
    void leftBttm();

    // Right Controls
    void rightTop();
    void rightMid();
    void rightBttm();

    // Bottom Controls
    void bttmLeft();
    void bttmMid();
    void bttmRight();

    // Top Controls
    void topLeft();
    void topMid();
    void topRight();

    // Getters
    void getFace(int); //TODO: Shoudl this return a CubeFace object?
    void getCube();

private:
    std::vector<CubeFace> cubeFaces;
};
#endif // CUBE_H
