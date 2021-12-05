#include "window3dcube.h"
#include "ui_window3dcube.h"



Window3DCube::Window3DCube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window3DCube)
{
    ui->setupUi(this);

//    faceWidget1 = new QGraphicsRectItem;

//     faceWidget1->setZValue(1);
//   faceWidget1->setRect(320, 210 , 100, 100);

   scene1= new QGraphicsScene;
   float cubeSize = 120;

   float eSize = cubeSize / 3; //size of each element

   // (0,0) is at bottom piont on cube
   //
   // so left view is negative, right view is positive


   //float viewAngle = 30;

   float xScale = 0.866025403784; //cos(30deg)
   qDebug()<<xScale;
   float yScale = 0.5;		//sin(30deg)
      qDebug()<<yScale;

   float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;

   //left side
   QPainterPath path1;
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
       }
   }
   path1.moveTo(point1x, point1y);
   path1.lineTo(point2x, point2y);
   path1.lineTo(point3x, point3y);
   path1.lineTo(point4x, point4y);
   path1.lineTo(point1x, point1y);
   itemR = scene1->addPath(path1);
   itemR->setBrush(Qt::black);


   //right side
   QPainterPath path2;
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
       }
   }

      qDebug()<<point1x;
      qDebug()<<point1y;
      qDebug()<<point2x;
      qDebug()<<point2y;
      qDebug()<<point3x;
      qDebug()<<point3y;
      qDebug()<<point4x;
      qDebug()<<point4y;


path2.moveTo(point1x, point1y);
path2.lineTo(point2x, point2y);
path2.lineTo(point3x, point3y);
path2.lineTo(point4x, point4y);
path2.lineTo(point1x, point1y);
itemR = scene1->addPath(path2);
itemR->setBrush(Qt::blue);


   //top side
QPainterPath path3;
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
       }
   }
   path3.moveTo(point1x, point1y);
   path3.lineTo(point2x, point2y);
   path3.lineTo(point3x, point3y);
   path3.lineTo(point4x, point4y);
   path3.lineTo(point1x, point1y);
   itemR = scene1->addPath(path3);
   itemR->setBrush(Qt::gray);





   scene1->setSceneRect(0, 0 , 500, 300);
   scene1->setBackgroundBrush(Qt::white);


    //scene1->addItem(itemR);
    ui->cubeGraphicsView->setScene(scene1);
    ui->cubeGraphicsView->scale(-1,1);
   // ui->cubeGraphicsView->setVisible(false);

}

Window3DCube::~Window3DCube()
{
    delete ui;
}

void Window3DCube::open3DCubeWindow(){

    this->show();

}
