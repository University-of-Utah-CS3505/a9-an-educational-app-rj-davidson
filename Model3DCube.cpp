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

}

/*
 *TODO
*/
std::vector<QImage> Model3DCube::getQImageList(){
    //    QVector<QGraphicsPathItem*> vctrFace0;
    //    QVector<QGraphicsPathItem*> vctrFace1;
    //    QVector<QGraphicsPathItem*> vctrFace2;
    //    QVector<QGraphicsPathItem*> vctrFace3;
    //    QVector<QGraphicsPathItem*> vctrFace4;
    //    QVector<QGraphicsPathItem*> vctrFace5;

    return vctrFaces1DCube;
}

/*
 *TODO
*/
//the cube controller will tell what to display at the same time as the mainwindow cube
void Model3DCube::update3DCube(vector<QImage> qImageList)
{

    // the model will need to know the faces hidden and visible
    updateVisibleFace();
    updateHiddenFaces();

    // the model will need to know the way each face needs to look
   //TODO updateFace0(QImage f0,QImage scaled);
    //TODO updateFace1(QImage f1,QImage scaled);
   //TODO updateFace2(QImage f2,QImage scaled);
   //TODO updateFace3(QImage f3,QImage scaled);
   //TODO updateFace4(QImage f4,QImage scaled);
   //TODO updateFace5(QImage f5,QImage scaled);

    // the model will need to save the 3dcube orientation
    updateOrientation();

    emit notify3DCubeView(qImageList);
}

/*
 *TODO
*/
void Model3DCube::updateVisibleFace()
{

}

/*
 *TODO
*/
void Model3DCube::updateHiddenFaces()
{

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
*/
void Model3DCube::updateVisibleFaces(){
    //left, right, up is correct order in vector
    visibleFaces.clear();

    visibleFaces.push_back(cube3DFaceData.at(xAxisPosition));
    int rightFacePosition = (xAxisPosition+1)%4;
    visibleFaces.push_back(cube3DFaceData.at(rightFacePosition));
    visibleFaces.push_back(cube3DFaceData.at(yAxisPosition+4));
    qDebug()<< "updateVisibleFaces: " << visibleFaces.size();
    emit notify3DCubeViewSimple(visibleFaces);
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
