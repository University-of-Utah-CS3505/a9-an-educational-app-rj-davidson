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
void View3DCube::create3DCube(){

}

/*
 *TODO
*/
void View3DCube::createLeftFace()
{

}


/*
 *TODO
*/
void View3DCube::createRightFace()
{

}


/*
 *TODO
*/
void View3DCube::createTopFace()
{

}


/*
 *TODO
*/
void View3DCube::setScene(QGraphicsScene *scene1){

}

/*
 *TODO
*/
void View3DCube::scale(int x,int y){

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
