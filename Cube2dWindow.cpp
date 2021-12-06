#include "Cube2dWindow.h"
#include "ui_Cube2dWindow.h"

Cube2dWindow::Cube2dWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cube2dWindow)
{
    ui->setupUi(this);
}

Cube2dWindow::~Cube2dWindow()
{
    delete ui;
}
