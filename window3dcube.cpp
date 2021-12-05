#include "window3dcube.h"
#include "ui_window3dcube.h"


/*
 *
*/
Window3DCube::Window3DCube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window3DCube)
{
    ui->setupUi(this);

   scene1= new QGraphicsScene;
createLeftOfCube();

createRightOfCube();

createTopOfCube();




   scene1->setSceneRect(0, 0 , 500, 300);
   scene1->setBackgroundBrush(Qt::white);


    ui->cubeGraphicsView->setScene(scene1);
    ui->cubeGraphicsView->scale(-1,1);


}

/*
 *
*/
Window3DCube::~Window3DCube()
{
    vector.clear();
    delete ui;
}

/*
 *
*/
void Window3DCube::open3DCubeWindow(){

    this->show();

}


/*
 *left side
*/
void Window3DCube::createLeftOfCube(){

    for(int xPos = 0; xPos<3; xPos++)
    {
        for(int yPos = 0; yPos<3; yPos++)
        {
            xPos = -xPos+2; //change xPosition so that 0 element is on left and 2 element is on right.  This ensures the face 0,0 point is on the bottom left corner
            point1x = -eSize*xPos*xScale;
            point1y = eSize*yPos;
            point2x = -eSize*(xPos+1)*xScale;
            point2y = eSize*yPos+eSize*yScale;
            point3x = -eSize*(xPos+1)*xScale;
            point3y = eSize*(yPos+1)+eSize*yScale;
            point4x = -eSize*xPos*xScale;
            point4y = eSize*(yPos+1);

            path1.moveTo(point1x, point1y);
            path1.lineTo(point2x, point2y);
            path1.lineTo(point3x, point3y);
            path1.lineTo(point4x, point4y);
            path1.lineTo(point1x, point1y);
            itemRLeft = scene1->addPath(path1);
            itemRLeft->setBrush(Qt::black);
            vector.append(itemRLeft);
            qDebug()<<vector.size();
        }
    }

}

/*
 *right side
*/
void Window3DCube::createRightOfCube(){
    for(int xPos = 0; xPos<3; xPos++)
    {
        for(int yPos = 0; yPos<3; yPos++)
        {
            point1x = eSize*xPos*xScale;
            point1y = eSize*yPos;
            point2x = eSize*(xPos+1)*xScale;
            point2y = eSize*yPos+eSize*yScale;
            point3x = eSize*(xPos+1)*xScale;
            point3y = eSize*(yPos+1)+eSize*yScale;
            point4x = eSize*xPos*xScale;
            point4y = eSize*(yPos+1);

            path2.moveTo(point1x, point1y);
            path2.lineTo(point2x, point2y);
            path2.lineTo(point3x, point3y);
            path2.lineTo(point4x, point4y);
            path2.lineTo(point1x, point1y);
            itemRRight = scene1->addPath(path2);
            itemRRight->setBrush(Qt::blue);
            vector.append(itemRRight);
            qDebug()<<vector.size();
        }

    }



save2DCubeXY();
}

/*
 *top side
*/
void Window3DCube::createTopOfCube(){

    for(int xPos = 0; xPos<3; xPos++)
    {
        for(int yPos = 0; yPos<3; yPos++)
        {
            point1x = (xPos-yPos)*eSize*xScale;
            point1y = cubeSize+(xPos+yPos)*eSize*yScale;
            point2x = (xPos+1-yPos)*eSize*xScale;
            point2y = cubeSize+(xPos+yPos)*eSize*yScale+eSize*yScale;
            point3x = (xPos+1-yPos)*eSize*xScale;
            point3y = cubeSize+(xPos+yPos+1)*eSize*yScale+eSize*yScale;
            point4x = (xPos-1-yPos)*eSize*xScale;
            point4y = cubeSize+(xPos+yPos)*eSize*yScale+eSize*yScale;

            path3.moveTo(point1x, point1y);
            path3.lineTo(point2x, point2y);
            path3.lineTo(point3x, point3y);
            path3.lineTo(point4x, point4y);
            path3.lineTo(point1x, point1y);
            itemRTop = scene1->addPath(path3);
            itemRTop->setBrush(Qt::gray);
            vector.append(itemRTop);
        }
    }
    qDebug()<<vector.size();

}

///*
// *save inside vector2d to be used later so that they don't have to be created
// *each time again when repainting
//*/
//void Window3DCube::save2DCubeXY(){

//QByteArray arrayFaceLeft;
//arrayFaceLeft.resize(8);
//arrayFaceLeft[0] = point1x;
//arrayFaceLeft[1] = point1y;
//arrayFaceLeft[2] = point2x;
//arrayFaceLeft[3] = point2y;
//arrayFaceLeft[4] = point3x;
//arrayFaceLeft[5] = point3y;
//arrayFaceLeft[6] = point4x;
//arrayFaceLeft[7] = point4y;

//qDebug()<<arrayFaceLeft[7];

//}
