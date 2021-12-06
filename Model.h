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
    void moveWorker(int);
signals:
    void updateCube(std::vector<QImage>); // TODO: What data type to send?

public slots:
    void setCurrentFace(int);
    void setEduMode(int);
private:
    Cube cube;
    std::queue<int> moveTracker; //TODO: Tuple??
    std::queue<QString> hintTracker;
    bool setupMode;
    void setupAndRandomizeCube();

};

#endif // MODEL_H
