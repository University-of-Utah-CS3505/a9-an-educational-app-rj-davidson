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


/*
 * TODO Elizabeth
 *
 *
*/
void Model::moveCube(int moveID) // TODO: moveWorker and moveCube do the same thing?
{
    moveWorker(moveID);
}


/*
 * TODO Elizabeth
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
 * TODO Elizabeth
 *
 *
*/
void Model::setupAndRandomizeCube()
{
    setupMode = true;
    //make new cube object here

    for (int i = 0; i < 20; i++)
    {
        // Randomize Moves and Store to
        //make a bunch of random cubes
        //randomize face 0-5
        //randomize moveid 0-7

    }
    //set new cube object but don't modify the cube in use until the very end this way it gets sent in the end
    cube.setCurrentFace(0);
    setupMode = false;
    //emit updateCube(pass list of qImages);
}
