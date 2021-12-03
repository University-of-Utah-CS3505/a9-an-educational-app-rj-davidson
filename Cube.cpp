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
            leftBttm();
            break;
        case 2:
            bttmLeft();
            break;
        case 3:
            bttmRight();
            break;
        case 4:
            rightBttm();
            break;
        case 5:
            rightTop();
            break;
        case 6:
            topRight();
            break;
        default:
            topLeft();
    }
}

// Left Controls
void Cube::leftTop()
{

}

void Cube::leftBttm()
{

}

// Right Controls
void Cube::rightTop()
{

}

void Cube::rightBttm()
{

}

// Bottom Controls
void Cube::bttmLeft()
{

}

void Cube::bttmRight()
{

}

// Top Controls
void Cube::topLeft()
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
