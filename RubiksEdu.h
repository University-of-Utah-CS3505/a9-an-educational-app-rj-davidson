#ifndef RUBIKSEDU_H
#define RUBIKSEDU_H

#include <QMainWindow>
#include "CubeController.h"
#include <QImage>
#include <vector>
#include <QGraphicsScene>
#include "Cube2dWindow.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class RubiksEdu; }
QT_END_NAMESPACE

class RubiksEdu : public QMainWindow
{
    Q_OBJECT

public:
     RubiksEdu(QWidget *parent = nullptr, CubeController *controller = nullptr, TutorialBrowser *tutorial =nullptr);
    ~RubiksEdu();



private slots:
    void on_topLeftButton_clicked();

    void on_topRightButton_clicked();

    void on_leftTopButton_clicked();

    void on_leftBttmButton_clicked();

    void on_bttmLeftButton_clicked();

    void on_bttmRightButton_clicked();

    void on_rightBttmButton_clicked();
    void on_rightTopButton_clicked();
    void displayCube(std::vector<QImage>);

    void on_clockwiseButton_clicked();

    void on_counterClockwiseButton_clicked();

    //3d stuff
    void on_pushLeftBtn_clicked();
    void on_pushRightButton_clicked();
    void on_pushUpBtn_clicked();
    void on_3DCubeCreation(QGraphicsScene *scene);





signals:
    void sendMove(int);

    //3d stuff
    void send3DRotation(string dirRotation);
   // void createNew3DCube(QGraphicsScene *scene3D);

private:
    Ui::RubiksEdu *ui;

    //3d scene
    QGraphicsScene *scene3D;
    //3d cube stuff
    void createBtnConnection();
    void connectControllerView(CubeController *controller);


    //tester
    void createLeftOfCube();
    void createRightOfCube();
    void createTopOfCube();
    float cubeSize = 120;
    float eSize = cubeSize / 3; //size of each element

    // (0,0) is at bottom piont on cube
    // so left view is negative, right view is positive
    float xScale = 0.866025403784; //cos(30deg)
    float yScale = 0.5;		//sin(30deg)
    float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;

    QPainterPath path1;
    QPainterPath path2;
    QPainterPath path3;

    QGraphicsScene *scene;
    QGraphicsPathItem *itemRLeft;
    QGraphicsPathItem *itemRRight;
    QGraphicsPathItem *itemRTop;

    QVector<QGraphicsPathItem*> vctrTester;//Tester only will need to be deleted when all of the face vectors are being saved into their own vectors
    QVector<QGraphicsPathItem*> vctrVisibleFaceTop;
    QVector<QGraphicsPathItem*> vctrVisibleFaceRight;
    QVector<QGraphicsPathItem*> vctrVisibleFaceLeft;

};
#endif // RUBIKSEDU_H

//TODO refactor notes for 3dCube
//#ifndef VIEW3DCUBE_H
//#define VIEW3DCUBE_H

//#include <QObject>
//#include <QWidget>
//#include <QMainWindow>
//#include <QGraphicsView>
//#include <QtWidgets>
//#include <QGraphicsWidget>
//#include <QGraphicsRectItem>
//#include <QGraphicsScene>
//#include <QPainterPath>
//#include <QRectF>
//#include <QSize>
//#include <QDebug>
//#include <QImage>
//#include <QByteArray>
//#include <QVector>
//#include <iostream>
//#include <QString>
//#include <QPushButton>

//#include "Cube.h"


//using namespace std;

///*
// * controller tells view to update visible faces of cube
// *
// * the view tels the controller when there is user action
// *
// *In real time the 3d cube will change with the main 1d cube
// *
// *Controller will tell view to redraw when the button's changing up, right, left 180deg accordingly
// *
//*/
//class View3DCube: public QObject
//{
//    Q_OBJECT
//public:
//    View3DCube();
//    //View3DCube(QWidget *parent=nullptr);

//signals:
//    void show3DCube(QGraphicsScene *scene);
//    void update3DCubeScene();
//    //the view tels the controller when there is user action
//    void leftPushBtnClicked();
//    void rightPushBtnClicked();
//    void upPushBtnClicked();

//public slots:
//    //controller tells view to update visible faces of cube
//    void updateVisibleFaces(vector<QImage>);
//    void updateBtnClicked(string dir);
//    void createUser3DCube();

//private slots:

//private:
//    float cubeSize = 120;
//    float eSize = cubeSize / 3; //size of each element

//    // (0,0) is at bottom piont on cube
//    // so left view is negative, right view is positive
//    float xScale = 0.866025403784; //cos(30deg)
//    float yScale = 0.5;		//sin(30deg)
//    float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;

//    QPainterPath path1;
//    QPainterPath path2;
//    QPainterPath path3;

//    QGraphicsScene *scene;
//    QGraphicsPathItem *itemRLeft;
//    QGraphicsPathItem *itemRRight;
//    QGraphicsPathItem *itemRTop;

//    QVector<QGraphicsPathItem*> vctrTester;//Tester only will need to be deleted when all of the face vectors are being saved into their own vectors
//    QVector<QGraphicsPathItem*> vctrVisibleFaceTop;
//    QVector<QGraphicsPathItem*> vctrVisibleFaceRight;
//    QVector<QGraphicsPathItem*> vctrVisibleFaceLeft;

//    void create3DCube();
//    void createLeftFace();
//    void createRightFace();
//    void createTopFace();

//    //In real time the 3d cube will change with the main 1d cube
//    //Controller will tell view to redraw when the button's changing up, right, left 180deg accordingly
//    void redraw3DCube(std::vector<QImage>);
//    void redrawLeftFace(std::vector<QImage>);
//    void redrawRightFace(std::vector<QImage>);
//    void redrawTopFace(std::vector<QImage>);




//};

//#endif // VIEW3DCUBE_H
