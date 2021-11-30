#include "RubiksEdu.h"
#include "ui_RubiksEdu.h"

RubiksEdu::RubiksEdu(QWidget *parent, Model *model)
    : QMainWindow(parent)
    , ui(new Ui::RubiksEdu)
{
    ui->setupUi(this);
}

RubiksEdu::~RubiksEdu()
{
    delete ui;
}

