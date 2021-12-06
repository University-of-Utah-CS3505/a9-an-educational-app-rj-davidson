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

void Cube2dWindow::on_leftPushBtn_clicked()
{

}


void Cube2dWindow::on_rightPushBtn_clicked()
{

}


void Cube2dWindow::on_upPushBtn_clicked()
{

}

