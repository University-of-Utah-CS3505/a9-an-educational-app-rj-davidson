#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QObject>
#include <QWidget>

class CubeWidget:public QWidget
{
public:
    CubeWidget();
    explicit CubeWidget(QWidget *parent = nullptr);

    signals:
};

#endif // CUBEWIDGET_H
