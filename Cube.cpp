#include "Cube.h"

Cube::Cube(){
    baseCubeFaces.push_back(CubeFace('g'));
    baseCubeFaces.push_back(CubeFace('r'));
    baseCubeFaces.push_back(CubeFace('y'));
    baseCubeFaces.push_back(CubeFace('w'));
    baseCubeFaces.push_back(CubeFace('o'));
    baseCubeFaces.push_back(CubeFace('b'));
    setCurrentFaceID(0);
}

Cube::Cube(QVector<CubeFace> &cubeFaces){
    this->baseCubeFaces = cubeFaces;
    setCurrentFaceID(0);
}

// ---------- Cube Faces ----------
QVector<CubeFace> Cube::getAllFaces()
{
    return rotatedCubeFaces;
}

void Cube::setCubeFaces(QVector<CubeFace> newCubeFaces)
{
    baseCubeFaces.clear();
    for(int i=0; i<6; i++){
        baseCubeFaces.push_back(newCubeFaces.at(i));
    }
    setCurrentFaceID(0);
}

CubeFace Cube::getFace(int i)
{
    return rotatedCubeFaces[i];
}

int Cube::getCurrentFaceID()
{
    return currentFaceID;
}

void Cube::setCurrentFaceID(int num)
{
    rotatedCubeFaces = rotateToFace(baseCubeFaces, num);
    currentFaceID = num;
}

// ------------ Moves ---------
void Cube::moveF(RotationDirection dir) {
    QVector<char> lCol = rotatedCubeFaces[1].getCol(2);
    std::reverse(lCol.begin(), lCol.end());
    QVector<char> uRow = rotatedCubeFaces[2].getRow(2);
    QVector<char> rCol = rotatedCubeFaces[3].getCol(0);
    std::reverse(rCol.begin(), rCol.end());
    QVector<char> dRow = rotatedCubeFaces[4].getRow(0);

    if(dir == CLOCKWISE) {
        rotatedCubeFaces[0].rotateClockwise();
        rotatedCubeFaces[1].setCol(2, dRow);
        rotatedCubeFaces[2].setRow(2, lCol);
        rotatedCubeFaces[3].setCol(0, uRow);
        rotatedCubeFaces[4].setRow(0, rCol);
    } else {
        rotatedCubeFaces[0].rotateCounterClockwise();
        rotatedCubeFaces[1].setCol(2, uRow);
        rotatedCubeFaces[2].setRow(2, rCol);
        rotatedCubeFaces[3].setCol(0, dRow);
        rotatedCubeFaces[4].setRow(0, lCol);
    }
}

void Cube::moveU(RotationDirection dir) {
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[2].rotateClockwise();
    } else {
        rotatedCubeFaces[2].rotateCounterClockwise();
    }
}

void Cube::moveD(RotationDirection dir) {
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[4].rotateClockwise();
    } else {
        rotatedCubeFaces[4].rotateCounterClockwise();
    }
}

void Cube::moveL(RotationDirection dir) {
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[1].rotateClockwise();
    } else {
        rotatedCubeFaces[1].rotateCounterClockwise();
    }
}

void Cube::moveR(RotationDirection dir) {
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[3].rotateClockwise();
    } else {
        rotatedCubeFaces[3].rotateCounterClockwise();
    }
}


// ----------- Solve Function --------
bool Cube::isSolved()
{
    for(CubeFace f : rotatedCubeFaces)
        if (!f.complete())
            return false;
    return true;
}

// -------- Converters -----------
QVector<QImage> Cube::toQImageList()
{
    QVector<CubeFace> tempCubeFaces = rotatedCubeFaces;
    QVector<QImage> list;
    for (CubeFace f : tempCubeFaces)
        list.push_back(f.toQImage());
    return list;
}

QVector<CubeFace> Cube::rotateToFace(QVector<CubeFace> original, int faceID) {
    QVector<CubeFace> cubeFaces;
    switch (faceID)
    {
    case 0:
        cubeFaces = original;
        break;
    case 1:
        cubeFaces.push_back(original[1]);
        cubeFaces.push_back(original[5]);
        cubeFaces.push_back(original[2]);
        cubeFaces.push_back(original[0]);
        cubeFaces.push_back(original[4]);
        cubeFaces.push_back(original[3]);
        cubeFaces[2].rotateCounterClockwise();
        cubeFaces[4].rotateClockwise();
        break;
    case 2:
        cubeFaces.push_back(original[2]);
        cubeFaces.push_back(original[1]);
        cubeFaces.push_back(original[5]);
        cubeFaces.push_back(original[3]);
        cubeFaces.push_back(original[0]);
        cubeFaces.push_back(original[4]);
        cubeFaces[1].rotateClockwise();
        cubeFaces[3].rotateCounterClockwise();
        cubeFaces[5].rotateCounterClockwise();
        cubeFaces[5].rotateCounterClockwise();
        cubeFaces[2].rotateCounterClockwise();
        cubeFaces[2].rotateCounterClockwise();
        break;
    case 3:
        cubeFaces.push_back(original[3]);
        cubeFaces.push_back(original[0]);
        cubeFaces.push_back(original[2]);
        cubeFaces.push_back(original[5]);
        cubeFaces.push_back(original[4]);
        cubeFaces.push_back(original[1]);
        cubeFaces[2].rotateClockwise();
        cubeFaces[4].rotateCounterClockwise();
        break;
    case 4:
        cubeFaces.push_back(original[4]);
        cubeFaces.push_back(original[1]);
        cubeFaces.push_back(original[0]);
        cubeFaces.push_back(original[3]);
        cubeFaces.push_back(original[5]);
        cubeFaces.push_back(original[2]);
        cubeFaces[1].rotateCounterClockwise();
        cubeFaces[5].rotateClockwise();
        cubeFaces[5].rotateClockwise();
        cubeFaces[3].rotateClockwise();
        cubeFaces[4].rotateClockwise();
        cubeFaces[4].rotateClockwise();
        break;
    case 5:
        cubeFaces.push_back(original[5]);
        cubeFaces.push_back(original[3]);
        cubeFaces.push_back(original[2]);
        cubeFaces.push_back(original[1]);
        cubeFaces.push_back(original[4]);
        cubeFaces.push_back(original[0]);
        cubeFaces[2].rotateClockwise();
        cubeFaces[2].rotateClockwise();
        cubeFaces[4].rotateClockwise();
        cubeFaces[4].rotateClockwise();
        break;
    default:
        qDebug() << "Invalid cube face ID";
    }

    return cubeFaces;
}

