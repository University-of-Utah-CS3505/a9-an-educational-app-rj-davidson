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
#include <QMatrix3x3>

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



private:
    Ui::Window3DCube *ui;
QGraphicsScene *scene1;
QGraphicsRectItem *faceWidget1;
QGraphicsPathItem *itemR;

QPainterPath path1;
QPainterPath path2;
QPainterPath path3;

//float cubeSize,eSizexPosxScale,eSize,point1,point2,point3,point4,point1x,point1y,point2x,point2y,point3x,point3y,point4x,point4y,viewAngle,xScale,yScale,eSizePosxScale,eSizeyPos;




};

#endif // WINDOW3DCUBE_H
