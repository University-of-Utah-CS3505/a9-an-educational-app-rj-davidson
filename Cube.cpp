#include "Cube.h"

Cube::Cube()
{
    currentFace = 0;

    cubeFaces.push_back(CubeFace('g'));
    cubeFaces.push_back(CubeFace('r'));
    cubeFaces.push_back(CubeFace('y'));
    cubeFaces.push_back(CubeFace('w'));
    cubeFaces.push_back(CubeFace('o'));
    cubeFaces.push_back(CubeFace('b'));
}

// Left Controls
void Cube::leftTop()
{

}

void Cube::leftMid()
{

}

void Cube::leftBttm()
{

}

// Right Controls
void Cube::rightTop()
{

}

void Cube::rightMid()
{

}

void Cube::rightBttm()
{

}

// Bottom Controls
void Cube::bttmLeft()
{

}

void Cube::bttmMid()
{

}

void Cube::bttmRight()
{

}

// Top Controls
void Cube::topLeft()
{

}

void Cube::topMid()
{

}

void Cube::topRight()
{

}

// Getters
CubeFace Cube::getFace(int i)
{
    return cubeFaces[i];
}

std::vector<CubeFace> Cube::getCube()
{
    return cubeFaces;
}

// Setters
void Cube::setCurrentFace(int num)
{
    currentFace = num;
}

// Solved Check
bool Cube::solved()
{
    for(CubeFace f : cubeFaces)
        if (!f.complete())
            return false;
    return true;
}
