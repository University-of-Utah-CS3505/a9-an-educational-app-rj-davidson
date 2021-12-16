// Used for Cursor and Click tracking in the view.

#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QWidget>

class CubeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CubeWidget(QWidget *parent = nullptr);

signals:
};

#endif // CUBEWIDGET_H
