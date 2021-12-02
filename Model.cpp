#include "Model.h"

Model::Model(QObject *parent) : QObject(parent)
{
    setupMode = false;
}

void Model::setCurrentFace(int i)
{
    cube.setCurrentFace(i);
}

void Model::setEduMode(int i)
{
    switch(i)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        setupAndRandomizeCube();
    }
}

void Model::moveCube(int moveID)
{
    moveWorker(moveID);
}

void Model::moveWorker(int moveID)
{
    cube.move(moveID);
    if (!setupMode)
    {
        //TODO: Check if the move is correct, if not add to both moveTracker and hintTracker Queues
    }
    emit updateCube(cube.toQImageList());
}

void Model::setupAndRandomizeCube()
{
    setupMode = true;
    for (int i = 0; i < 20; i++)
    {
        // Randomize Moves and Store to
    }
    cube.setCurrentFace(0);
    setupMode = false;
}
