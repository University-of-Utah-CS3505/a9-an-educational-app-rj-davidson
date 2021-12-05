#ifndef WINDOW3DCUBE_H
#define WINDOW3DCUBE_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtCore>
#include <QtWidgets>
#include <QGraphicsWidget>
#include <QtStateMachine/QStateMachine>
#include <QtStateMachine/QState>
#include <QtStateMachine/QAbstractTransition>


namespace Ui {
class Window3DCube;
}

class Window3DCube : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window3DCube(QWidget *parent = nullptr);
    ~Window3DCube();

public slots:
    void open3DCubeWindow();



private:
    Ui::Window3DCube *ui;



};

#endif // WINDOW3DCUBE_H
