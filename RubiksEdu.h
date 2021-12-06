#ifndef RUBIKSEDU_H
#define RUBIKSEDU_H

#include <QMainWindow>
#include "Model.h"
#include "Window2dCube.h"
#include "Cube2dWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RubiksEdu; }
QT_END_NAMESPACE

class RubiksEdu : public QMainWindow
{
    Q_OBJECT

public:
//    RubiksEdu(QWidget *parent = nullptr, Model *model = nullptr,Window2DCube *window2DCube=nullptr);
     RubiksEdu(QWidget *parent = nullptr, Model *model = nullptr,Cube2dWindow *cube2dWindow=nullptr);
    ~RubiksEdu();

private:
    Ui::RubiksEdu *ui;


};
#endif // RUBIKSEDU_H
