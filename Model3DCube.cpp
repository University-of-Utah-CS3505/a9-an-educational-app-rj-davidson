/*
 * Lacking Ideas - Rubiks Educational App
 * CS 3505 - A9 - An Education App
 * @authors: Elizabeth Thomas
 * Model3DCube.cpp
*/

#include "Model3DCube.h"

/*
 *tester code to have a cube to send to view before connecting with actual cube data
 */
Model3DCube::Model3DCube()
{
    cubeCopyOf1D = Cube();
}

/*
 * Resets the orientation of the cube to the current face
 * Added by: Maiko Tuitupou
 */
void Model3DCube::resetOrientation()
{
    setRotationToCurrentFace();
    updateVisibleFaces();
}

/*
 *the cube controller will tell what to display at the same time as the mainwindow cube
 */
void Model3DCube::update3DCube(Cube const &cube1D)
{
    cubeCopyOf1D = cube1D;

    if (cubeCopyOf1D.getCurrentFaceID() != previouslyFocusedFaceID)
    {
        setRotationToCurrentFace();
        previouslyFocusedFaceID = cubeCopyOf1D.getCurrentFaceID();
    }

    // We want the non-rotated cube
    cubeCopyOf1D = cubeCopyOf1D.getBaseCube();

    // Flip the back face since it is flipped in the model
    cubeCopyOf1D.flipBackFace();

    convertCube1DtoCube3D();
    updateVisibleFaces();
}

/*
 *
 *3D cube assumes the faces are stored in the following order
 *
 *    deg0,  deg90, deg180, deg270,  up   ,  down
 *
 *    'g' ,  'y'  ,  'b'  ,  'w'  ,  'r'  ,  'o'
 *
 *    This function maps the 2d cube face order to the order listed above.
 */
void Model3DCube::convertCube1DtoCube3D()
{

    QVector<CubeFace> cube1Dfaces = cubeCopyOf1D.getAllFaces();
    QVector<CubeFace> cube3Dfaces;

    for (int i = 0; i < 6; i++)
    {
        CubeFace tempFace = cube1Dfaces.at(conversionMap[i]);
        // flip all faces vertically so that zero position and x-axis, y-axis orientations of 3D cube match 2D cube.
        tempFace.flipVertically();

        cube3Dfaces.push_back(tempFace);
    }
    cube3D = Cube(cube3Dfaces, true);
}

/*
 * Rotates the cube to the currently selected face
 * Added by: Maiko Tuitupou
 */
void Model3DCube::setRotationToCurrentFace()
{
    switch (cubeCopyOf1D.getCurrentFaceID())
    {
    case 0:
    {
        yAxisPosition = yAxis::up;
        xAxisPosition = xAxis::deg90;
        break;
    }
    case 1:
    {
        yAxisPosition = yAxis::up;
        xAxisPosition = xAxis::deg0;
        break;
    }
    case 2:
    {
        yAxisPosition = yAxis::up;
        xAxisPosition = xAxis::deg90;
        break;
    }
    case 3:
    {
        yAxisPosition = yAxis::up;
        xAxisPosition = xAxis::deg180;
        break;
    }
    case 4:
    {
        yAxisPosition = yAxis::down;
        xAxisPosition = xAxis::deg90;
        break;
    }
    case 5:
    {
        yAxisPosition = yAxis::up;
        xAxisPosition = xAxis::deg270;
        break;
    }
    }
}

/*
 *method for updating visible faces
 *
 */
void Model3DCube::updateVisibleFaces()
{
    // actual implementation with full cube data
    visibleFaces.clear();

    // makeing a copy of stored 1d cube data to calculate the visible faces and visible face orientations
    Cube tempCube = cube3D;
    CubeFace leftFace, rightFace, topFace;

    leftFace = tempCube.getFace(xAxisPosition);
    rightFace = tempCube.getFace(getRightVisibleFacePosition());
    topFace = tempCube.getFace(yAxisPosition + 4);

    // rotate top face to match xAxis orientation
    if (yAxisPosition == up)
    {
        // rotate top face to match xAxisPosition
        for (int i = 0; i < (int)xAxisPosition; i++)
        {
            topFace.rotateCounterClockwise();
        }
    }
    else
    {
        // rotate top face the opposite direction
        for (int i = 0; i < (int)xAxisPosition; i++)
        {
            topFace.rotateCounterClockwise();
        }
        // if down, need to rotate left and right face by 180
        leftFace.rotateClockwise();
        leftFace.rotateClockwise();
        rightFace.rotateClockwise();
        rightFace.rotateClockwise();
        topFace.rotateClockwise();
        topFace.rotateClockwise();
    }

    visibleFaces.push_back(leftFace);
    visibleFaces.push_back(rightFace);
    visibleFaces.push_back(topFace);

    emit notify3DCubeView(visibleFaces);
}

/*
 *method for getting the right visible face position
 */
int Model3DCube::getRightVisibleFacePosition()
{
    int rightFacePosition = 0;
    if (yAxisPosition == up)
    {
        rightFacePosition = (xAxisPosition + 1) % 4; // position one to the right
    }
    else if (yAxisPosition == down)
    {
        // must get position one to the left if cube is upside-down because everything is inverted
        if (xAxisPosition == deg0)
        {
            rightFacePosition = deg270;
        }
        else
        {
            rightFacePosition = ((int)xAxisPosition) - 1;
        }
    }
    return rightFacePosition;
}

// Functions for orientation code -------------------------------------------------------------------------------------------------------

void Model3DCube::update3DOrientation(const string &dirRotate)
{
    if (dirRotate == "Up")
    {
        rotate_up();
    }
    else if (dirRotate == "Left")
    {
        rotate_left();
    }
    else if (dirRotate == "Right")
    {
        rotate_right();
    }
    updateVisibleFaces();
}

/*
 * Decreases the xAxis rotation angle
 * loops back around to 270 when decreasing from 0
 */
void Model3DCube::helper_decrease_angle()
{
    if (xAxisPosition == deg0)
    {
        xAxisPosition = deg270;
    }
    else
    {
        xAxisPosition = (enum xAxis)(xAxisPosition - 1);
    }
}

/*
 * Increases the xAxis rotation angle
 * loops back around to 0 when increasing from 270
 */
void Model3DCube::helper_increase_angle()
{
    xAxisPosition = (enum xAxis)((xAxisPosition + 1) % 4);
}

/*
 * Updates the xAxisPosition to rotate the cube orientation to the right
 */
void Model3DCube::rotate_right()
{
    if (yAxisPosition == up)
    {
        // xAxis angle goes down when rotated to the left when the yAxis is up
        helper_decrease_angle();
    }
    else
    {
        // xAxis angle goes up when rotated to the left when the yAxis is down
        helper_increase_angle();
    }
}

/*
 * Updates the xAxisPosition to rotate the cube orientation to the left
 */
void Model3DCube::rotate_left()
{

    if (yAxisPosition == up)
    {
        // xAxis angle goes up when rotated to the left when the yAxis is up
        helper_increase_angle();
    }
    else
    {
        // xAxis angle goes down when rotated to the left when the yAxis is down
        helper_decrease_angle();
    }
}

/*
 * Updates the yAxisPosition to rotate the cube upside-down
 */
void Model3DCube::rotate_up()
{
    if (yAxisPosition == up)
    {
        helper_decrease_angle();
    }
    else
    {
        helper_increase_angle();
    }

    yAxisPosition = (enum yAxis)((yAxisPosition + 1) % 2);
}
