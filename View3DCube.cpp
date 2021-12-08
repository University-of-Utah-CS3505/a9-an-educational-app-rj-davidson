#include "View3DCube.h"

/*
 *
*/
View3DCube::View3DCube(QWidget *parent,CubeController *controller)
{

    connect(&controller,&CubeController::updateUserRotation,this,&View3DCube::updateBtnClicked);
}

//~View3DCube(){

//}

/*
 *
*/
void View3DCube::open2DCubeWindow()
{

}

/*
 *
*/
void View3DCube::leftPushBtnClicked()
{

}

/*
 *
*/
void View3DCube::rightPushBtnClicked()
{

}

/*
 *
*/
void View3DCube::upPushBtnClicked()
{

}

/*
 *
*/
void createLeftOfCube()
{

}


/*
 *
*/
void View3DCube::createRightOfCube()
{

}


/*
 *
*/
void View3DCube::createTopOfCube()
{

}

/*
 *
*/
void View3DCube::createBtnConnection()
{

}

void View3DCube::updateBtnClicked(string dir){

}
