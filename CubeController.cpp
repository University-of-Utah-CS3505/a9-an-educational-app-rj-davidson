#include "CubeController.h"
#include <stdlib.h>
#include <iostream>

CubeController::CubeController(QWidget *parent) : QWidget(parent)
{
    //setupAndRandomizeCube();
//    setUpFirstCross();
    emit updateCube(userCube.toQImageList());
}

void CubeController::switchFace(int faceNumber)
{
    std::cout << "Current Face: " << faceNumber << std::endl;
    switch(userCube.getCurrentFace())
    {
        case 1:
            if (faceNumber == 1)
                userCube.setCurrentFace(5);
            else if (faceNumber == 2)
                userCube.setCurrentFace(2);
            else if (faceNumber == 3)
                userCube.setCurrentFace(0);
            else if (faceNumber == 4)
                userCube.setCurrentFace(4);
            else if (faceNumber == 5)
                userCube.setCurrentFace(3);
            break;
        case 2:
            if (faceNumber == 1)
                userCube.setCurrentFace(1);
            else if (faceNumber == 2)
                userCube.setCurrentFace(5);
            else if (faceNumber == 3)
                userCube.setCurrentFace(3);
            else if (faceNumber == 4)
                userCube.setCurrentFace(0);
            else if (faceNumber == 5)
                userCube.setCurrentFace(4);
            break;
        case 3:
            if (faceNumber == 1)
                userCube.setCurrentFace(0);
            else if (faceNumber == 2)
                userCube.setCurrentFace(2);
            else if (faceNumber == 3)
                userCube.setCurrentFace(5);
            else if (faceNumber == 4)
                userCube.setCurrentFace(4);
            else if (faceNumber == 5)
                userCube.setCurrentFace(1);
            break;
        case 4:
            if (faceNumber == 1)
                userCube.setCurrentFace(1);
            else if (faceNumber == 2)
                userCube.setCurrentFace(0);
            else if (faceNumber == 3)
                userCube.setCurrentFace(3);
            else if (faceNumber == 4)
                userCube.setCurrentFace(5);
            else if (faceNumber == 5)
                userCube.setCurrentFace(2);
            break;
        case 5:
            if (faceNumber == 1)
                userCube.setCurrentFace(3);
            else if (faceNumber == 2)
                userCube.setCurrentFace(2);
            else if (faceNumber == 3)
                userCube.setCurrentFace(1);
            else if (faceNumber == 4)
                userCube.setCurrentFace(4);
            else if (faceNumber == 5)
                userCube.setCurrentFace(0);
            break;
        default:
            userCube.setCurrentFace(faceNumber);
    }
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
