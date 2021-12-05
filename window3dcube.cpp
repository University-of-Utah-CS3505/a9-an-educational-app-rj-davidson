#include "window3dcube.h"
#include "ui_window3dcube.h"

Window3DCube::Window3DCube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window3DCube)
{
    ui->setupUi(this);
}

Window3DCube::~Window3DCube()
{
    delete ui;
}

void Window3DCube::open3DCubeWindow(){
    this->show();
}
