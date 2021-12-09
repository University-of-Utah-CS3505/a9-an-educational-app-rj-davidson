#include "RubiksEdu.h"
#include "ui_RubiksEdu.h"
#include <iostream>
#include <QMenuBar>
#include <QMainWindow>
#include <QAction>

RubiksEdu::RubiksEdu(QWidget *parent, CubeController *controller, TutorialBrowser *tutorial)
    : QMainWindow(parent)
    , ui(new Ui::RubiksEdu)
{
    ui->setupUi(this);
    connect(this,&RubiksEdu::sendMove,controller,&CubeController::MoveCube);
    connect(controller,&CubeController::updateCube,this, &RubiksEdu::displayCube);
    connect(ui->cubeWidget,SIGNAL(faceSelected(int)),controller,SLOT(switchFace(int)));
        // TODO: delete, this is for testing:
    // Tutorial Widget Connections
    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [] (int step) {
        qDebug() << step;
    });
    connect(ui->stepSelect, &QComboBox::currentIndexChanged, this, [=] (int stepIndex) {
        ui->tutorialTextBrowser->setTutorialStep(stepIndex + 1);
    });
    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [=] (int stepID) {
        ui->stepSelect->setCurrentIndex(stepID-1);
    });
    connect(ui->homeButton, &QPushButton::pressed, this, [=] () {
       ui->tutorialTextBrowser->setTutorialStep(-1);
       ui->stepSelect->setCurrentIndex(-1);
    });
    connect(tutorial, &TutorialBrowser::tutorialStepChanged, controller, [=] () {
       &CubeController::setEduMode;
    });

    // Displays initial cube
    on_leftTopButton_clicked();
    on_rightTopButton_clicked();

    //3d stuff
    createBtnConnection();
    connectControllerView(controller);


    scene3D= new QGraphicsScene;

    createLeftOfCube();
    createRightOfCube();
    createTopOfCube();

    scene3D->setBackgroundBrush(Qt::white);
    ui->cube3DGraphicsView->setScene(scene3D);
    ui->cube3DGraphicsView->scale(0.75,-0.75);


    //Tester 3d:
}
RubiksEdu::~RubiksEdu()
{
    delete ui;
}


void RubiksEdu::on_topLeftButton_clicked()
{
    emit sendMove(7);
}


void RubiksEdu::on_topRightButton_clicked()
{
    emit sendMove(6);
}


void RubiksEdu::on_leftTopButton_clicked()
{
    emit sendMove(0);
}


void RubiksEdu::on_leftBttmButton_clicked()
{
    emit sendMove(1);
}


void RubiksEdu::on_bttmLeftButton_clicked()
{
    emit sendMove(2);
}


void RubiksEdu::on_bttmRightButton_clicked()
{
    emit sendMove(3);
}


void RubiksEdu::on_rightBttmButton_clicked()
{
    emit sendMove(4);
}


void RubiksEdu::on_rightTopButton_clicked()
{
    emit sendMove(5);
}

void RubiksEdu::displayCube(std::vector<QImage> faces)
{
    QImage farRightFace = faces.back();
    faces.pop_back();
    QImage bottomFace = faces.back();
    faces.pop_back();
    QImage rightFace = faces.back();
    faces.pop_back();
    QImage topFace = faces.back();
    faces.pop_back();
    QImage leftFace = faces.back();
    faces.pop_back();
    QImage centerFace = faces.back();
    faces.pop_back();
    QImage centerFaceScaled = centerFace.scaled(120,120);
    QImage rightFaceScaled = rightFace.scaled(120,120);
    QImage leftFaceScaled = leftFace.scaled(120,120);
    QImage topFaceScaled = topFace.scaled(120,120);
    QImage bottomFaceScaled = bottomFace.scaled(120,120);
    QImage farRightFaceScaled = farRightFace.scaled(120,120);

    ui->face0->setPixmap(QPixmap::fromImage(centerFaceScaled));
    ui->face1->setPixmap(QPixmap::fromImage(leftFaceScaled));
    ui->face2->setPixmap(QPixmap::fromImage(topFaceScaled));
    ui->face3->setPixmap(QPixmap::fromImage(rightFaceScaled));
    ui->face4->setPixmap(QPixmap::fromImage(bottomFaceScaled));
    ui->face5->setPixmap(QPixmap::fromImage(farRightFaceScaled));
    ui->face0->setScaledContents( true );
    ui->face0->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    //emit createNew3DCube(scene3D);
}

void RubiksEdu::on_clockwiseButton_clicked()
{
    emit sendMove(8);
}


void RubiksEdu::on_counterClockwiseButton_clicked()
{
    emit sendMove(9);
}


/*
 *3d
*/
void RubiksEdu::on_pushLeftBtn_clicked()
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
            tempItemReference = scene3D->addPath(path1);
            vctrTester.append(tempItemReference);

//            if(xPos == 0){
//                tempItemReference->setBrush(Qt::green);
//            }else if(xPos == 2){
//                tempItemReference->setBrush(Qt::yellow);
//            }else{
//                tempItemReference->setBrush(Qt::black);
//            }
//            tempItemReference->setPen(QPen(Qt::red));
            tempItemReference->setBrush(Qt::white);
        }
    }

    emit send3DRotation("Left");
}

/*
 *3d
*/
void RubiksEdu::on_pushRightButton_clicked()
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
            tempItemReference = scene3D->addPath(path2);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(QColor(255,165,0));
        }

    }
        emit send3DRotation("Right");

}

/*
 *3d
*/
void RubiksEdu::on_pushUpBtn_clicked()
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
            tempItemReference = scene3D->addPath(path3);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::blue);
        }
    }
    emit send3DRotation("Up");
}

/*
 *3d
*/
void RubiksEdu::createBtnConnection(){
    connect(ui->pushLeftBtn,&QPushButton::clicked,this,&RubiksEdu::on_pushLeftBtn_clicked);
    connect(ui->pushRightBtn,&QPushButton::clicked,this,&RubiksEdu::on_pushRightButton_clicked);
    connect(ui->pushUpBtn,&QPushButton::clicked,this,&RubiksEdu::on_pushUpBtn_clicked);
}

/*
 *3d
*/
void RubiksEdu::connectControllerView(CubeController *controller){
   // connect(this, &RubiksEdu::createNew3DCube,controller,&CubeController::new3DCube);
    connect(this, &RubiksEdu::send3DRotation,controller,&CubeController::rotationCube);
    connect(controller,&CubeController::makeNew3DCube,this,&RubiksEdu::on_3DCubeCreation);
}

void RubiksEdu::on_3DCubeCreation(QGraphicsScene *scene){
    ui->cube3DGraphicsView->setScene(scene);
    ui->cube3DGraphicsView->scale(1,-1);
    ui->cube3DGraphicsView->show();
}

/*
 *left side
*/
void RubiksEdu::createLeftOfCube(){

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
            tempItemReference = scene3D->addPath(path1);
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
 *right side
*/
void RubiksEdu::createRightOfCube(){
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
            tempItemReference = scene3D->addPath(path2);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::red);
        }

    }
}

/*
 *top side
*/
void RubiksEdu::createTopOfCube(){

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
            tempItemReference = scene3D->addPath(path3);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::green);
        }
    }

}


//TODO refactor notes for 3d cube
//#include "View3DCube.h"

/////*
//// *TODO
////*/
////View3DCube::View3DCube(QWidget *parent,CubeController *controller)
////{

////    create3DCube();
////}

///*
// *TODO
//*/
//View3DCube::View3DCube()
//{

//    create3DCube();
//}


//void View3DCube::create3DCube(){
//    createUser3DCube();
//}

///*
// *TODO
//*/
//void View3DCube::updateVisibleFaces(std::vector<QImage>)
//{
//        //redraw3DCube(std::vector<QImage>);

//}

///*
// *TODO
//*/
//void View3DCube::redraw3DCube(std::vector<QImage>){

//}

///*
// *TODO
//*/
//void View3DCube::redrawLeftFace(std::vector<QImage>){

//}

///*
// *TODO
//*/
//void View3DCube::redrawRightFace(std::vector<QImage>){

//}

///*
// *TODO
//*/
//void View3DCube::redrawTopFace(std::vector<QImage>){

//}

///*
// *TODO
//*/
//void View3DCube::createUser3DCube(){

//    scene= new QGraphicsScene;

//    createLeftFace();
//    createRightFace();
//    createTopFace();

//    scene->setBackgroundBrush(Qt::white);

//    emit show3DCube(scene);

//}

///*
// *TODO left side
//*/
//void View3DCube::createLeftFace()
//{
//    for(int xPos = 0; xPos<3; xPos++)
//    {
//        int xPosCorrected = 2-xPos; //change xPosition so that 0 element is on left and 2 element is on right.
//                                    //This ensures the face 0,0 point is on the bottom left corner for every face
//        for(int yPos = 0; yPos<3; yPos++)
//        {
//            point1x = -eSize*xPosCorrected*xScale;
//            point1y = eSize*yPos+eSize*xPosCorrected*yScale;
//            point2x = -eSize*(xPosCorrected+1)*xScale;
//            point2y = eSize*yPos+eSize*yScale+eSize*xPosCorrected*yScale;
//            point3x = -eSize*(xPosCorrected+1)*xScale;
//            point3y = eSize*(yPos+1)+eSize*yScale+eSize*xPosCorrected*yScale;
//            point4x = -eSize*xPosCorrected*xScale;
//            point4y = eSize*(yPos+1)+eSize*xPosCorrected*yScale;

//            QPainterPath path1;

//            path1.moveTo(point1x, point1y);
//            path1.lineTo(point2x, point2y);
//            path1.lineTo(point3x, point3y);
//            path1.lineTo(point4x, point4y);
//            path1.lineTo(point1x, point1y);
//            QGraphicsPathItem *tempItemReference;
//            tempItemReference = scene->addPath(path1);
//            vctrTester.append(tempItemReference);

////            if(xPos == 0){
////                tempItemReference->setBrush(Qt::green);
////            }else if(xPos == 2){
////                tempItemReference->setBrush(Qt::yellow);
////            }else{
////                tempItemReference->setBrush(Qt::black);
////            }
////            tempItemReference->setPen(QPen(Qt::red));
//            tempItemReference->setBrush(Qt::yellow);
//        }
//    }

//}


///*
// *TODO right side
//*/
//void View3DCube::createRightFace()
//{
//    for(int xPos = 0; xPos<3; xPos++)
//    {
//        for(int yPos = 0; yPos<3; yPos++)
//        {
//            point1x = eSize*xPos*xScale;
//            point1y = eSize*yPos+eSize*xPos*yScale;
//            point2x = eSize*(xPos+1)*xScale;
//            point2y = eSize*yPos+eSize*yScale+eSize*xPos*yScale;
//            point3x = eSize*(xPos+1)*xScale;
//            point3y = eSize*(yPos+1)+eSize*yScale+eSize*xPos*yScale;
//            point4x = eSize*xPos*xScale;
//            point4y = eSize*(yPos+1)+eSize*xPos*yScale;

//            QPainterPath path2;

//            path2.moveTo(point1x, point1y);
//            path2.lineTo(point2x, point2y);
//            path2.lineTo(point3x, point3y);
//            path2.lineTo(point4x, point4y);
//            path2.lineTo(point1x, point1y);

//            QGraphicsPathItem *tempItemReference;
//            tempItemReference = scene->addPath(path2);
//            vctrTester.append(tempItemReference);

//            tempItemReference->setBrush(Qt::red);
//        }

//    }

//}


///*
// *TODO top side
//*/
//void View3DCube::createTopFace()
//{

//    for(int xPos = 0; xPos<3; xPos++)
//    {
//        for(int yPos = 0; yPos<3; yPos++)
//        {
//            point1x = (xPos-yPos)*eSize*xScale;
//            point1y = cubeSize+(xPos+yPos)*eSize*yScale;
//            point2x = (xPos+1-yPos)*eSize*xScale;
//            point2y = cubeSize+(xPos+yPos)*eSize*yScale+eSize*yScale;
//            point3x = (xPos-yPos)*eSize*xScale;
//            point3y = cubeSize+(xPos+yPos+1)*eSize*yScale+eSize*yScale;
//            point4x = (xPos-1-yPos)*eSize*xScale;
//            point4y = cubeSize+(xPos+yPos)*eSize*yScale+eSize*yScale;

//            QPainterPath path3;

//            path3.moveTo(point1x, point1y);
//            path3.lineTo(point2x, point2y);
//            path3.lineTo(point3x, point3y);
//            path3.lineTo(point4x, point4y);
//            path3.lineTo(point1x, point1y);


//            QGraphicsPathItem *tempItemReference;
//            tempItemReference = scene->addPath(path3);
//            vctrTester.append(tempItemReference);

//            tempItemReference->setBrush(Qt::green);
//        }
//    }


//}



///*
// *TODO
//*/
//void View3DCube::updateBtnClicked(string dir){

//    if(dir=="Left")
//    emit leftPushBtnClicked();


//    if(dir=="Right")
//    emit rightPushBtnClicked();


//    if(dir == "Up")
//    emit upPushBtnClicked();

//}


