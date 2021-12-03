#include "mainwindow.h"
#include "model.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,Model *model)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//#include "rubiksedu.h"
//#include "ui_RubiksEdu.h"

//RubiksEdu::RubiksEdu(QWidget *parent, Model *model)
//    : QMainWindow(parent)
//    , ui(new Ui::RubiksEdu)
//{
//    ui->setupUi(this);
//}

//RubiksEdu::~RubiksEdu()
//{
//    delete ui;
//}
