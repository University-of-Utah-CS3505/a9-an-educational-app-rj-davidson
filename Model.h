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

private:
    Cube cube;
    std::queue<int> moveTracker; //TODO: Tuple??
    std::queue<QString> hintTracker;
    bool setupMode;

    void moveWorker(int);
    void setupAndRandomizeCube();

};

#endif // MODEL_H
