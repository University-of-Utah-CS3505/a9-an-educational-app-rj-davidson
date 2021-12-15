#include "Cube.h"

Cube::Cube(){
    currentFaceID = 0;

        cubeFaces.push_back(CubeFace('g'));
        cubeFaces.push_back(CubeFace('r'));
        cubeFaces.push_back(CubeFace('y'));
        cubeFaces.push_back(CubeFace('w'));
        cubeFaces.push_back(CubeFace('o'));
        cubeFaces.push_back(CubeFace('b'));
}

Cube::Cube(QVector<CubeFace> &cubeFaces){
    currentFaceID = 0;
    this->cubeFaces = cubeFaces;
}

// ---------- Cube Faces ----------
QVector<CubeFace> Cube::getAllFaces()
{
    return cubeFaces;
}

void Cube::setCubeFaces(QVector<CubeFace> newCubeFaces)
{
    cubeFaces.clear();
    for(int i=0; i<6; i++){
        cubeFaces.push_back(newCubeFaces.at(i));
    }
}

CubeFace Cube::getFace(int i)
{
    return cubeFaces[i];
}

int Cube::getCurrentFaceID()
{
    return currentFaceID;
}

void Cube::setCurrentFaceID(int num)
{
    currentFaceID = num;
}

// ------------ Moves ---------
void Cube::moveF(RotationDirection dir) {
    if(dir == CLOCKWISE) {

    } else {

    }
}

void Cube::moveU(RotationDirection dir) {
    if(dir == CLOCKWISE) {

    } else {

    }
}

void Cube::moveD(RotationDirection dir) {
    if(dir == CLOCKWISE) {

    } else {

    }
}

void Cube::moveL(RotationDirection dir) {
    if(dir == CLOCKWISE) {

    } else {

    }
}

void Cube::moveR(RotationDirection dir) {
    if(dir == CLOCKWISE) {

    } else {

    }
}


// ----------- Solve Function --------
bool Cube::isSolved()
{
    for(CubeFace f : cubeFaces)
        if (!f.complete())
            return false;
    return true;
}

// -------- Converters -----------
QVector<QImage> Cube::toQImageList()
{
    QVector<CubeFace> tempCubeFaces = rotateToFace(cubeFaces, currentFaceID);
    QVector<QImage> list;
    for (CubeFace f : tempCubeFaces)
        list.push_back(f.toQImage());
    return list;
}

QVector<CubeFace> Cube::rotateToFace(QVector<CubeFace> original, int faceID) {
    QVector<CubeFace> rotatedCubeFaces;
    switch (faceID)
    {
    case 0:
        rotatedCubeFaces = original;
        break;
    case 1:
        rotatedCubeFaces.push_back(original[1]);
        rotatedCubeFaces.push_back(original[5]);
        rotatedCubeFaces.push_back(original[2]);
        rotatedCubeFaces.push_back(original[0]);
        rotatedCubeFaces.push_back(original[4]);
        rotatedCubeFaces.push_back(original[3]);
        rotatedCubeFaces[2].rotateCounterClockwise();
        rotatedCubeFaces[4].rotateClockwise();
        break;
    case 2:
        rotatedCubeFaces.push_back(original[2]);
        rotatedCubeFaces.push_back(original[1]);
        rotatedCubeFaces.push_back(original[5]);
        rotatedCubeFaces.push_back(original[3]);
        rotatedCubeFaces.push_back(original[0]);
        rotatedCubeFaces.push_back(original[4]);
        rotatedCubeFaces[1].rotateClockwise();
        rotatedCubeFaces[3].rotateCounterClockwise();
        rotatedCubeFaces[5].rotateCounterClockwise();
        rotatedCubeFaces[5].rotateCounterClockwise();
        rotatedCubeFaces[2].rotateCounterClockwise();
        rotatedCubeFaces[2].rotateCounterClockwise();
        break;
    case 3:
        rotatedCubeFaces.push_back(original[3]);
        rotatedCubeFaces.push_back(original[0]);
        rotatedCubeFaces.push_back(original[2]);
        rotatedCubeFaces.push_back(original[5]);
        rotatedCubeFaces.push_back(original[4]);
        rotatedCubeFaces.push_back(original[1]);
        rotatedCubeFaces[2].rotateClockwise();
        rotatedCubeFaces[4].rotateCounterClockwise();
        break;
    case 4:
        rotatedCubeFaces.push_back(original[4]);
        rotatedCubeFaces.push_back(original[1]);
        rotatedCubeFaces.push_back(original[0]);
        rotatedCubeFaces.push_back(original[3]);
        rotatedCubeFaces.push_back(original[5]);
        rotatedCubeFaces.push_back(original[2]);
        rotatedCubeFaces[1].rotateCounterClockwise();
        rotatedCubeFaces[5].rotateClockwise();
        rotatedCubeFaces[5].rotateClockwise();
        rotatedCubeFaces[3].rotateClockwise();
        rotatedCubeFaces[4].rotateClockwise();
        rotatedCubeFaces[4].rotateClockwise();
        break;
    case 5:
        rotatedCubeFaces.push_back(original[5]);
        rotatedCubeFaces.push_back(original[3]);
        rotatedCubeFaces.push_back(original[2]);
        rotatedCubeFaces.push_back(original[1]);
        rotatedCubeFaces.push_back(original[4]);
        rotatedCubeFaces.push_back(original[0]);
        rotatedCubeFaces[2].rotateClockwise();
        rotatedCubeFaces[2].rotateClockwise();
        rotatedCubeFaces[4].rotateClockwise();
        rotatedCubeFaces[4].rotateClockwise();
        break;
    default:
        qDebug() << "Invalid cube face ID";
    }

    return rotatedCubeFaces;
}

