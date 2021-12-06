#include "controller2dcube.h"
#include "ui_controller2dcube.h"

Controller2DCube::Controller2DCube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller2DCube)
{
    ui->setupUi(this);
}

Controller2DCube::~Controller2DCube()
{
    delete ui;
}
