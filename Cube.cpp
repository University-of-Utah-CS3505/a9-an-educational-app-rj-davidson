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
    std::vector<char> g0Temp = cubeFaces[0].getRow(0);
    std::vector<char> r1Temp = cubeFaces[1].getRow(0);
    std::vector<char> b5Temp = cubeFaces[5].getRow(0);
    std::vector<char> w3Temp = cubeFaces[3].getRow(0);

    // Set r1 row 0 to g0Temp
    cubeFaces[1].setRow(0, g0Temp);
    // Set b5 row 0 to r1Temp
    cubeFaces[5].setRow(0, r1Temp);
    // Set w3 row 0 to b5Temp
    cubeFaces[3].setRow(0, b5Temp);
    // Set g0 row 0 to w3Temp
    cubeFaces[0].setRow(0, w3Temp);
}

void Cube::move2()
{
    std::vector<char> g0Temp = cubeFaces[0].getRow(2);
    std::vector<char> r1Temp = cubeFaces[1].getRow(2);
    std::vector<char> b5Temp = cubeFaces[5].getRow(2);
    std::vector<char> w3Temp = cubeFaces[3].getRow(2);

    // Set r1 row 2 to g0Temp
    cubeFaces[1].setRow(2, g0Temp);
    // Set b5 row 2 to r1Temp
    cubeFaces[5].setRow(2, r1Temp);
    // Set w3 row 2 to b5Temp
    cubeFaces[3].setRow(2, b5Temp);
    // Set g0 row 2 to w3Temp
    cubeFaces[0].setRow(2, w3Temp);
}

void Cube::move3()
{
    std::vector<char> g0Temp = cubeFaces[0].getCol(0);
    std::vector<char> o4Temp = cubeFaces[4].getCol(0);
    std::reverse(o4Temp.begin(), o4Temp.end());
    std::vector<char> b5Temp = cubeFaces[5].getCol(2);
    std::reverse(b5Temp.begin(), b5Temp.end());
    std::vector<char> y2Temp = cubeFaces[2].getCol(0);

    // Set o4 col 0 to g0Temp
    cubeFaces[4].setCol(0, g0Temp);
    // Set b5 col 2 to o4Temp
    cubeFaces[5].setCol(2, o4Temp);
    // Set y2 col 0 to b5Temp
    cubeFaces[2].setCol(0, b5Temp);
    // Set g0 col 0 to y2Temp
    cubeFaces[0].setCol(0, y2Temp);
}

void Cube::move4()
{
    std::vector<char> g0Temp = cubeFaces[0].getCol(2);
    std::vector<char> o4Temp = cubeFaces[4].getCol(2);
    std::reverse(o4Temp.begin(), o4Temp.end());
    std::vector<char> b5Temp = cubeFaces[5].getCol(0);
    std::reverse(b5Temp.begin(), b5Temp.end());
    std::vector<char> y2Temp = cubeFaces[2].getCol(2);

    // Set o4 col 2 to g0Temp
    cubeFaces[4].setCol(2, g0Temp);
    // Set b5 col 0 to o4Temp
    cubeFaces[5].setCol(0, o4Temp);
    // Set y2 col 2 to b5Temp
    cubeFaces[2].setCol(2, b5Temp);
    // Set g0 col 2 to y2Temp
    cubeFaces[0].setCol(2, y2Temp);
}

void Cube::move5()
{
    std::vector<char> g0Temp = cubeFaces[0].getRow(2);
    std::vector<char> w3Temp = cubeFaces[3].getRow(2);
    std::vector<char> b5Temp = cubeFaces[5].getRow(2);
    std::vector<char> r1Temp = cubeFaces[1].getRow(2);

    // Set w3 row 2 to g0Temp
    cubeFaces[3].setRow(2, g0Temp);
    // Set b5 row 2 to w3Temp
    cubeFaces[5].setRow(2, w3Temp);
    // Set r1 row 2 to b5Temp
    cubeFaces[1].setRow(2, b5Temp);
    // Set g0 row 2 to r1Temp
    cubeFaces[0].setRow(2, r1Temp);
}

void Cube::move6()
{
    std::vector<char> g0Temp = cubeFaces[0].getRow(0);
    std::vector<char> w3Temp = cubeFaces[3].getRow(0);
    std::vector<char> b5Temp = cubeFaces[5].getRow(0);
    std::vector<char> r1Temp = cubeFaces[1].getRow(0);

    // Set w3 row 2 to g0Temp
    cubeFaces[3].setRow(0, g0Temp);
    // Set b5 row 2 to w3Temp
    cubeFaces[5].setRow(0, w3Temp);
    // Set r1 row 2 to b5Temp
    cubeFaces[1].setRow(0, b5Temp);
    // Set g0 row 2 to r1Temp
    cubeFaces[0].setRow(0, r1Temp);
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
