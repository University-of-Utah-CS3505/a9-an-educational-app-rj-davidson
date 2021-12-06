#include "RubiksEdu.h"
#include "ui_RubiksEdu.h"

#include <QMenuBar>
#include <QMainWindow>
#include <QAction>

RubiksEdu::RubiksEdu(QWidget *parent, Model *model,Cube2dWindow *cube2dWindow)
    : QMainWindow(parent)
    , ui(new Ui::RubiksEdu)
{
    ui->setupUi(this);

    connect(ui->actionUse_2D_Cube,&QAction::triggered,cube2dWindow,&Cube2dWindow::open2DCubeWindow);
        // TODO: delete, this is for testing:
    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [] (int step) {
        qDebug() << step;
    });
}

RubiksEdu::~RubiksEdu()
{
    delete ui;
}


