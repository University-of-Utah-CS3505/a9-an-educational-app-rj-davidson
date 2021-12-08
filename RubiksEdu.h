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
