#ifndef CONTROLLER2DCUBE_H
#define CONTROLLER2DCUBE_H

#include <QMainWindow>

namespace Ui {
class Controller2DCube;
}

class Controller2DCube : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller2DCube(QWidget *parent = nullptr);
    ~Controller2DCube();

private:
    Ui::Controller2DCube *ui;
};

#endif // CONTROLLER2DCUBE_H
