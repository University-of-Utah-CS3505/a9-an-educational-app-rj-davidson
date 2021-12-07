#include "CubeController.h"
#include <stdlib.h>
#include <iostream>

CubeController::CubeController(QWidget *parent) : QWidget(parent)
{
    //setupAndRandomizeCube();
//    setUpFirstCross();
}

void CubeController::switchFace(int faceNumber)
{
    std::cout << "Current Face: " << faceNumber << std::endl;
    userCube.setCurrentFace(faceNumber);
    emit updateCube(userCube.toQImageList());
}

void CubeController::MoveCube(int moveClicked){
    userCube.move(moveClicked);
    emit updateCube(userCube.toQImageList());
}

void CubeController::setEduMode(int mode)
{
    switch(mode)
    {
//    case 0:
//        setUpFirstCross();
//        break;
//    case 1:
//        setUpFirstCorners();
//        break;
//    case 2:
//        setUpNeighbors();
//        break;
//    case 3:
//        setUpBottomCross();
//        break;
//    case 4:
//        setUpFinalCorners();
//        break;
//    default:
//        setupAndRandomizeCube();
    }
}


void CubeController::setupAndRandomizeCube()
{
    //make new cube object here

    for (int i = 0; i < 20; i++)
    {
        int randomMove = rand() % 7 + 0;
        int randomFace = rand() % 5 + 0;
        userCube.setCurrentFace(randomFace);
        MoveCube(randomMove);
        // Randomize Moves and Store to
        //make a bunch of random cubes
        //randomize face 0-5
        //randomize moveid 0-7
    }
    //set new cube object but don't modify the cube in use until the very end this way it gets sent in the end
    userCube.setCurrentFace(0);
    emit updateCube(userCube.toQImageList());
    //emit updateCube(pass list of qImages);
}

void CubeController::setUpFirstCross()
{
    userCube = Cube(1);
    userCube.setCurrentFace(0);
    emit updateCube(userCube.toQImageList());
//    Cube newCube = Cube(1);
}

void CubeController::setUpFirstCorners()
{

}

void CubeController::setUpNeighbors()
{

}

void CubeController::setUpBottomCross()
{

}

void CubeController::setUpFinalCorners()
{

}
