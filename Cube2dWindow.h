#ifndef CUBE2DWINDOW_H
#define CUBE2DWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainterPath>
#include <QRectF>
#include <QSize>
#include <QDebug>
#include <QImage>
#include <QByteArray>
#include <QVector>
#include <iostream>
#include <QString>
#include <QPushButton>

#include "Cube.h"
#include "CubeController.h"
#include "TutorialBrowser.h"

using namespace std;

namespace Ui {
class Cube2dWindow;
}

class Cube2dWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cube2dWindow(QWidget *parent = nullptr,CubeController *controller=nullptr);
    ~Cube2dWindow();

public slots:
    void open2DCubeWindow();



private slots:
    void on_leftPushBtn_clicked();

    void on_rightPushBtn_clicked();

    void on_upPushBtn_clicked();

    //the cube controller will tell what to display at the same time as the mainwindow cube
    void update2DCubeView(std::vector<QImage>);


private:
    Ui::Cube2dWindow *ui;
    QGraphicsScene *scene1;
    QGraphicsPathItem *itemRLeft;
    QGraphicsPathItem *itemRRight;
    QGraphicsPathItem *itemRTop;

    QVector<QGraphicsPathItem*> vctrTester;//Tester only will need to be deleted when all of the face vectors are being saved into their own vectors
    QVector<QGraphicsPathItem*> vctrFace0;
    QVector<QGraphicsPathItem*> vctrFace1;
    QVector<QGraphicsPathItem*> vctrFace2;
    QVector<QGraphicsPathItem*> vctrFace3;
    QVector<QGraphicsPathItem*> vctrFace4;
    QVector<QGraphicsPathItem*> vctrFace5;



    QPainterPath path1;
    QPainterPath path2;
    QPainterPath path3;

    void createLeftOfCube();
    void createRightOfCube();
    void createTopOfCube();

    float cubeSize = 120;

    float eSize = cubeSize / 3; //size of each element

    // (0,0) is at bottom piont on cube
    //
    // so left view is negative, right view is positive

    float xScale = 0.866025403784; //cos(30deg)

    float yScale = 0.5;		//sin(30deg)


    float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;

    void createBtnConnection();

//    Cube userCube;
//    void setupAndRandomizeCube();
//    void setEduMode(int);

    void updateFace0(QImage f0,QImage scaled);
    void updateFace1(QImage f1,QImage scaled);
    void updateFace2(QImage f2,QImage scaled);
    void updateFace3(QImage f3,QImage scaled);
    void updateFace4(QImage f4,QImage scaled);
    void updateFace5(QImage f5,QImage scaled);


};

#endif // CUBE2DWINDOW_H
