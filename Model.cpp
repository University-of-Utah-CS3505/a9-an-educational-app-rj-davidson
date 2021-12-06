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
    emit updateCube(cube.toQImageList());
}


/*
 * TODO Elizabeth
 *Delete
 *
*/
void Model::moveCube(int moveID) // TODO: moveWorker and moveCube do the same thing?
{
    moveWorker(moveID);
}


/*
 * TODO but needs to be deleted if there is not moveTracker is used
 *
 *
*/
void Model::moveWorker(int moveID)
{
    cube.move(moveID);
    if (!setupMode)
    {
        //TODO: Check if the move is correct, if not add to both moveTracker and hintTracker Queues
    }
    emit updateCube(cube.toQImageList());
}


//createNewCube()

/*
 *
 *make a bunch of random cube
 *might need to be more logic here because there will need to be a move tracker maybe
 *
*/
void Model::setupAndRandomizeCube()
{
    setupMode = true;
    //make new cube object here
    Cube cubeTemp;

    for (int i = 0; i < 20; i++)
    {
        //randomize face 0-5
        cubeTemp.setCurrentFace(rand()%6);
        cubeTemp.move(rand()%8);
    }
    //set new cube object but don't modify the cube in use until the very end this way it gets sent in the end
    cube=cubeTemp;
    cube.setCurrentFace(0);
    setupMode = false;
    //emit updateCube(pass list of qImages);
}
