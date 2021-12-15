#include "Cube.h"

Cube::Cube(){
    coreCubeFaces.push_back(CubeFace('g'));
    coreCubeFaces.push_back(CubeFace('r'));
    coreCubeFaces.push_back(CubeFace('y'));
    coreCubeFaces.push_back(CubeFace('w'));
    coreCubeFaces.push_back(CubeFace('o'));
    coreCubeFaces.push_back(CubeFace('b'));
    setCurrentFaceID(0);
}

Cube::Cube(QVector<CubeFace> &cubeFaces, bool flipBackFace){
    coreCubeFaces = cubeFaces;

    if(flipBackFace) {
        this->flipBackFace();
    }

    setCurrentFaceID(0);
}

// ---------- Cube Faces ----------
void Cube::flipBackFace() {
    coreCubeFaces[5].flipHorizontally();
    rotatedCubeFaces = convertCoreToRotated(coreCubeFaces, currentFaceID);
}

QVector<CubeFace> Cube::getAllFaces()
{
    return rotatedCubeFaces;
}

void Cube::setCubeFaces(QVector<CubeFace> newCubeFaces, bool flipBackFace)
{
    coreCubeFaces = newCubeFaces;

    if(flipBackFace) {
        this->flipBackFace();
    }

    setCurrentFaceID(0);
}

CubeFace Cube::getFace(int i)
{
    return rotatedCubeFaces[i];
}

int Cube::getCurrentFaceID()
{
    return currentFaceID;
}

void Cube::setCurrentFaceID(int num)
{
    rotatedCubeFaces = convertCoreToRotated(coreCubeFaces, num);
    currentFaceID = num;
}

// ------------ Moves ---------
void Cube::moveF(RotationDirection dir) {
    QVector<char> lCol = rotatedCubeFaces[1].getCol(2);
    std::reverse(lCol.begin(), lCol.end());
    QVector<char> uRow = rotatedCubeFaces[2].getRow(2);
    QVector<char> rCol = rotatedCubeFaces[3].getCol(0);
    std::reverse(rCol.begin(), rCol.end());
    QVector<char> dRow = rotatedCubeFaces[4].getRow(0);

    if(dir == CLOCKWISE) {
        rotatedCubeFaces[0].rotateClockwise();
        rotatedCubeFaces[1].setCol(2, dRow);
        rotatedCubeFaces[2].setRow(2, lCol);
        rotatedCubeFaces[3].setCol(0, uRow);
        rotatedCubeFaces[4].setRow(0, rCol);
    } else {
        rotatedCubeFaces[0].rotateCounterClockwise();
        rotatedCubeFaces[1].setCol(2, uRow);
        rotatedCubeFaces[2].setRow(2, rCol);
        rotatedCubeFaces[3].setCol(0, dRow);
        rotatedCubeFaces[4].setRow(0, lCol);
    }

    coreCubeFaces = convertRotatedToCore(rotatedCubeFaces, currentFaceID);
}

void Cube::moveU(RotationDirection dir) {
    rotatedCubeFaces[5].flipHorizontally();
    QVector<char> lRow = rotatedCubeFaces[1].getRow(0);
    QVector<char> fRow = rotatedCubeFaces[0].getRow(0);
    QVector<char> rRow = rotatedCubeFaces[3].getRow(0);
    QVector<char> bRow = rotatedCubeFaces[5].getRow(0);
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[2].rotateClockwise();
        rotatedCubeFaces[1].setRow(0, fRow);
        rotatedCubeFaces[0].setRow(0, rRow);
        rotatedCubeFaces[3].setRow(0, bRow);
        rotatedCubeFaces[5].setRow(0, lRow);
    } else {
        rotatedCubeFaces[2].rotateCounterClockwise();
        rotatedCubeFaces[1].setRow(0, bRow);
        rotatedCubeFaces[0].setRow(0, lRow);
        rotatedCubeFaces[3].setRow(0, fRow);
        rotatedCubeFaces[5].setRow(0, rRow);
    }
    rotatedCubeFaces[5].flipHorizontally();

    coreCubeFaces = convertRotatedToCore(rotatedCubeFaces, currentFaceID);
}

void Cube::moveD(RotationDirection dir) {
    rotatedCubeFaces[5].flipHorizontally();
    QVector<char> lRow = rotatedCubeFaces[1].getRow(2);
    QVector<char> fRow = rotatedCubeFaces[0].getRow(2);
    QVector<char> rRow = rotatedCubeFaces[3].getRow(2);
    QVector<char> bRow = rotatedCubeFaces[5].getRow(2);
    if(dir == CLOCKWISE) {
        rotatedCubeFaces[4].rotateClockwise();
        rotatedCubeFaces[1].setRow(2, bRow);
        rotatedCubeFaces[0].setRow(2, lRow);
        rotatedCubeFaces[3].setRow(2, fRow);
        rotatedCubeFaces[5].setRow(2, rRow);
    } else {
        rotatedCubeFaces[4].rotateCounterClockwise();
        rotatedCubeFaces[1].setRow(2, fRow);
        rotatedCubeFaces[0].setRow(2, rRow);
        rotatedCubeFaces[3].setRow(2, bRow);
        rotatedCubeFaces[5].setRow(2, lRow);
    }
    rotatedCubeFaces[5].flipHorizontally();

    coreCubeFaces = convertRotatedToCore(rotatedCubeFaces, currentFaceID);
}

void Cube::moveL(RotationDirection dir) {
    QVector<char> fCol = rotatedCubeFaces[0].getCol(0);
    QVector<char> dCol = rotatedCubeFaces[4].getCol(0);
    QVector<char> bCol = rotatedCubeFaces[5].getCol(0);
    std::reverse(bCol.begin(), bCol.end());
    QVector<char> uCol = rotatedCubeFaces[2].getCol(0);

    if(dir == CLOCKWISE) {
        rotatedCubeFaces[1].rotateClockwise();
        rotatedCubeFaces[0].setCol(0, uCol);
        rotatedCubeFaces[4].setCol(0, fCol);
        rotatedCubeFaces[5].setCol(0, dCol);
        rotatedCubeFaces[2].setCol(0, bCol);
    } else {
        rotatedCubeFaces[1].rotateCounterClockwise();
        rotatedCubeFaces[0].setCol(0, dCol);
        rotatedCubeFaces[4].setCol(0, bCol);
        rotatedCubeFaces[5].setCol(0, uCol);
        rotatedCubeFaces[2].setCol(0, fCol);
    }

    bCol = rotatedCubeFaces[5].getCol(0);
    std::reverse(bCol.begin(), bCol.end());
    rotatedCubeFaces[5].setCol(0, bCol);

    coreCubeFaces = convertRotatedToCore(rotatedCubeFaces, currentFaceID);
}

void Cube::moveR(RotationDirection dir) {
    QVector<char> fCol = rotatedCubeFaces[0].getCol(2);
    QVector<char> dCol = rotatedCubeFaces[4].getCol(2);
    QVector<char> bCol = rotatedCubeFaces[5].getCol(2);
    std::reverse(bCol.begin(), bCol.end());
    QVector<char> uCol = rotatedCubeFaces[2].getCol(2);

    if(dir == CLOCKWISE) {
        rotatedCubeFaces[3].rotateClockwise();
        rotatedCubeFaces[0].setCol(2, dCol);
        rotatedCubeFaces[4].setCol(2, bCol);
        rotatedCubeFaces[5].setCol(2, uCol);
        rotatedCubeFaces[2].setCol(2, fCol);
    } else {
        rotatedCubeFaces[3].rotateCounterClockwise();
        rotatedCubeFaces[0].setCol(2, uCol);
        rotatedCubeFaces[4].setCol(2, fCol);
        rotatedCubeFaces[5].setCol(2, dCol);
        rotatedCubeFaces[2].setCol(2, bCol);
    }

    bCol = rotatedCubeFaces[5].getCol(2);
    std::reverse(bCol.begin(), bCol.end());
    rotatedCubeFaces[5].setCol(2, bCol);

    coreCubeFaces = convertRotatedToCore(rotatedCubeFaces, currentFaceID);
}


// ----------- Solve Function --------
bool Cube::isSolved()
{
    for(CubeFace f : rotatedCubeFaces)
        if (!f.complete())
            return false;
    return true;
}

// -------- Converters -----------
QVector<QImage> Cube::toQImageList()
{
    QVector<CubeFace> tempCubeFaces = rotatedCubeFaces;

    // Flip the back face for display
    tempCubeFaces[5].flipHorizontally();

    QVector<QImage> list;
    for (CubeFace f : tempCubeFaces)
        list.push_back(f.toQImage());
    return list;
}

QVector<CubeFace> Cube::convertCoreToRotated(QVector<CubeFace> original, int targetFaceID) {
    QVector<CubeFace> rotated;
    original[5].flipHorizontally();
    switch (targetFaceID)
    {
    case 0:
        rotated = original;
        break;
    case 1:
        rotated.push_back(original[1]);
        rotated.push_back(original[5]);
        rotated.push_back(original[2]);
        rotated.push_back(original[0]);
        rotated.push_back(original[4]);
        rotated.push_back(original[3]);
        rotated[2].rotateCounterClockwise();
        rotated[4].rotateClockwise();
        break;
    case 2:
        rotated.push_back(original[2]);
        rotated.push_back(original[1]);
        rotated.push_back(original[5]);
        rotated.push_back(original[3]);
        rotated.push_back(original[0]);
        rotated.push_back(original[4]);
        rotated[1].rotateClockwise();
        rotated[3].rotateCounterClockwise();
        rotated[5].rotateCounterClockwise();
        rotated[5].rotateCounterClockwise();
        rotated[2].rotateCounterClockwise();
        rotated[2].rotateCounterClockwise();
        break;
    case 3:
        rotated.push_back(original[3]);
        rotated.push_back(original[0]);
        rotated.push_back(original[2]);
        rotated.push_back(original[5]);
        rotated.push_back(original[4]);
        rotated.push_back(original[1]);
        rotated[2].rotateClockwise();
        rotated[4].rotateCounterClockwise();
        break;
    case 4:
        rotated.push_back(original[4]);
        rotated.push_back(original[1]);
        rotated.push_back(original[0]);
        rotated.push_back(original[3]);
        rotated.push_back(original[5]);
        rotated.push_back(original[2]);
        rotated[1].rotateCounterClockwise();
        rotated[5].rotateClockwise();
        rotated[5].rotateClockwise();
        rotated[3].rotateClockwise();
        rotated[4].rotateClockwise();
        rotated[4].rotateClockwise();
        break;
    case 5:
        rotated.push_back(original[5]);
        rotated.push_back(original[3]);
        rotated.push_back(original[2]);
        rotated.push_back(original[1]);
        rotated.push_back(original[4]);
        rotated.push_back(original[0]);
        rotated[2].rotateClockwise();
        rotated[2].rotateClockwise();
        rotated[4].rotateClockwise();
        rotated[4].rotateClockwise();
        break;
    default:
        qDebug() << "Invalid cube face ID";
    }

    rotated[5].flipHorizontally();

    return rotated;
}

QVector<CubeFace> Cube::convertRotatedToCore(QVector<CubeFace> rotated, int currentFaceID) {
    QVector<CubeFace> core;
    rotated[5].flipHorizontally();
    qDebug() << currentFaceID;
    switch (currentFaceID)
    {
    case 0: // Front
        core = rotated;
        break;
    case 1: // Left
        rotated[2].rotateClockwise();
        rotated[4].rotateCounterClockwise();
        core.push_back(rotated[3]);
        core.push_back(rotated[0]);
        core.push_back(rotated[2]);
        core.push_back(rotated[5]);
        core.push_back(rotated[4]);
        core.push_back(rotated[1]);
        break;
    case 2: // Top
        rotated[1].rotateCounterClockwise();
        rotated[3].rotateClockwise();
        rotated[5].rotateClockwise();
        rotated[5].rotateClockwise();
        rotated[2].rotateClockwise();
        rotated[2].rotateClockwise();
        core.push_back(rotated[4]);
        core.push_back(rotated[1]);
        core.push_back(rotated[0]);
        core.push_back(rotated[3]);
        core.push_back(rotated[5]);
        core.push_back(rotated[2]);
        break;
    case 3: // Right
        rotated[2].rotateCounterClockwise();
        rotated[4].rotateClockwise();
        core.push_back(rotated[1]);
        core.push_back(rotated[5]);
        core.push_back(rotated[2]);
        core.push_back(rotated[0]);
        core.push_back(rotated[4]);
        core.push_back(rotated[3]);
        break;
    case 4: // Down
        rotated[1].rotateClockwise();
        rotated[5].rotateCounterClockwise();
        rotated[5].rotateCounterClockwise();
        rotated[3].rotateCounterClockwise();
        rotated[4].rotateCounterClockwise();
        rotated[4].rotateCounterClockwise();
        core.push_back(rotated[2]);
        core.push_back(rotated[1]);
        core.push_back(rotated[5]);
        core.push_back(rotated[3]);
        core.push_back(rotated[0]);
        core.push_back(rotated[4]);
        break;
    case 5: // Back
        rotated[2].rotateCounterClockwise();
        rotated[2].rotateCounterClockwise();
        rotated[4].rotateCounterClockwise();
        rotated[4].rotateCounterClockwise();
        core.push_back(rotated[5]);
        core.push_back(rotated[3]);
        core.push_back(rotated[2]);
        core.push_back(rotated[1]);
        core.push_back(rotated[4]);
        core.push_back(rotated[0]);
        break;
    default:
        qDebug() << "Invalid cube face ID";
    }

    core[5].flipHorizontally();

    return core;
}
