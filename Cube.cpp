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

Cube::Cube(QVector<CubeFace> &cubeFaces, bool flipBackFace){
    baseCubeFaces = cubeFaces;

//    if(flipBackFace) {
//        this->flipBackFace();
//    }

    setCurrentFaceID(0);
}

// ---------- Cube Faces ----------
void Cube::flipBackFace() {
    baseCubeFaces[5].rotateClockwise();
    baseCubeFaces[5].rotateClockwise();
    rotatedCubeFaces = rotateToFace(baseCubeFaces, currentFaceID);
}

QVector<CubeFace> Cube::getAllFaces()
{
    return rotatedCubeFaces;
}

void Cube::setCubeFaces(QVector<CubeFace> newCubeFaces, bool flipBackFace)
{
    baseCubeFaces.clear();
    for(int i=0; i<6; i++){
        baseCubeFaces.push_back(newCubeFaces.at(i));
    }

//    if(flipBackFace) {
//        this->flipBackFace();
//    }

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
    QVector<char> lRow = rotatedCubeFaces[1].getRow(0);
    QVector<char> fRow = rotatedCubeFaces[0].getRow(0);
    QVector<char> rRow = rotatedCubeFaces[3].getRow(0);
    QVector<char> bRow = rotatedCubeFaces[5].getRow(0);
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[2].rotateClockwise();
        rotatedCubeFaces[1].setRow(0, fRow);
        rotatedCubeFaces[0].setRow(0, rRow);
        rotatedCubeFaces[3].setRow(0, bRow);
        rotatedCubeFaces[5].setRow(0, lRow);
    } else {
        rotatedCubeFaces[2].rotateCounterClockwise();
        rotatedCubeFaces[1].setRow(0, bRow);
        rotatedCubeFaces[0].setRow(0, lRow);
        rotatedCubeFaces[3].setRow(0, fRow);
        rotatedCubeFaces[5].setRow(0, rRow);
    }
}

void Cube::moveD(RotationDirection dir) {
    QVector<char> lRow = rotatedCubeFaces[1].getRow(2);
    QVector<char> fRow = rotatedCubeFaces[0].getRow(2);
    QVector<char> rRow = rotatedCubeFaces[3].getRow(2);
    QVector<char> bRow = rotatedCubeFaces[5].getRow(2);
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[4].rotateClockwise();
        rotatedCubeFaces[1].setRow(2, bRow);
        rotatedCubeFaces[0].setRow(2, lRow);
        rotatedCubeFaces[3].setRow(2, fRow);
        rotatedCubeFaces[5].setRow(2, rRow);
    } else {
        rotatedCubeFaces[4].rotateCounterClockwise();
        rotatedCubeFaces[1].setRow(2, fRow);
        rotatedCubeFaces[0].setRow(2, rRow);
        rotatedCubeFaces[3].setRow(2, bRow);
        rotatedCubeFaces[5].setRow(2, lRow);
    }
}

void Cube::moveL(RotationDirection dir) {
    QVector<char> fCol = rotatedCubeFaces[0].getCol(0);
    QVector<char> dCol = rotatedCubeFaces[4].getCol(0);
    QVector<char> bCol = rotatedCubeFaces[5].getCol(2);
    QVector<char> uCol = rotatedCubeFaces[2].getCol(0);

    if(dir == CLOCKWISE) {
        rotatedCubeFaces[1].rotateClockwise();
        rotatedCubeFaces[0].setCol(0, uCol);
        rotatedCubeFaces[4].setCol(0, fCol);
        rotatedCubeFaces[5].setCol(2, dCol);
        rotatedCubeFaces[2].setCol(0, bCol);
    } else {
        rotatedCubeFaces[1].rotateCounterClockwise();
        rotatedCubeFaces[0].setCol(0, dCol);
        rotatedCubeFaces[4].setCol(0, bCol);
        rotatedCubeFaces[5].setCol(2, uCol);
        rotatedCubeFaces[2].setCol(0, fCol);
    }
}

void Cube::moveR(RotationDirection dir) {
    QVector<char> fCol = rotatedCubeFaces[0].getCol(2);
    QVector<char> dCol = rotatedCubeFaces[4].getCol(2);
    QVector<char> bCol = rotatedCubeFaces[5].getCol(0);
    QVector<char> uCol = rotatedCubeFaces[2].getCol(2);

    if(dir == CLOCKWISE) {
        rotatedCubeFaces[3].rotateClockwise();
        rotatedCubeFaces[0].setCol(2, dCol);
        rotatedCubeFaces[4].setCol(2, bCol);
        rotatedCubeFaces[5].setCol(0, uCol);
        rotatedCubeFaces[2].setCol(2, fCol);
    } else {
        rotatedCubeFaces[3].rotateCounterClockwise();
        rotatedCubeFaces[0].setCol(2, uCol);
        rotatedCubeFaces[4].setCol(2, fCol);
        rotatedCubeFaces[5].setCol(0, dCol);
        rotatedCubeFaces[2].setCol(2, bCol);
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

//    // Flip the back face for display
//    tempCubeFaces[5].rotateClockwise();
//    tempCubeFaces[5].rotateClockwise();

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

