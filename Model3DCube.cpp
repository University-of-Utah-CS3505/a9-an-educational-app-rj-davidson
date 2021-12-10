#include "Model3DCube.h"

///*
// *TODO
//*/
//Model3DCube::Model3DCube(QWidget *parent,CubeController *controller)
//{

//}

/*
 *TODO
*/
Model3DCube::Model3DCube()
{
    //tester code to have a cube to send to view before connecting with actual cube data
    cubeCopyOf1D = Cube();
}

/*
 *TODO
*/
std::vector<QImage> Model3DCube::getQImageList(){


    return vctrFaces1DCube;
}

/*
 *TODO
*/
//the cube controller will tell what to display at the same time as the mainwindow cube
void Model3DCube::update3DCube(Cube const &cube)
{
    qDebug()<<"model3DCube.cpp:update3DCube called";
    cubeCopyOf1D = cube;
    updateVisibleFaces();




    // the model will need to know the faces hidden and visible


    // the model will need to know the way each face needs to look
   //TODO updateFace0(QImage f0,QImage scaled);
    //TODO updateFace1(QImage f1,QImage scaled);
   //TODO updateFace2(QImage f2,QImage scaled);
   //TODO updateFace3(QImage f3,QImage scaled);
   //TODO updateFace4(QImage f4,QImage scaled);
   //TODO updateFace5(QImage f5,QImage scaled);

    // the model will need to save the 3dcube orientation
//    updateOrientation();

    //emit notify3DCubeView(qImageList);
}

/*
 *TODO
*/
void Model3DCube::updateFace0(QImage f0,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace1(QImage f1,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace2(QImage f2,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace3(QImage f3,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace4(QImage f4,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace5(QImage f5,QImage scaled)
{

}

/*
 *TODO
 *
 *In progress:
 * need to connect this to view
 * need to implement correct visible face rotation and flipping to match orientation
*/
void Model3DCube::updateVisibleFaces(){
    //actual implementation with full cube data
    visibleFaces.clear();

    //makeing a copy of stored 1d cube data to calculate the visible faces and visible face orientations
    Cube tempCube = cubeCopyOf1D;
    CubeFace leftFace, rightFace, topFace;

    leftFace = tempCube.getFace(xAxisPosition);
    rightFace = tempCube.getFace(getRightVisibleFacePosition());
    topFace = tempCube.getFace(yAxisPosition+4);

    if(yAxisPosition == up){
        //need to rotate top face to match xAxisPosition
        for(int i=0; i<xAxisPosition; i++){
            topFace.rotateClockwise();
        }
    }else{
        //if down, need to flip left and right face vertically

    }

    visibleFaces.push_back(leftFace);
    visibleFaces.push_back(rightFace);
    visibleFaces.push_back(topFace);
    qDebug()<< "updateVisibleFaces: " << visibleFaces.size();
    emit notify3DCubeView(visibleFaces);


    //simple tester code:
    //left, right, up is correct order in vector
//    visibleFacesSimple.clear();
//    visibleFacesSimple.push_back(cube3DFaceData.at(xAxisPosition));
//    visibleFacesSimple.push_back(cube3DFaceData.at(getRightVisibleFacePosition()));
//    visibleFacesSimple.push_back(cube3DFaceData.at(yAxisPosition+4));
//    qDebug()<< "updateVisibleFacesSimple: " << visibleFacesSimple.size();
    //emit notify3DCubeViewSimple(visibleFacesSimple);
}

int Model3DCube::getRightVisibleFacePosition(){
    int rightFacePosition = 0;
    if(yAxisPosition == up){
        rightFacePosition = (xAxisPosition+1)%4;
    }
    else if(yAxisPosition == down){
        if(xAxisPosition == deg0){
            rightFacePosition = deg270;
        }else{
            rightFacePosition = ((int)xAxisPosition)-1;
        }
    }
    return rightFacePosition;
}

/*
 *TODO
*/
void Model3DCube::updateOrientation(){

}

//Functions for orientation code -------------------------------------------------------------------------------------------------------

void Model3DCube::update3DOrientation(const string &dirRotate){
    if(dirRotate == "Up"){
        rotate_up();
    }
    else if(dirRotate == "Left"){
        rotate_left();
    }
    else if(dirRotate == "Right"){
        rotate_right();
    }
    updateVisibleFaces();
}

/*
 * Decreases the xAxis rotation angle
 * loops back around to 270 when decreasing from 0
 */
void Model3DCube::helper_decrease_angle(){
    if(xAxisPosition == deg0){
        xAxisPosition = deg270;
    }else{
        xAxisPosition = (enum xAxis)(xAxisPosition-1);
    }
}

/*
 * Increases the xAxis rotation angle
 * loops back around to 0 when increasing from 270
 */
void Model3DCube::helper_increase_angle(){
    xAxisPosition = (enum xAxis)((xAxisPosition+1)%4);
}

/*
 * Updates the xAxisPosition to rotate the cube orientation to the right
*/
void Model3DCube::rotate_right(){
    if(yAxisPosition == up){
        //xAxis angle goes down when rotated to the left when the yAxis is up
        helper_decrease_angle();
    }else{
        //xAxis angle goes up when rotated to the left when the yAxis is down
        helper_increase_angle();
    }

    printOrientation();
}

/*
 * Updates the xAxisPosition to rotate the cube orientation to the left
*/
void Model3DCube::rotate_left(){

    if(yAxisPosition == up){
        //xAxis angle goes up when rotated to the left when the yAxis is up
        helper_increase_angle();
    }else{
        //xAxis angle goes down when rotated to the left when the yAxis is down
        helper_decrease_angle();
    }


    printOrientation();
}

/*
 * Updates the yAxisPosition to rotate the cube upside-down
*/
void Model3DCube::rotate_up(){
    if(yAxisPosition == up){
        helper_decrease_angle();
    }else{
        helper_increase_angle();
    }

    yAxisPosition = (enum yAxis)((yAxisPosition+1)%2);

    printOrientation();
}

void Model3DCube::printOrientation(){
    QList<QString> xOrentations = {"deg0", "deg90", "deg180", "deg270"};
    QList<QString> yOrentations = {"up", "down"};
    qDebug()<<"xAxisPosition: " << xOrentations.at(xAxisPosition) << "\tyAxisPosition: " << yOrentations.at(yAxisPosition);
}

//end of orientation code -------------------------------------------------------------------------------------------------------
