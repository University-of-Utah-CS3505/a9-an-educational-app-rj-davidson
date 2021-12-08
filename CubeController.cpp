#include "CubeController.h"
#include <stdlib.h>
#include <iostream>

CubeController::CubeController(QWidget *parent) : QWidget(parent)
{
    //setupAndRandomizeCube();
//    setUpFirstCross();
    emit updateCube(userCube.toQImageList());
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

void CubeController::create3DCubeView(){
    //Cube2dWindow(QWidget *parent,CubeController *controller)
        scene= new QGraphicsScene;

        createLeftOfCube();
        createRightOfCube();
        createTopOfCube();

        scene->setBackgroundBrush(Qt::white);
        cube3D.setScene(scene);
        cube3D.scale(1,-1);

        emit update3DCubeScene(scene,itemRLeft,itemRRight,itemRTop);

}

/*
 *TODO left side
*/
void CubeController::createLeftOfCube(){

    for(int xPos = 0; xPos<3; xPos++)
    {
        int xPosCorrected = 2-xPos; //change xPosition so that 0 element is on left and 2 element is on right.
                                    //This ensures the face 0,0 point is on the bottom left corner for every face
        for(int yPos = 0; yPos<3; yPos++)
        {
            point1x = -eSize*xPosCorrected*xScale;
            point1y = eSize*yPos+eSize*xPosCorrected*yScale;
            point2x = -eSize*(xPosCorrected+1)*xScale;
            point2y = eSize*yPos+eSize*yScale+eSize*xPosCorrected*yScale;
            point3x = -eSize*(xPosCorrected+1)*xScale;
            point3y = eSize*(yPos+1)+eSize*yScale+eSize*xPosCorrected*yScale;
            point4x = -eSize*xPosCorrected*xScale;
            point4y = eSize*(yPos+1)+eSize*xPosCorrected*yScale;

            QPainterPath path1;

            path1.moveTo(point1x, point1y);
            path1.lineTo(point2x, point2y);
            path1.lineTo(point3x, point3y);
            path1.lineTo(point4x, point4y);
            path1.lineTo(point1x, point1y);
            QGraphicsPathItem *tempItemReference;
            tempItemReference = scene->addPath(path1);
            vctrTester.append(tempItemReference);

//            if(xPos == 0){
//                tempItemReference->setBrush(Qt::green);
//            }else if(xPos == 2){
//                tempItemReference->setBrush(Qt::yellow);
//            }else{
//                tempItemReference->setBrush(Qt::black);
//            }
//            tempItemReference->setPen(QPen(Qt::red));
            tempItemReference->setBrush(Qt::yellow);
        }
    }

        emit update3DCubeScene(scene,itemRLeft,itemRRight,itemRTop);
}

/*
 *TODO right side
*/
void CubeController::createRightOfCube(){
    for(int xPos = 0; xPos<3; xPos++)
    {
        for(int yPos = 0; yPos<3; yPos++)
        {
            point1x = eSize*xPos*xScale;
            point1y = eSize*yPos+eSize*xPos*yScale;
            point2x = eSize*(xPos+1)*xScale;
            point2y = eSize*yPos+eSize*yScale+eSize*xPos*yScale;
            point3x = eSize*(xPos+1)*xScale;
            point3y = eSize*(yPos+1)+eSize*yScale+eSize*xPos*yScale;
            point4x = eSize*xPos*xScale;
            point4y = eSize*(yPos+1)+eSize*xPos*yScale;

            QPainterPath path2;

            path2.moveTo(point1x, point1y);
            path2.lineTo(point2x, point2y);
            path2.lineTo(point3x, point3y);
            path2.lineTo(point4x, point4y);
            path2.lineTo(point1x, point1y);

            QGraphicsPathItem *tempItemReference;
            tempItemReference = scene->addPath(path2);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::red);
        }

    }


    emit update3DCubeScene(scene,itemRLeft,itemRRight,itemRTop);
}

/*
 *TODO top side
*/
void CubeController::createTopOfCube(){

    for(int xPos = 0; xPos<3; xPos++)
    {
        for(int yPos = 0; yPos<3; yPos++)
        {
            point1x = (xPos-yPos)*eSize*xScale;
            point1y = cubeSize+(xPos+yPos)*eSize*yScale;
            point2x = (xPos+1-yPos)*eSize*xScale;
            point2y = cubeSize+(xPos+yPos)*eSize*yScale+eSize*yScale;
            point3x = (xPos-yPos)*eSize*xScale;
            point3y = cubeSize+(xPos+yPos+1)*eSize*yScale+eSize*yScale;
            point4x = (xPos-1-yPos)*eSize*xScale;
            point4y = cubeSize+(xPos+yPos)*eSize*yScale+eSize*yScale;

            QPainterPath path3;

            path3.moveTo(point1x, point1y);
            path3.lineTo(point2x, point2y);
            path3.lineTo(point3x, point3y);
            path3.lineTo(point4x, point4y);
            path3.lineTo(point1x, point1y);


            QGraphicsPathItem *tempItemReference;
            tempItemReference = scene->addPath(path3);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::green);
        }
    }

        emit update3DCubeScene(scene,itemRLeft,itemRRight,itemRTop);

}


/*
 *TODO
*/
void CubeController::rotationCube(string dirRotate){
     emit updateUserRotation(dirRotate);
}
