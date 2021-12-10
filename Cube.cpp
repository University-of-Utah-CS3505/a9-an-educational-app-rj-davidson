#include "Cube.h"

Cube::Cube(int style)
{
    currentFace = 0;
    switch(style) {
        case 0:
        cubeFaces.push_back(CubeFace('g'));
        cubeFaces.push_back(CubeFace('r'));
        cubeFaces.push_back(CubeFace('y'));
        cubeFaces.push_back(CubeFace('w'));
        cubeFaces.push_back(CubeFace('o'));
        cubeFaces.push_back(CubeFace('b'));
        break;
    case 1:
        cubeFaces.push_back(CubeFace("firstCrossMainFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCrossLeftFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCrossAboveFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCrossRightFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCrossBelowFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCrossOppositeFace", 'x'));
        break;
    case 2:
        cubeFaces.push_back(CubeFace("firstCornersMainFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCornersLeftFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCornersAboveFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCornersRightFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCornersBelowFace", 'x'));
        cubeFaces.push_back(CubeFace("firstCornersOppositeFace", 'x'));
        break;
    case 3:
        cubeFaces.push_back(CubeFace("neighborRightMainFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborRightLeftFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborRightAboveFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborRightRightFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborRightBelowFace", 'x'));
        cubeFaces.push_back(CubeFace('w'));
        break;
    case 4:
        cubeFaces.push_back(CubeFace("neighborLeftMainFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborLeftLeftFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborLeftAboveFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborLeftRightFace", 'x'));
        cubeFaces.push_back(CubeFace("neighborLeftBelowFace", 'x'));
        cubeFaces.push_back(CubeFace('w'));
        break;
    case 5:
        cubeFaces.push_back(CubeFace("finalCrossMainFace", 'x'));      
        cubeFaces.push_back(CubeFace("finalCrossLeftFace", 'x'));
        cubeFaces.push_back(CubeFace("finalCrossAboveFace", 'x'));
        cubeFaces.push_back(CubeFace("finalCrossRightFace", 'x'));
        cubeFaces.push_back(CubeFace("finalCrossBelowFace", 'x'));
        cubeFaces.push_back(CubeFace('w'));
        break;
    case 6:
        cubeFaces.push_back(CubeFace("finalCornersMainFace", 'y'));
        cubeFaces.push_back(CubeFace("finalCornersLeftFace", 'g'));
        cubeFaces.push_back(CubeFace("finalCornersAboveFace", 'r'));
        cubeFaces.push_back(CubeFace("finalCornersRightFace", 'b'));
        cubeFaces.push_back(CubeFace("finalCornersBelowFace", 'o'));
        cubeFaces.push_back(CubeFace('w'));
        break;
    }
}

Cube::Cube(){
    currentFace = 0;

        cubeFaces.push_back(CubeFace('g'));
        cubeFaces.push_back(CubeFace('r'));
        cubeFaces.push_back(CubeFace('y'));
        cubeFaces.push_back(CubeFace('w'));
        cubeFaces.push_back(CubeFace('o'));
        cubeFaces.push_back(CubeFace('b'));
}

Cube::Cube(QVector<CubeFace> &newCubeFaces){
    currentFace = 0;
    for(int i=0; i<6; i++){
        cubeFaces.push_back(newCubeFaces.at(i));
    }
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
        case 7:
            topLeft();
            break;
        case 8:
            clockwiseMove();
            break;
        case 9:
            counterClockwiseMove();
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
            y2Clockwise();
            break;
        case 2: // y2
            b5Clockwise();
            break;
        case 3: // w3
            y2Clockwise();
            break;
        case 4: // o4
            g0Clockwise();
            break;
        case 5: // b5
            y2Clockwise();
            break;
        default: // g0
            y2Clockwise();
    }
}

void Cube::leftBttm()
{
    switch (currentFace)
    {
        case 1: // r1
            o4CounterClockwise();
            break;
        case 2: // y2
            g0CounterClockwise();
            break;
        case 3: // w3
            o4CounterClockwise();
            break;
        case 4: // o4
            b5CounterClockwise();
            break;
        case 5: // b5
            o4CounterClockwise();
            break;
        default: // g0
            o4CounterClockwise();
    }
}

// Bottom Controls
void Cube::bttmLeft()
{
    switch (currentFace)
    {
        case 1: // r1
            b5Clockwise();
            break;
        case 2: // y2
            r1Clockwise();
            break;
        case 3: // w3
            g0Clockwise();
            break;
        case 4: // o4
            r1Clockwise();
            break;
        case 5: // b5
            w3Clockwise();
            break;
        default: // g0
            r1Clockwise();
    }
}

void Cube::bttmRight()
{
    switch (currentFace)
    {
        case 1: // r1
            g0CounterClockwise();
            break;
        case 2: // y2
            w3CounterClockwise();
            break;
        case 3: // w3
            b5CounterClockwise();
            break;
        case 4: // o4
            w3CounterClockwise();
            break;
        case 5: // b5
            r1CounterClockwise();
            break;
        default: // g0
            w3CounterClockwise();
    }
}

// Right Controls
void Cube::rightBttm()
{
    switch (currentFace)
    {
        case 1: // r1
            o4Clockwise();
            break;
        case 2: // y2
            g0Clockwise();
            break;
        case 3: // w3
            o4Clockwise();
            break;
        case 4: // o4
            b5Clockwise();
            break;
        case 5: // b5
            o4Clockwise();
            break;
        default: // g0
            o4Clockwise();
    }
}

void Cube::rightTop()
{
    switch (currentFace)
    {
        case 1: // r1
            y2CounterClockwise();
            break;
        case 2: // y2
            b5CounterClockwise();
            break;
        case 3: // w3
            y2CounterClockwise();
            break;
        case 4: // o4
            g0CounterClockwise();
            break;
        case 5: // b5
            y2CounterClockwise();
            break;
        default: // g0
            y2CounterClockwise();
    }
}

// Top Controls
void Cube::topRight()
{
    switch (currentFace)
    {
        case 1: // r1
            g0Clockwise();
            break;
        case 2: // y2
            w3Clockwise();
            break;
        case 3: // w3
            b5Clockwise();
            break;
        case 4: // o4
            w3Clockwise();
            break;
        case 5: // b5
            r1Clockwise();
            break;
        default: // g0
            w3Clockwise();
    }
}

void Cube::topLeft()
{
    switch (currentFace)
    {
        case 1: // r1
            b5CounterClockwise();
            break;
        case 2: // y2
            r1CounterClockwise();
            break;
        case 3: // w3
            g0CounterClockwise();
            break;
        case 4: // o4
            r1CounterClockwise();
            break;
        case 5: // b5
            w3CounterClockwise();
            break;
        default: // g0
            r1CounterClockwise();
    }
}

void Cube::clockwiseMove()
{
    switch (currentFace)
    {
        case 1: // r1
            r1CounterClockwise();
            break;
        case 2: // y2
            y2CounterClockwise();
            break;
        case 3: // w3
            w3CounterClockwise();
            break;
        case 4: // o4
            o4CounterClockwise();
            break;
        case 5: // b5
            b5CounterClockwise();
            break;
        default: // g0
            g0CounterClockwise();
    }
}

void Cube::counterClockwiseMove()
{
    switch (currentFace)
    {
        case 1: // r1
            r1CounterClockwise();
            break;
        case 2: // y2
            y2CounterClockwise();
            break;
        case 3: // w3
            w3CounterClockwise();
            break;
        case 4: // o4
            o4CounterClockwise();
            break;
        case 5: // b5
            b5CounterClockwise();
            break;
        default: // g0
            g0CounterClockwise();
    }
}

// Moves
void Cube::g0Clockwise()
{
    std::vector<char> r1Temp = cubeFaces[1].getCol(2);
    std::vector<char> y2Temp = cubeFaces[2].getRow(2);
    std::reverse(y2Temp.begin(), y2Temp.end());
    std::vector<char> w3Temp = cubeFaces[3].getCol(0);
    std::reverse(w3Temp.begin(), w3Temp.end());
    std::vector<char> o4Temp = cubeFaces[4].getRow(0);

    // Set y2 row 2 to r1Temp
    cubeFaces[2].setRow(2, r1Temp);
    // Set w3 col 0 to y2Temp
    cubeFaces[3].setCol(0, y2Temp);
    // Set o4 row 0 to w3Temp
    cubeFaces[4].setRow(0, w3Temp);
    // Set r1 col 2 to o4Temp
    cubeFaces[1].setCol(2, o4Temp);
    // Rotate g0 Clockwise
    cubeFaces[0].rotateClockwise();
}

void Cube::g0CounterClockwise()
{
    std::vector<char> r1Temp = cubeFaces[1].getCol(2);
    std::vector<char> o4Temp = cubeFaces[4].getRow(0);
    std::reverse(o4Temp.begin(), o4Temp.end());
    std::vector<char> w3Temp = cubeFaces[3].getCol(0);
    std::reverse(w3Temp.begin(), w3Temp.end());
    std::vector<char> y2Temp = cubeFaces[2].getRow(2);

    // Set o4 row 0 to r1Temp
    cubeFaces[4].setRow(0, r1Temp);
    // Set w3 col 0 to o4Temp
    cubeFaces[3].setCol(0, o4Temp);
    // Set y2 row 2 to w3Temp
    cubeFaces[2].setRow(2, w3Temp);
    // Set r1 col 2 to y2Temp
    cubeFaces[1].setCol(2, y2Temp);
    // Rotate g0 Counter Clockwise
    cubeFaces[0].rotateCounterClockwise();
}

void Cube::r1Clockwise()
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
    // Rotate r1 Clockwise
    cubeFaces[1].rotateClockwise();
}

void Cube::r1CounterClockwise()
{
    std::vector<char> g0Temp = cubeFaces[0].getCol(0);
    std::vector<char> y2Temp = cubeFaces[2].getCol(0);
    std::reverse(y2Temp.begin(), y2Temp.end());
    std::vector<char> b5Temp = cubeFaces[5].getCol(2);
    std::reverse(b5Temp.begin(), b5Temp.end());
    std::vector<char> o4Temp = cubeFaces[4].getCol(0);

    // Set y2 col 0 to g0Temp
    cubeFaces[2].setCol(0, g0Temp);
    // Set b5 col 2 to y2Temp
    cubeFaces[5].setCol(2, y2Temp);
    // Set o4 col 0 to b5Temp
    cubeFaces[4].setCol(0, b5Temp);
    // Set g0 col 0 to o4Temp
    cubeFaces[0].setCol(0, o4Temp);
    // Rotate r1 Counter Clockwise
    cubeFaces[1].rotateCounterClockwise();
}

void Cube::y2CounterClockwise()
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
    // Rotate y2 Counter Clockwise
    cubeFaces[2].rotateCounterClockwise();
}

void Cube::y2Clockwise()
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
    // Rotate y2 Clockwise
    cubeFaces[2].rotateClockwise();
}

void Cube::w3Clockwise()
{
    std::vector<char> g0Temp = cubeFaces[0].getCol(2);
    std::vector<char> y2Temp = cubeFaces[2].getCol(2);
    std::reverse(y2Temp.begin(), y2Temp.end());
    std::vector<char> b5Temp = cubeFaces[5].getCol(0);
    std::reverse(b5Temp.begin(), b5Temp.end());
    std::vector<char> o4Temp = cubeFaces[4].getCol(2);

    // Set y2 col 2 to g0Temp
    cubeFaces[2].setCol(2, g0Temp);
    // Set b5 col 0 to y2Temp
    cubeFaces[5].setCol(0, y2Temp);
    // Set o4 col 2 to b5Temp
    cubeFaces[4].setCol(2, b5Temp);
    // Set g0 col 2 to o4Temp
    cubeFaces[0].setCol(2, o4Temp);
    // Rotate w3 Clockwise
    cubeFaces[3].rotateClockwise();
}

void Cube::w3CounterClockwise()
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
    // Rotate w3 Counter Clockwise
    cubeFaces[3].rotateCounterClockwise();
}

void Cube::o4Clockwise()
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
    // Rotate o4 Clockwise
    cubeFaces[4].rotateClockwise();
}

void Cube::o4CounterClockwise()
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
    // Rotate 04 Counter Clockwise
    cubeFaces[4].rotateCounterClockwise();
}

void Cube::b5Clockwise()
{
    std::vector<char> r1Temp = cubeFaces[1].getCol(0);
    std::vector<char> o4Temp = cubeFaces[4].getRow(2);
    std::reverse(o4Temp.begin(), o4Temp.end());
    std::vector<char> w3Temp = cubeFaces[3].getCol(2);
    std::reverse(w3Temp.begin(), w3Temp.end());
    std::vector<char> y2Temp = cubeFaces[2].getRow(0);

    // Set o4 row 2 to r1Temp
    cubeFaces[4].setRow(2, r1Temp);
    // Set w3 col 2 to o4Temp
    cubeFaces[3].setCol(2, o4Temp);
    // Set y2 row 0 to w3Temp
    cubeFaces[2].setRow(0, w3Temp);
    // Set r1 col 0 to y2Temp
    cubeFaces[1].setCol(0, y2Temp);
    // Rotate b5 Clockwise
    cubeFaces[5].rotateClockwise();
}

void Cube::b5CounterClockwise()
{
    std::vector<char> r1Temp = cubeFaces[1].getCol(0);
    std::vector<char> y2Temp = cubeFaces[2].getRow(0);
    std::reverse(y2Temp.begin(), y2Temp.end());
    std::vector<char> w3Temp = cubeFaces[3].getCol(2);
    std::reverse(w3Temp.begin(), w3Temp.end());
    std::vector<char> o4Temp = cubeFaces[4].getRow(2);

    // Set y2 row 0 to r1Temp
    cubeFaces[2].setRow(0, r1Temp);
    // Set w3 col 2 to y2Temp
    cubeFaces[3].setCol(2, y2Temp);
    // Set o4 row 2 to w3Temp
    cubeFaces[4].setRow(2, w3Temp);
    // Set r1 col 0 to o4Temp
    cubeFaces[1].setCol(0, o4Temp);
    // Rotate b5 Counter Clockwise
    cubeFaces[5].rotateCounterClockwise();
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

void Cube::setCube(QVector<CubeFace> newCubeFaces)
{
    cubeFaces.clear();
    for(int i=0; i<6; i++){
        cubeFaces.push_back(newCubeFaces.at(i));
    }
}

int Cube::getCurrentFace()
{
    return currentFace;
}

// Setters
void Cube::setCurrentFace(int num)
{
    currentFace = num;
}

// Solved Check
bool Cube::isComplete()
{
    for(CubeFace f : cubeFaces)
        if (!f.complete())
            return false;
    return true;
}

// Converts Cube to List of QImages
std::vector<QImage> Cube::toQImageList()
{
    std::vector<CubeFace> tempCubeFaces;
    switch (currentFace)
    {
    case 1:
        tempCubeFaces.push_back(cubeFaces[1]);
        tempCubeFaces.push_back(cubeFaces[5]);
        tempCubeFaces.push_back(cubeFaces[2]);
        tempCubeFaces.push_back(cubeFaces[0]);
        tempCubeFaces.push_back(cubeFaces[4]);
        tempCubeFaces.push_back(cubeFaces[3]);
        tempCubeFaces[2].rotateCounterClockwise();
        tempCubeFaces[4].rotateClockwise();
        break;
    case 2:
        tempCubeFaces.push_back(cubeFaces[2]);
        tempCubeFaces.push_back(cubeFaces[1]);
        tempCubeFaces.push_back(cubeFaces[5]);
        tempCubeFaces.push_back(cubeFaces[3]);
        tempCubeFaces.push_back(cubeFaces[0]);
        tempCubeFaces.push_back(cubeFaces[4]);
        tempCubeFaces[1].rotateClockwise();
        tempCubeFaces[3].rotateCounterClockwise();
        tempCubeFaces[4].rotateCounterClockwise();
        tempCubeFaces[4].rotateCounterClockwise();
        tempCubeFaces[5].rotateCounterClockwise();
        tempCubeFaces[5].rotateCounterClockwise();
        break;
    case 3:
        tempCubeFaces.push_back(cubeFaces[3]);
        tempCubeFaces.push_back(cubeFaces[0]);
        tempCubeFaces.push_back(cubeFaces[2]);
        tempCubeFaces.push_back(cubeFaces[5]);
        tempCubeFaces.push_back(cubeFaces[4]);
        tempCubeFaces.push_back(cubeFaces[1]);
        tempCubeFaces[2].rotateClockwise();
        tempCubeFaces[4].rotateCounterClockwise();
        break;
    case 4:
        tempCubeFaces.push_back(cubeFaces[4]);
        tempCubeFaces.push_back(cubeFaces[1]);
        tempCubeFaces.push_back(cubeFaces[0]);
        tempCubeFaces.push_back(cubeFaces[3]);
        tempCubeFaces.push_back(cubeFaces[5]);
        tempCubeFaces.push_back(cubeFaces[2]);
        tempCubeFaces[1].rotateCounterClockwise();
        tempCubeFaces[2].rotateClockwise();
        tempCubeFaces[2].rotateClockwise();
        tempCubeFaces[3].rotateClockwise();
        tempCubeFaces[5].rotateClockwise();
        tempCubeFaces[5].rotateClockwise();
        break;
    case 5:
        tempCubeFaces.push_back(cubeFaces[5]);
        tempCubeFaces.push_back(cubeFaces[3]);
        tempCubeFaces.push_back(cubeFaces[2]);
        tempCubeFaces.push_back(cubeFaces[1]);
        tempCubeFaces.push_back(cubeFaces[4]);
        tempCubeFaces.push_back(cubeFaces[0]);
        tempCubeFaces[2].rotateClockwise();
        tempCubeFaces[2].rotateClockwise();
        tempCubeFaces[4].rotateClockwise();
        tempCubeFaces[4].rotateClockwise();
        break;
    default:
        tempCubeFaces = cubeFaces;
    }

    std::vector<QImage> list;
    for (CubeFace f : tempCubeFaces)
        list.push_back(f.toQImage());
    return list;
}
