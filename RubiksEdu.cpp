#include "RubiksEdu.h"
#include "ui_RubiksEdu.h"
#include "Window2dCube.h"
#include "ui_window3dcube.h"
#include <QMenuBar>
#include <QMainWindow>
#include <QAction>

RubiksEdu::RubiksEdu(QWidget *parent, Model *model,Window3DCube *window3DCube)
    : QMainWindow(parent)
    , ui(new Ui::RubiksEdu)
{
    ui->setupUi(this);

   connect(ui->actionUse_3D_Cube,&QAction::triggered,window3DCube,&Window3DCube::open3DCubeWindow);

}

RubiksEdu::~RubiksEdu()
{
    delete ui;
}


