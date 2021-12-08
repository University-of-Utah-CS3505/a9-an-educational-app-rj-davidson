#ifndef RUBIKSEDU_H
#define RUBIKSEDU_H

#include <QMainWindow>
#include "CubeController.h"
#include <QImage>
#include <vector>
#include "Cube2dWindow.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class RubiksEdu; }
QT_END_NAMESPACE

class RubiksEdu : public QMainWindow
{
    Q_OBJECT

public:
     RubiksEdu(QWidget *parent = nullptr, CubeController *controller = nullptr, TutorialBrowser *tutorial =nullptr);
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

    void on_clockwiseButton_clicked();

    void on_counterClockwiseButton_clicked();

    //3d stuff
    void on_pushLeftBtn_clicked();
    void on_pushRightButton_clicked();
    void on_pushUpBtn_clicked();

signals:
    void sendMove(int);

    //3d stuff
    void send3DRotation(string dirRotation);

private:
    Ui::RubiksEdu *ui;

    //3d cube stuff
    void createBtnConnection();
    void connectControllerView(CubeController *controller);


};
#endif // RUBIKSEDU_H
