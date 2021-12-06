#ifndef RUBIKSEDU_H
#define RUBIKSEDU_H

#include <QMainWindow>
#include "Model.h"
#include "CubeController.h"
#include <QImage>
#include <vector>
#include "Cube2dWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RubiksEdu; }
QT_END_NAMESPACE

class RubiksEdu : public QMainWindow
{
    Q_OBJECT

public:
     RubiksEdu(QWidget *parent = nullptr, CubeController *controller = nullptr,Cube2dWindow *cube2dWindow=nullptr);
    ~RubiksEdu();

private slots:
    void on_topLeftButton_clicked();

    void on_topRightButton_clicked();

    void on_leftTopButton_clicked();

    void on_leftBttmButton_clicked();

    void on_bttmLeftButton_clicked();

    void on_bttmRightButton_clicked();

    void on_rightBttmButton_clicked();
    void on_rightTopButton_clicked();
    void displayCube(std::vector<QImage>);
signals:
    void sendMove(int);
private:
    Ui::RubiksEdu *ui;


};
#endif // RUBIKSEDU_H
