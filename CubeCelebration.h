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


namespace Ui {
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
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::CubeCelebration *ui;
    QPixmap pm;
    b2World world;
    b2Body* ground;
    b2Body* cube;
    QTimer worldTimer;

};

#endif // CUBECELEBRATION_H

