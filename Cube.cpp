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
    QVector<CubeFace> tempCubeFaces;
    switch (currentFace)
    {
    case 0:
        tempCubeFaces = cubeFaces;
        break;
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
        tempCubeFaces[5].rotateCounterClockwise();
        tempCubeFaces[5].rotateCounterClockwise();
        tempCubeFaces[2].rotateCounterClockwise();
        tempCubeFaces[2].rotateCounterClockwise();
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
        tempCubeFaces[5].rotateClockwise();
        tempCubeFaces[5].rotateClockwise();
        tempCubeFaces[3].rotateClockwise();
        tempCubeFaces[4].rotateClockwise();
        tempCubeFaces[4].rotateClockwise();
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
        qDebug() << "Invalid cube face ID";
    }

    QVector<QImage> list;
    for (CubeFace f : tempCubeFaces)
        list.push_back(f.toQImage());
    return list;
}

