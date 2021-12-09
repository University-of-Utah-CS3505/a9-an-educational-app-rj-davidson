#ifndef RUBIKSCELEBRATION_H
#define RUBIKSCELEBRATION_H

#include <QWidget>

#include <box2d/box2d.h>

#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QWidget>

class RubiksCelebration : public QWidget
{
    Q_OBJECT
public:
    explicit RubiksCelebration(QWidget *parent = nullptr);

signals:

};

#endif // RUBIKSCELEBRATION_H



//class LabRubiksWidget : public QWidget {
//  Q_OBJECT
// public:
//  explicit LabRubiksWidget(QWidget* parent = nullptr);

// signals:

// protected:
//  void paintEvent(QPaintEvent* event) override;
//  void keyPressEvent(QKeyEvent* event) override;

// private:
//  QPixmap pm;
//  b2World world;
//  b2Body* ground;
//  b2Body* cube;
//  QTimer worldTimer;
//};
