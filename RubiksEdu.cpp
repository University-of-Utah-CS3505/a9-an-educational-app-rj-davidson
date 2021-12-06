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

   connect(ui->actionUse_2D_Cube,&QAction::triggered,cube2dWindow,&Cube2dWindow::open2DCubeWindow);

}

RubiksEdu::~RubiksEdu()
{
    delete ui;
}


