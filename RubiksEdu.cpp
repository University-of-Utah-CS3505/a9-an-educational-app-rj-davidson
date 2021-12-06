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

    // Tutorial Widget Connections
    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [] (int step) {
        qDebug() << step;
    });
    connect(ui->stepSelect, &QComboBox::currentIndexChanged, this, [=] (int stepIndex) {
        ui->tutorialTextBrowser->setTutorialStep(stepIndex + 1);
    });
    connect(ui->tutorialTextBrowser, &TutorialBrowser::tutorialStepChanged, this, [=] (int stepID) {
        ui->stepSelect->setCurrentIndex(stepID-1);
    });
    connect(ui->homeButton, &QPushButton::pressed, this, [=] () {
       ui->tutorialTextBrowser->setTutorialStep(-1);
       ui->stepSelect->setCurrentIndex(-1);
    });

   connect(ui->actionUse_2D_Cube,&QAction::triggered,window2DCube,&Window2DCube::open2DCubeWindow);

}

RubiksEdu::~RubiksEdu()
{
    delete ui;
}


