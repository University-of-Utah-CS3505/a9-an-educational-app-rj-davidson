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

void Cube::move(int moveID)
{
    switch (moveID)
    {
        case 0:
            leftTop();
            break;
        case 1:
            leftMid();
            break;
        case 2:
            leftBttm();
            break;
        case 3:
            bttmLeft();
            break;
        case 4:
            bttmMid();
            break;
        case 5:
            bttmRight();
            break;
        case 6:
            rightBttm();
            break;
        case 7:
            rightMid();
            break;
        case 8:
            rightTop();
            break;
        case 9:
            topRight();
            break;
        case 10:
            topMid();
            break;
        default:
            topLeft();
    }
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

// Converts Cube to List of QImages
std::vector<QImage> Cube::toQImageList()
{
    std::vector<QImage> list;
    for (CubeFace f : cubeFaces)
        list.push_back(f.toQImage());
    return list;
}
