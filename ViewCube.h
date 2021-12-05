#ifndef VIEWCUBE_H
#define VIEWCUBE_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>

class ViewCube : public QWidget
{
    Q_OBJECT
public:
    explicit ViewCube(QWidget *parent = nullptr);

    // Handles if the mouse was clicked
    void mousePressEvent(QMouseEvent *event);

signals:
    void faceSelected(int);
};

#endif // VIEWCUBE_H
