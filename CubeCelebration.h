#ifndef CUBECELEBRATION_H
#define CUBECELEBRATION_H

#include <QDialog>
#include <QWidget>
#include <box2d/box2d.h>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <vector>


namespace Ui {
class CubeCelebration;
}

class CubeCelebration : public QDialog
{
    Q_OBJECT

public:
    explicit CubeCelebration(QWidget *parent = nullptr, bool *complete = nullptr);
    ~CubeCelebration();


signals:

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::CubeCelebration *ui;
    QPixmap pmGreen, pmRed, pmYellow, pmWhite, pmOrange, pmBlue, pmW, pmL, pmCoal;
    b2World world;
    b2Body* ground;
//    b2Body* leftWall;
//    b2Body* rightWall;
    b2Body* greenCube;
    b2Body* redCube;
    b2Body* yellowCube;
    b2Body* whiteCube;
    b2Body* orangeCube;
    b2Body* blueCube;
    b2Body* wCube;
    b2Body* lCube;
    b2Body* coalCube;
    QTimer worldTimer;
    QVector<b2Body*> cubes;
    bool completed;
};

#endif // CUBECELEBRATION_H

