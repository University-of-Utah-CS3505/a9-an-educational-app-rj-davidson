#ifndef WINDOW3DCUBE_H
#define WINDOW3DCUBE_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtCore>
#include <QtWidgets>
#include <QGraphicsWidget>
#include <QtStateMachine/QStateMachine>
#include <QtStateMachine/QState>
#include <QtStateMachine/QAbstractTransition>
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


using namespace std;




namespace Ui {
class Window3DCube;
}

class Window3DCube : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window3DCube(QWidget *parent = nullptr);
    ~Window3DCube();

public slots:
    void open3DCubeWindow();




private slots:
    void on_leftPushBtn_clicked();

private:
    Ui::Window3DCube *ui;
QGraphicsScene *scene1;
QGraphicsPathItem *itemRLeft;
QGraphicsPathItem *itemRRight;
QGraphicsPathItem *itemRTop;
QVector<QGraphicsPathItem*> vector;


QPainterPath path1;
QPainterPath path2;
QPainterPath path3;

void createLeftOfCube();
void createRightOfCube();
void createTopOfCube();

//float cubeSize,eSizexPosxScale,eSize,point1,point2,point3,point4,point1x,point1y,point2x,point2y,point3x,point3y,point4x,point4y,viewAngle,xScale,yScale,eSizePosxScale,eSizeyPos;

float cubeSize = 120;

float eSize = cubeSize / 3; //size of each element

// (0,0) is at bottom piont on cube
//
// so left view is negative, right view is positive


//float viewAngle = 30;

float xScale = 0.866025403784; //cos(30deg)

float yScale = 0.5;		//sin(30deg)


float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;

void save2DCubeXY();

};

#endif // WINDOW3DCUBE_H
