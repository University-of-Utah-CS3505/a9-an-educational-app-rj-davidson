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

void Cube::move(int rotationID)
{
    switch (rotationID)
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
    switch (currentFace)
    {
        case 1: // r1
            move1();
            break;
        case 2: // y2
            move9();
            break;
        case 3: // w3
            move1();
            break;
        case 4: // o4
            move11();
            break;
        case 5: // b5
            move1();
            break;
        default: // g0
            move1();
    }
}

void Cube::leftBttm()
{
    switch (currentFace)
    {
        case 1: // r1
            move2();
            break;
        case 2: // y2
            move10();
            break;
        case 3: // w3
            move2();
            break;
        case 4: // o4
            move12();
            break;
        case 5: // b5
            move2();
            break;
        default: // g0
            move2();
    }
}

// Bottom Controls
void Cube::bttmLeft()
{
    switch (currentFace)
    {
        case 1: // r1
            move9();
            break;
        case 2: // y2
            move3();
            break;
        case 3: // w3
            move11();
            break;
        case 4: // o4
            move3();
            break;
        case 5: // b5
            move7();
            break;
        default: // g0
            move3();
    }
}

void Cube::bttmRight()
{
    switch (currentFace)
    {
        case 1: // r1
            move10();
            break;
        case 2: // y2
            move4();
            break;
        case 3: // w3
            move12();
            break;
        case 4: // o4
            move4();
            break;
        case 5: // b5
            move8();
            break;
        default: // g0
            move4();
    }
}

// Right Controls
void Cube::rightBttm()
{
    switch (currentFace)
    {
        case 1: // r1
            move5();
            break;
        case 2: // y2
            move11();
            break;
        case 3: // w3
            move5();
            break;
        case 4: // o4
            move9();
            break;
        case 5: // b5
            move5();
            break;
        default: // g0
            move5();
    }
}

void Cube::rightTop()
{
    switch (currentFace)
    {
        case 1: // r1
            move6();
            break;
        case 2: // y2
            move12();
            break;
        case 3: // w3
            move6();
            break;
        case 4: // o4
            move10();
            break;
        case 5: // b5
            move6();
            break;
        default: // g0
            move6();
    }
}

// Top Controls
void Cube::topRight()
{
    switch (currentFace)
    {
        case 1: // r1
            move11();
            break;
        case 2: // y2
            move7();
            break;
        case 3: // w3
            move9();
            break;
        case 4: // o4
            move7();
            break;
        case 5: // b5
            move3();
            break;
        default: // g0
            move7();
    }
}

void Cube::topLeft()
{
    switch (currentFace)
    {
        case 1: // r1
            move12();
            break;
        case 2: // y2
            move8();
            break;
        case 3: // w3
            move10();
            break;
        case 4: // o4
            move8();
            break;
        case 5: // b5
            move4();
            break;
        default: // g0
            move8();
    }
}

// Moves
void Cube::move1()
{

}

void Cube::move2()
{

}

void Cube::move3()
{

}

void Cube::move4()
{

}

void Cube::move5()
{

}

void Cube::move6()
{

}

void Cube::move7()
{

}

void Cube::move8()
{

}

void Cube::move9()
{

}

void Cube::move10()
{

}

void Cube::move11()
{

}

void Cube::move12()
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
