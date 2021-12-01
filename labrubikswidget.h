#ifndef LABRUBIKSWIDGET_H
#define LABRUBIKSWIDGET_H

#include <box2d/box2d.h>

#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QWidget>

class LabRubiksWidget : public QWidget {
  Q_OBJECT
 public:
  explicit LabRubiksWidget(QWidget* parent = nullptr);

 signals:

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  QPixmap pm;
  b2World world;
  b2Body* ground;
  b2Body* cube;
  QTimer worldTimer;
};

#endif  // LABRUBIKSWIDGET_H
