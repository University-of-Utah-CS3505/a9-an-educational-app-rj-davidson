#include "RubiksEdu.h"
#include "ui_RubiksEdu.h"
#include "Window2dCube.h"
#include <QMenuBar>
#include <QMainWindow>
#include <QAction>

RubiksEdu::RubiksEdu(QWidget *parent, Model *model,Window2DCube *window2DCube)
    : QMainWindow(parent)
    , ui(new Ui::RubiksEdu)
{
    ui->setupUi(this);

    // TODO: delete, this is for testing:
    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [] (int step) {
        qDebug() << step;
    });

   connect(ui->actionUse_2D_Cube,&QAction::triggered,window2DCube,&Window2DCube::open2DCubeWindow);

}

RubiksEdu::~RubiksEdu()
{
    delete ui;
}


