#include "ViewCube.h"
#include <iostream>

ViewCube::ViewCube(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}

// Sends a signal if the mouse was clicked
void ViewCube::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();

    if (pos.x() >= 0 && pos.x() <= 120 && pos.y() >= 160 && pos.y() <= 280){
        std::cout << "1" << std::endl;
        emit faceSelected(1);
    }
    else if (pos.x() >= 160 && pos.x() <= 280 && pos.y() >= 0 && pos.y() <= 120){
        std::cout << "2" << std::endl;
        emit faceSelected(2);
    }
    else if (pos.x() >= 320 && pos.x() <= 440 && pos.y() >= 160 && pos.y() <= 280){
        std::cout << "3" << std::endl;
        emit faceSelected(3);
    }
    else if (pos.x() >= 160 && pos.x() <= 280 && pos.y() >= 320 && pos.y() <= 440){
        std::cout << "4" << std::endl;
        emit faceSelected(4);
    }
    else if (pos.x() >= 480 && pos.x() <= 600 && pos.y() >= 160 && pos.y() <= 280){
        std::cout << "5" << std::endl;
        emit faceSelected(5);
    }
}
