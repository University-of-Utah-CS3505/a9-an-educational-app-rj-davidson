#ifndef RUBIKSEDU_H
#define RUBIKSEDU_H

#include <QMainWindow>
#include "CubeController.h"
#include "TutorialBrowser.h"
#include "CubeCelebration.h"
#include <QImage>
#include <vector>
#include <QGraphicsScene>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class RubiksEdu;
}
QT_END_NAMESPACE

class RubiksEdu : public QMainWindow
{
    Q_OBJECT

public:
    RubiksEdu(QWidget *parent = nullptr, CubeController *controller = nullptr);
    ~RubiksEdu();

private slots:
    void switchButtonMode(int modeID);

    void on_topLeftButton_clicked();

    void on_topRightButton_clicked();

    void on_leftTopButton_clicked();

    void on_leftBttmButton_clicked();

    void on_bttmLeftButton_clicked();

    void on_bttmRightButton_clicked();

    void on_rightBttmButton_clicked();
    void on_rightTopButton_clicked();
    void displayCube(QVector<QImage>);

    void on_clockwiseButton_clicked();

    void on_counterClockwiseButton_clicked();

    void showCelebration();

    // cube3Dview stuff
    void on_pushLeftBtn_clicked();
    void on_pushRightBtn_clicked();
    void on_pushUpBtn_clicked();

    void cube3DpaintVisibleFacesSimple(QVector<char> &visibleFaces);
    void cube3DpaintVisibleFaces(QVector<CubeFace> &visibleFaces);

    void on_checkButton_clicked();

signals:
    void sendMove(int);
    void checkButton();
    // cube3Dview stuff
    void send3DRotation(const string &dirRotation);

private:
    Ui::RubiksEdu *ui;

    // 3d scene
    QGraphicsScene *scene3D;
    // 3d cube stuff
    void connectControllerView(CubeController *controller);

    // tester
    void createLeftOfCube();
    void createRightOfCube();
    void createTopOfCube();
    const float cubeSize = 120;
    const float eSize = cubeSize / 3; // size of each element

    // (0,0) is at bottom piont on cube
    // so left view is negative, right view is positive
    const float xScale = 0.866025403784; // cos(30deg)
    const float yScale = 0.5;            // sin(30deg)
    float point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y;

    QVector<QGraphicsPathItem *> vctrVisibleFaceTop;
    QVector<QGraphicsPathItem *> vctrVisibleFaceRight;
    QVector<QGraphicsPathItem *> vctrVisibleFaceLeft;

    void repaintLeftFace(QColor colorToPaint);
    void repaintRightFace(QColor colorToPaint);
    void repaintTopFace(QColor colorToPaint);

    void repaintLeftFace(CubeFace faceToPaint);
    void repaintRightFace(CubeFace faceToPaint);
    void repaintTopFace(CubeFace faceToPaint);

    QColor getColorFromChar(char charColor);
};
#endif // RUBIKSEDU_H
