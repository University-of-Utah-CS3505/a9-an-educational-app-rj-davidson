#include "View3DCube.h"

///*
// *TODO
//*/
//View3DCube::View3DCube(QWidget *parent,CubeController *controller)
//{

//    create3DCube();
//}

/*
 *TODO
*/
View3DCube::View3DCube()
{

    create3DCube();
}


void View3DCube::create3DCube(){
    createUser3DCube();
}

/*
 *TODO
*/
void View3DCube::updateVisibleFaces(std::vector<QImage>)
{
        //redraw3DCube(std::vector<QImage>);

}

/*
 *TODO
*/
void View3DCube::redraw3DCube(std::vector<QImage>){

}

/*
 *TODO
*/
void View3DCube::redrawLeftFace(std::vector<QImage>){

}

/*
 *TODO
*/
void View3DCube::redrawRightFace(std::vector<QImage>){

}

/*
 *TODO
*/
void View3DCube::redrawTopFace(std::vector<QImage>){

}

/*
 *TODO
*/
void View3DCube::createUser3DCube(){

    scene= new QGraphicsScene;

    createLeftFace();
    createRightFace();
    createTopFace();

    scene->setBackgroundBrush(Qt::white);

    emit show3DCube(scene);

}

/*
 *TODO left side
*/
void View3DCube::createLeftFace()
{
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

}


/*
 *TODO right side
*/
void View3DCube::createRightFace()
{
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

}


/*
 *TODO top side
*/
void View3DCube::createTopFace()
{

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


}



/*
 *TODO
*/
void View3DCube::updateBtnClicked(string dir){

    if(dir=="Left")
    emit leftPushBtnClicked();


    if(dir=="Right")
    emit rightPushBtnClicked();


    if(dir == "Up")
    emit upPushBtnClicked();

}
