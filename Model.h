#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QImage>
#include <queue>
#include <vector>
#include <QString>
#include "Cube.h"

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

signals:
    void updateCube(std::vector<QImage>); // TODO: What data type to send?

public slots:
    void setCurrentFace(int);
    void setEduMode(int);
    void moveCube(int);
    void moveLeftBottom();
    void moveLeftMid();
    void moveLeftTop();
    void moveTopLeft();
    void moveTopMid();
    void moveTopRight();
    void moveRightTop();
    void moveRightMid();
    void moveRightBttm();
    void moveBttmRight();
    void moveBttmMid();
    void moveBttmLeft();

private:
    Cube cube;
    std::queue<int[2]> moveTracker;
    std::queue<QString> hintTracker;
    bool setupMode;

    void moveWorker(int);
    void setupAndRandomizeCube();

};

#endif // MODEL_H
