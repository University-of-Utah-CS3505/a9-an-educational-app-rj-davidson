#include "CubeController.h"
#include <stdlib.h>
#include <iostream>

CubeController::CubeController(QWidget *parent, ViewCube *cubeView) : QWidget(parent)
{
    setupAndRandomizeCube();
    connect(cubeView,&ViewCube::faceSelected,this,&CubeController::switchFace);
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
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        setupAndRandomizeCube();
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
