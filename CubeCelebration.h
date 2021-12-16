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

namespace Ui
{
    class CubeCelebration;
}

class CubeCelebration : public QDialog
{
    Q_OBJECT

public:
    explicit CubeCelebration(QWidget *parent = nullptr);
    ~CubeCelebration();

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::CubeCelebration *ui;
    QPixmap pmGreen, pmRed, pmYellow, pmWhite, pmOrange, pmBlue;
    b2World world;
    b2Body *ground;
    b2Body *greenCube;
    b2Body *redCube;
    b2Body *yellowCube;
    b2Body *whiteCube;
    b2Body *orangeCube;
    b2Body *blueCube;
    QTimer worldTimer;
    std::vector<b2Body *> cubes;
};

#endif // CUBECELEBRATION_H
