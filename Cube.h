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

    // Moves
    void move1();
    void move2();
    void move3();
    void move4();
    void move5();
    void move6();
    void move7();
    void move8();
    void move9();
    void move10();
    void move11();
    void move12();

    // Getters
    CubeFace getFace(int); //TODO: Should this return a CubeFace object?
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
