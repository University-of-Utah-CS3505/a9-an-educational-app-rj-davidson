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
    emit send3DRotation("Left");
}

/*
 *3d
*/
void RubiksEdu::on_pushRightButton_clicked()
{
        emit send3DRotation("Right");

}

/*
 *3d
*/
void RubiksEdu::on_pushUpBtn_clicked()
{
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

    connect(this, &RubiksEdu::send3DRotation,controller,&CubeController::rotationCube);
}

