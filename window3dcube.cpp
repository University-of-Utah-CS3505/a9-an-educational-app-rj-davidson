#include "window3dcube.h"
#include "ui_window3dcube.h"



Window3DCube::Window3DCube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window3DCube)
{
    ui->setupUi(this);

    faceWidget1 = new QGraphicsRectItem;

     faceWidget1->setZValue(1);
   faceWidget1->setRect(50,50,50,50);

   scene1= new QGraphicsScene;

   QPainterPath path;
   QRectF rect(0, 0 , 100, 100);
   path.moveTo(rect.center().x(), rect.top());
   path.lineTo(rect.right(), rect.center().y());
   path.lineTo(rect.center().x(), rect.bottom());
   path.lineTo(rect.left(), rect.center().y());
   path.lineTo(rect.center().x(), rect.top());
   itemR = scene1->addPath(path);

    scene1->setSceneRect(0 ,0,500,500);


    scene1->setBackgroundBrush(Qt::red);
    scene1->addItem(faceWidget1);


    ui->cubeGraphicsView->setScene(scene1);
   // ui->cubeGraphicsView->setVisible(false);

}

Window3DCube::~Window3DCube()
{
    delete ui;
}

void Window3DCube::open3DCubeWindow(){

    this->show();

}
