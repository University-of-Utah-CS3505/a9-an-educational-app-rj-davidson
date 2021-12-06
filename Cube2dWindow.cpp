#include "Cube2dWindow.h"
#include "ui_Cube2dWindow.h"

/*
 *
*/
Cube2dWindow::Cube2dWindow(QWidget *parent,CubeController *controller) :
    QMainWindow(parent),
    ui(new Ui::Cube2dWindow)
{
    ui->setupUi(this);
    createBtnConnection();
    scene1= new QGraphicsScene;

    createLeftOfCube();
    createRightOfCube();
    createTopOfCube();

    scene1->setBackgroundBrush(Qt::white);
    ui->cube2DGraphicsView->setScene(scene1);
    ui->cube2DGraphicsView->scale(1,-1);



//    connect(this,&Cube2dWindow::sendMove,controller,&CubeController::MoveCube);
    connect(controller,&CubeController::updateCube,this, &Cube2dWindow::update2DCubeView);


//    connect(ui->cubeWidget,SIGNAL(faceSelected(int)),controller,SLOT(switchFace(int)));
//        // TODO: delete, this is for testing:
//    // Tutorial Widget Connections
//    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [] (int step) {
//        qDebug() << step;
//    });
//    connect(ui->stepSelect, &QComboBox::currentIndexChanged, this, [=] (int stepIndex) {
//        ui->tutorialTextBrowser->setTutorialStep(stepIndex + 1);
//    });
//    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [=] (int stepID) {
//        ui->stepSelect->setCurrentIndex(stepID-1);
//    });


//    connect(ui->homeButton, &QPushButton::pressed, this, [=] () {
//       ui->tutorialTextBrowser->setTutorialStep(-1);
//       ui->stepSelect->setCurrentIndex(-1);
//    });





}

/*
 *
*/
Cube2dWindow::~Cube2dWindow()
{
    vctrTester.clear(); //prolly don't need this at all but gonna for sure move this when the vctrlis are all implemented for all faces
    delete ui;
}

void Cube2dWindow::createBtnConnection(){
    connect(ui->leftPushBtn,&QPushButton::clicked,this,&Cube2dWindow::on_leftPushBtn_clicked);
    connect(ui->rightPushBtn,&QPushButton::clicked,this,&Cube2dWindow::on_rightPushBtn_clicked);
    connect(ui->upPushBtn,&QPushButton::clicked,this,&Cube2dWindow::on_upPushBtn_clicked);
}

/*
 *This is a public slot for the Rubik's main window to call when the action from the menu bar is triggered to open this window
*/
void Cube2dWindow::open2DCubeWindow(){

    this->show();

}
void Cube2dWindow::on_leftPushBtn_clicked()
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
            tempItemReference = scene1->addPath(path1);
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
}


void Cube2dWindow::on_rightPushBtn_clicked()
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
            tempItemReference = scene1->addPath(path2);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(QColor(255,165,0));
        }

    }
}


void Cube2dWindow::on_upPushBtn_clicked()
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
            tempItemReference = scene1->addPath(path3);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::blue);
        }
    }

}


/*
 *left side
*/
void Cube2dWindow::createLeftOfCube(){

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
            tempItemReference = scene1->addPath(path1);
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
void Cube2dWindow::createRightOfCube(){
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
            tempItemReference = scene1->addPath(path2);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::red);
        }

    }
}

/*
 *top side
*/
void Cube2dWindow::createTopOfCube(){

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
            tempItemReference = scene1->addPath(path3);
            vctrTester.append(tempItemReference);

            tempItemReference->setBrush(Qt::green);
        }
    }

}


/*
 *TODO
*/
void Cube2dWindow::update2DCubeView(std::vector<QImage> faces)
{

    QImage centerFace = faces.back();
    faces.pop_back();
    QImage centerFaceScaled = centerFace.scaled(120,120);
    updateFace0(centerFace,centerFaceScaled);

    QImage rightFace = faces.back();
    faces.pop_back();
    QImage rightFaceScaled = rightFace.scaled(120,120);
    updateFace1(rightFace,rightFaceScaled);

    QImage leftFace = faces.back();
    faces.pop_back();
    QImage leftFaceScaled = leftFace.scaled(120,120);
    updateFace2(leftFace,leftFaceScaled);

    QImage topFace = faces.back();
    faces.pop_back();
    QImage topFaceScaled = topFace.scaled(120,120);
    updateFace3(topFace,topFaceScaled);

    QImage bottomFace = faces.back();
    faces.pop_back();
    QImage bottomFaceScaled = bottomFace.scaled(120,120);
    updateFace4(bottomFace,bottomFaceScaled);

    QImage farRightFace = faces.back();
    faces.pop_back();
    QImage farRightFaceScaled = farRightFace.scaled(120,120);
    updateFace5(farRightFace,farRightFaceScaled);

}

/*
 *TODO
*/
void Cube2dWindow::updateFace0(QImage face0,QImage scaled ){
    //ui->face0->setPixmap(QPixmap::fromImage(scaled));

//    ui->face0->setScaledContents( true );
//    ui->face0->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}

/*
 *TODO
*/
void Cube2dWindow::updateFace1(QImage face1,QImage scaled ){
    //ui->face1->setPixmap(QPixmap::fromImage(scaled));

}

/*
 *TODO
*/
void Cube2dWindow::updateFace2(QImage face2,QImage scaled ){
   // ui->face2->setPixmap(QPixmap::fromImage(scaled));

}
/*
 *TODO
*/
void Cube2dWindow::updateFace3(QImage face3,QImage scaled ){
   // ui->face3->setPixmap(QPixmap::fromImage(scaled));

}

/*
 *TODO
*/
void Cube2dWindow::updateFace4(QImage face4,QImage scaled ){
   // ui->face4->setPixmap(QPixmap::fromImage(scaled));

}

/*
 *TODO
*/
void Cube2dWindow::updateFace5(QImage face5,QImage scaled ){
     //  ui->face5->setPixmap(QPixmap::fromImage(scaled));
}



