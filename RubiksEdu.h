#ifndef RUBIKSEDU_H
#define RUBIKSEDU_H

#include <QMainWindow>
#include "Model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RubiksEdu; }
QT_END_NAMESPACE

class RubiksEdu : public QMainWindow
{
    Q_OBJECT

public:
    RubiksEdu(QWidget *parent = nullptr, Model *model = nullptr);
    ~RubiksEdu();

private:
    Ui::RubiksEdu *ui;
};
#endif // RUBIKSEDU_H
