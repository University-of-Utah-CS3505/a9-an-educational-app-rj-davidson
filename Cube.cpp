#include "Cube.h"

Cube::Cube(){
    currentFace = 0;

        cubeFaces.push_back(CubeFace('g'));
        cubeFaces.push_back(CubeFace('r'));
        cubeFaces.push_back(CubeFace('y'));
        cubeFaces.push_back(CubeFace('w'));
        cubeFaces.push_back(CubeFace('o'));
        cubeFaces.push_back(CubeFace('b'));
}

/*
 *
 *this is a method for the 3d cube so that the converted copy of the data
 *can be stored in the 3d cube model
 *
*/
Cube::Cube(QVector<CubeFace> &newCubeFaces){
    currentFace = 0;
    for(int i=0; i<6; i++){
        cubeFaces.push_back(newCubeFaces.at(i));
    }
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

// Getters
CubeFace Cube::getFace(int i)
{
    return cubeFaces[i];
}

QVector<CubeFace> Cube::getCube()
{
    return cubeFaces;
}

/*
 * Allows cube data to be set from a list of faces. Used to store data for the 3d cube model
 */
void Cube::setCubeFaces(QVector<CubeFace> newCubeFaces)
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
QVector<QImage> Cube::toQImageList()
{
    QVector<CubeFace> tempCubeFaces = rotateToFace(cubeFaces, currentFace);
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

