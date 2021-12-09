#include "CubeController.h"
#include <stdlib.h>
#include <iostream>

CubeController::CubeController(QWidget *parent) : QWidget(parent)
{
    //setupAndRandomizeCube();
    setUpFirstCross();
//    connect(this,&CubeController::makeNew3DCube,&cube3DView,&View3DCube::createUser3DCube);
    connect(this, &CubeController::updateUserRotation, &cube3D, &Model3DCube::update3DOrientation);
    connect(&cube3D, &Model3DCube::notify3DCubeViewSimple, this, &CubeController::update3DCube);

    //emit updateCube(userCube.toQImageList());
    //TODO    emit updateCube(cube3D.getQImageList());
    //TODO   emit updateCube(cube3DView.getQImageList());
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
    //TODO    emit updateCube(cube3D.toQImageList());
    //TODO   emit updateCube(cube3DView.toQImageList();
}

void CubeController::MoveCube(int moveClicked){
    userCube.move(moveClicked);
    emit updateCube(userCube.toQImageList());
    //TODO    emit updateCube(cube3D.toQImageList());
    //TODO   emit updateCube(cube3DView.toQImageList();
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

//TODO    emit updateCube(cube3D.toQImageList());
//TODO   emit updateCube(cube3DView.toQImageList();

    //emit updateCube(pass list of qImages);
}

void CubeController::setUpFirstCross()
{
    userCube = Cube(6);
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

/*
 *TODO master of visible faces of the 3d cube
*/
void CubeController::create3DCubeView(){


        emit update3DCubeScene();

}

/*
 * Send direction to rotate 3D cube to model so that the orientation can be updated
 *
 * Based on what button was pressed in the view.  Either sends "Up", "Left", or "Right"
*/
void CubeController::rotationCube(const string & dirRotate){
     emit updateUserRotation(dirRotate);
}

void CubeController::on_cube3DdataUpdated(std::vector<char> &visibleFaceData){
    emit update3DCube(visibleFaceData);
}


/*
 *TODO
*/
void CubeController::new3DCube(QGraphicsScene *scene){
    emit makeNew3DCube(scene);
}
