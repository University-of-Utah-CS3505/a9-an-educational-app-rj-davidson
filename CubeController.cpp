#include "CubeController.h"
#include "CubeBuilder.h"
#include <stdlib.h>
#include <iostream>

CubeController::CubeController(QWidget *parent) : QWidget(parent)
{
    setUserCube(CubeBuilder::generateRandomCube());
    lastNontutorialCube = userCube;

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
    switch(userCube.getCurrentFaceID())
    {
        case 1:
            if (faceNumber == 1)
                userCube.setCurrentFaceID(5);
            else if (faceNumber == 2)
                userCube.setCurrentFaceID(2);
            else if (faceNumber == 3)
                userCube.setCurrentFaceID(0);
            else if (faceNumber == 4)
                userCube.setCurrentFaceID(4);
            else if (faceNumber == 5)
                userCube.setCurrentFaceID(3);
            break;
        case 2:
            if (faceNumber == 1)
                userCube.setCurrentFaceID(1);
            else if (faceNumber == 2)
                userCube.setCurrentFaceID(5);
            else if (faceNumber == 3)
                userCube.setCurrentFaceID(3);
            else if (faceNumber == 4)
                userCube.setCurrentFaceID(0);
            else if (faceNumber == 5)
                userCube.setCurrentFaceID(4);
            break;
        case 3:
            if (faceNumber == 1)
                userCube.setCurrentFaceID(0);
            else if (faceNumber == 2)
                userCube.setCurrentFaceID(2);
            else if (faceNumber == 3)
                userCube.setCurrentFaceID(5);
            else if (faceNumber == 4)
                userCube.setCurrentFaceID(4);
            else if (faceNumber == 5)
                userCube.setCurrentFaceID(1);
            break;
        case 4:
            if (faceNumber == 1)
                userCube.setCurrentFaceID(1);
            else if (faceNumber == 2)
                userCube.setCurrentFaceID(0);
            else if (faceNumber == 3)
                userCube.setCurrentFaceID(3);
            else if (faceNumber == 4)
                userCube.setCurrentFaceID(5);
            else if (faceNumber == 5)
                userCube.setCurrentFaceID(2);
            break;
        case 5:
            if (faceNumber == 1)
                userCube.setCurrentFaceID(3);
            else if (faceNumber == 2)
                userCube.setCurrentFaceID(2);
            else if (faceNumber == 3)
                userCube.setCurrentFaceID(1);
            else if (faceNumber == 4)
                userCube.setCurrentFaceID(4);
            else if (faceNumber == 5)
                userCube.setCurrentFaceID(0);
            break;
        default:
            userCube.setCurrentFaceID(faceNumber);
    }
    qDebug() << "Current Face: " << userCube.getCurrentFaceID();

    emit updateCube(userCube.toQImageList());
    emit cube1DUpdated(userCube);  //this signal passes the cube data to Model3DCube
}

void CubeController::MoveCube(int moveClicked){
    switch (moveClicked)
        {
            case 0:
                userCube.moveU(CLOCKWISE);
                break;
            case 1:
                userCube.moveD(COUNTERCLOCKWISE);
                break;
            case 2:
                userCube.moveL(CLOCKWISE);
                break;
            case 3:
                userCube.moveR(COUNTERCLOCKWISE);
                break;
            case 4:
                userCube.moveD(CLOCKWISE);
                break;
            case 5:
                userCube.moveD(COUNTERCLOCKWISE);
                break;
            case 6:
                userCube.moveU(CLOCKWISE);
                break;
            case 7:
                userCube.moveL(COUNTERCLOCKWISE);
                break;
            case 8:
                userCube.moveF(CLOCKWISE);
                break;
            case 9:
                userCube.moveF(COUNTERCLOCKWISE);
                break;
            default:
                qDebug() << "ERROR: Cube Move";
        }
    emit updateCube(userCube.toQImageList());
    emit cubeComplete(userCube.isSolved());

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
        setUserCube(lastNontutorialCube);
      }
    }
}

void CubeController::buildRandomCube() {
    setUserCube(CubeBuilder::generateRandomCube());
    lastNontutorialCube = userCube;
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
void CubeController::on_cube3DdataUpdated(QVector<char> &visibleFaceData){
    emit update3DCubeViewSimple(visibleFaceData);
}

void CubeController::checkCompletion()
{
    bool c = userCube.isSolved();
    emit complete(&c);
}

