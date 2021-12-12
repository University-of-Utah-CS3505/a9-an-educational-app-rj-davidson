#include "CubeController.h"
#include "CubeBuilder.h"
#include <stdlib.h>
#include <iostream>

CubeController::CubeController(QWidget *parent) : QWidget(parent)
{
    setUserCube(CubeBuilder::randomCube());

//    connect(this,&CubeController::makeNew3DCube,&cube3DView,&View3DCube::createUser3DCube);

    //3D cube view connections
    connect(this, &CubeController::updateUserRotation, &cube3D, &Model3DCube::update3DOrientation);
    connect(this, &CubeController::cube1DUpdated, &cube3D, &Model3DCube::update3DCube);
    connect(&cube3D, &Model3DCube::notify3DCubeViewSimple, this, &CubeController::update3DCubeViewSimple);
    connect(&cube3D, &Model3DCube::notify3DCubeView, this, &CubeController::update3DCubeView);

    //TODO need to make connection from rubiks to celebration when the cube is solved

}


void CubeController::switchFace(int faceNumber)
{
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
    qDebug() << "Current Face: " << userCube.getCurrentFace();

    emit updateCube(userCube.toQImageList());
    emit cube1DUpdated(userCube);  //this signal passes the cube data to Model3DCube
}

void CubeController::MoveCube(int moveClicked){
    userCube.move(moveClicked);
    emit updateCube(userCube.toQImageList());
    emit cubeComplete(userCube.isComplete());

    //for 3D cube view
    emit cube1DUpdated(userCube);  //this signal passes the cube data to Model3DCube
}

void CubeController::buildPredefinedCube(int cubeID)
{
    switch (cubeID) {
      case 1: {
        setUserCube(CubeBuilder::generateTutorialStep1Cube());
        break;
      }
      case 2: {
        setUserCube(CubeBuilder::generateTutorialStep2Cube());
        break;
      }
      case 3: {
        setUserCube(CubeBuilder::generateTutorialStep3Cube());
        break;
      }
      case 4: {
        setUserCube(CubeBuilder::generateTutorialStep4Cube());
        break;
      }
      case 5: {
        setUserCube(CubeBuilder::generateTutorialStep5Cube());
        break;
      }
      case 6: {
        setUserCube(CubeBuilder::generateTutorialStep6Cube());
        break;
      }
      case 7: {
        setUserCube(CubeBuilder::generateTutorialStep7Cube());
        break;
      }
      case 8: {
        setUserCube(CubeBuilder::generateTutorialStep8Cube());
        break;
      }
      default: {
        setUserCube(CubeBuilder::randomCube());
      }
    }
}


void CubeController::setUserCube(Cube c) {
    userCube = c;
    emit updateCube(userCube.toQImageList());
    emit cube1DUpdated(userCube);
}


//cube3Dview methods
/*
 * Resets the orientation to the base position (matches tutorial)
 * Added by: Maiko Tuitupou
 */
void CubeController::reset3DCubeOrientation() {
    cube3D.resetOrientation();
}

/*
 * Send direction to rotate 3D cube to model so that the orientation can be updated
 *
 * Based on what button was pressed in the view.  Either sends "Up", "Left", or "Right"
*/
void CubeController::rotationCube(const string & dirRotate){
     emit updateUserRotation(dirRotate);
}

/*
 * Sends 3D cube data to view to paint
 */
void CubeController::on_cube3DdataUpdated(std::vector<char> &visibleFaceData){
    emit update3DCubeViewSimple(visibleFaceData);
}

void CubeController::checkCompletion()
{
    emit complete(userCube.isComplete());
}

