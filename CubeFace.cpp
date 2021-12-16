#include "CubeFace.h"

CubeFace::CubeFace()
{
    QVector<char> row(3, 'g');
    QVector<QVector<char> > completeFace(3, row);
    face = completeFace;
}

CubeFace::CubeFace(QVector<QVector<char> > face)
{
    this->face = face;
}

CubeFace::CubeFace(char faceColor)
{
    QVector<char> row(3, faceColor);
    QVector<QVector<char> > completeFace(3, row);
    face = completeFace;
}

CubeFace::CubeFace(const CubeFace &other)
{
    face = other.face;
}

CubeFace::CubeFace(string faceString, char faceColor)
{
    QVector<char> row(3, faceColor);
    QVector<QVector<char> > completeFace(3, row);
    face = completeFace;
    // start cross
    if (faceString == "firstCrossMainFace")
    {
        face[1][1] = 'r';
        face[1][0] = 'r';
        face[0][1] = 'r';
        face[1][2] = 'r';
        face[2][1] = 'g';
    }
    if (faceString == "firstCrossRightFace")
    {
        face[0][1] = 'w';
        face[1][1] = 'w';
    }
    if (faceString == "firstCrossBelowFace")
    {
        face[0][1] = 'r';
        face[1][1] = 'g';
    }

    // first corners
    if (faceString == "firstCornersMainFace")
    {
        face[2][2] = 'x';
    }
    if (faceString == "firstCornersRightFace")
    {
        face[0][2] = 'w';
        face[0][1] = 'w';
        face[1][1] = 'w';
        face[2][0] = 'r';
    }
    if (faceString == "firstCornersBelowFace")
    {
        face[0][0] = 'g';
        face[0][1] = 'g';
        face[1][1] = 'g';
        face[2][2] = 'g';
    }
    if (faceString == "firstCornersAboveFace")
        face[0][2] = 'w';

    // neighbor right
    if (faceString == "neighborRightMainFace")
    {
        face[2][1] = 'b';
        face[1][1] = 'y';
    }
    if (faceString == "neighborRightRightFace")
    {
        face[2][0] = 'b';
        face[2][1] = 'b';
        face[1][1] = 'b';
        face[2][2] = 'b';
    }
    if (faceString == "neighborRightBelowFace")
    {
        face[0][1] = 'o';
        face[1][1] = 'o';
        face[2][0] = 'o';
        face[2][1] = 'o';
        face[2][2] = 'o';
    }
    if (faceString == "neighborRightAboveFace")
    {
        face[2][0] = 'r';
        face[2][1] = 'r';
        face[1][1] = 'r';
        face[2][2] = 'r';
    }
    if (faceString == "neighborRightLeftFace")
    {
        face[2][0] = 'g';
        face[2][1] = 'g';
        face[2][2] = 'g';
        face[1][1] = 'g';
    }

    // neighbor left
    if (faceString == "neighborLeftMainFace")
    {
        face[2][1] = 'g';
        face[1][1] = 'y';
    }
    if (faceString == "neighborLeftRightFace")
    {
        face[0][2] = 'b';
        face[1][2] = 'b';
        face[1][1] = 'b';
        face[2][2] = 'b';
    }
    if (faceString == "neighborLeftBelowFace")
    {
        face[0][1] = 'o';
        face[1][1] = 'o';
        face[2][0] = 'o';
        face[2][1] = 'o';
        face[2][2] = 'o';
    }
    if (faceString == "neighborLeftAboveFace")
    {
        face[0][0] = 'r';
        face[0][1] = 'r';
        face[1][1] = 'r';
        face[0][2] = 'r';
    }
    if (faceString == "neighborLeftLeftFace")
    {
        face[0][0] = 'g';
        face[1][0] = 'g';
        face[2][0] = 'g';
        face[1][1] = 'g';
    }

    // final cross
    if (faceString == "finalCrossMainFace")
    {
        face[1][1] = 'r';
        face[1][0] = 'r';
        face[0][1] = 'r';
    }
    if (faceString == "finalCrossRightFace")
        face[0][1] = 'r';
    if (faceString == "finalCrossBelowFace")
        face[0][1] = 'r';

    // final edges
    if (faceString == "finalEdgesMainFace")
    {
        face[0][0] = 'x';
        face[0][2] = 'x';
        face[2][0] = 'x';
        face[2][2] = 'x';
    }
    if (faceString == "finalEdgesRightFace")
    {
        face[0][0] = 'x';
        face[0][2] = 'x';
    }
    if (faceString == "finalEdgesBelowFace")
    {
        face[0][1] = 'g';
        face[0][0] = 'x';
        face[0][2] = 'x';
    }
    if (faceString == "finalEdgesAboveFace")
    {
        face[0][0] = 'x';
        face[0][2] = 'x';
    }
    if (faceString == "finalEdgesLeftFace")
    {
        face[0][1] = 'o';
        face[0][0] = 'x';
        face[0][2] = 'x';
    }
    if (faceString == "finalEdgesOppositeFace")
    {
        face[0][2] = 'y';
    }

    // final corners
    if (faceString == "finalCornersMainFace")
    {
        face[0][0] = 'o';
        face[0][2] = 'g';
        face[2][0] = 'r';
    }
    if (faceString == "finalCornersRightFace")
    {
        face[0][2] = 'y';
    }
    if (faceString == "finalCornersBelowFace")
    {
        face[0][0] = 'b';
    }
    if (faceString == "finalCornersAboveFace")
    {
        face[0][2] = 'y';
    }
    if (faceString == "finalCornersLeftFace")
    {
        face[0][2] = 'y';
    }

    // orient corners
    if (faceString == "orientCornersMainFace")
    {
        face[2][2] = 'o';
        face[2][0] = 'o';
    }
    if (faceString == "orientCornersRightFace")
    {
        face[0][0] = 'y';
    }
    if (faceString == "orientCornersBelowFace")
    {
        face[0][2] = 'b';
        face[0][0] = 'g';
    }
    if (faceString == "orientCornersLeftFace")
    {
        face[0][2] = 'y';
    }
}

QVector<QVector<char> > CubeFace::getFace()
{
    return face;
}

QVector<char> CubeFace::getRow(int y)
{
    return face[y];
}

QVector<char> CubeFace::getCol(int x)
{
    QVector<char> col;
    for (int i = 0; i < (int)face.size(); i++)
        col.push_back(face[i][x]);
    return col;
}

void CubeFace::setRow(int y, QVector<char> row)
{
    face[y] = row;
}

void CubeFace::setCol(int x, QVector<char> col)
{
    for (int i = 0; i < (int)face.size(); i++)
        face[i][x] = col[i];
}

void CubeFace::rotateClockwise()
{
    const QVector<char> r0 = getRow(0);
    const QVector<char> r1 = getRow(1);
    const QVector<char> r2 = getRow(2);

    for (int i = 0; i < (int)face.size(); i++)
    {
        face[i][0] = r2[i];
        face[i][1] = r1[i];
        face[i][2] = r0[i];
    }
}

void CubeFace::rotateCounterClockwise()
{
    const QVector<char> c0 = getCol(0);
    const QVector<char> c1 = getCol(1);
    const QVector<char> c2 = getCol(2);

    for (int i = 0; i < (int)face.size(); i++)
    {
        face[2][i] = c0[i];
        face[1][i] = c1[i];
        face[0][i] = c2[i];
    }
}

/*
 * Flips face vertically (mirrors along x axis) (needed for cube3Dview
 */
void CubeFace::flipVertically()
{
    QVector<char> r0 = getRow(0);
    QVector<char> r2 = getRow(2);

    setRow(0, r2);
    setRow(2, r0);
}

/*
 * Flips face vertically (mirrors along x axis) (needed for cube3Dview
 */
void CubeFace::flipHorizontally()
{
    QVector<char> c0 = getCol(0);
    QVector<char> c2 = getCol(2);

    setCol(0, c2);
    setCol(2, c0);
}

bool CubeFace::complete()
{
    char standard = face[0][0];
    for (QVector<char> row : face)
    {
        for (char c : row)
        {
            if (c != standard)
                return false;
        }
    }
    return true;
}

QImage CubeFace::toQImage()
{
    QImage image(3, 3, QImage::Format_RGBA64);

    for (int i = 0; i < (int)face.size(); i++)
    {
        for (int j = 0; j < (int)face[i].size(); j++)
        {
            image.setPixelColor(j,i,getColor(i,j));
        }
    }

    return image;
}


QImage CubeFace::toQImageAlt(int swit)
{
    QImage image(205, 85, QImage::Format_RGBA64);
    double angle = 45 * 3.14159265/180;
    for (int j = 0; j < 85 ; j++)
    {
        for (int i = 0; i < 120 ; i++)
        {
            if(i+j >= j && i < 40 + j && j >= 0 && j < 40 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(2,0));
                else
                    image.setPixelColor(i+j,j,getColor(2,0));
            }
            if(i+j >= 40 + j && i < 80 + j && j >= 0 && j < 40 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(2,1));
                else
                    image.setPixelColor(i+j,j,getColor(1,0));
            }
            if(i+j >= 80 + j && i+j < 120 + j && j >= 0 && j < 40 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(2,2));
                else
                    image.setPixelColor(i+j,j,getColor(0,0));
            }
            if(i+j >= j && i+j < 40 + j && j >= 40 * cos(angle) && j < 80 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(1,0));
                else
                    image.setPixelColor(i+j,j,getColor(2,1));
            }
            if(i+j >= 40 + j && i+j < 80 + j && j >= 40 * cos(angle) && j < 80 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(1,1));
                else
                    image.setPixelColor(i+j,j,getColor(1,1));
            }
            if(i+j >= 80 + j && i+j < 120 + j && j >= 40 * cos(angle) && j < 80 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(1,2));
                else
                    image.setPixelColor(i+j,j,getColor(0,1));
            }
            if(i+j >= j && i+j < 40 + j && j >= 80 * cos(angle) && j < 120 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(0,0));
                else
                    image.setPixelColor(i+j,j,getColor(2,2));
            }
            if(i+j >= 40 + j && i+j < 80 + j && j >= 80 * cos(angle) && j < 120 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(0,1));
                else
                    image.setPixelColor(i+j,j,getColor(1,2));
            }
            if(i+j >= 80 + j && i+j < 120 + j && j >= 80 * cos(angle) && j < 120 * cos(angle)){
                if (swit == 1)
                    image.setPixelColor(i+j,j,getColor(0,2));
                else
                    image.setPixelColor(i+j,j,getColor(0,2));
            }
        }
    }
    return image;
}

QColor CubeFace::getColor(int i, int j){
    switch(face[i][j])
    {
        case 'g':
            return QColor("green");
        case 'r':
            return QColor("red");
        case 'y':
            return QColor("yellow");
        case 'w':
            return QColor("white");
        case 'o':
            return QColor("orange");
        case 'x':
            return QColor("grey");
        default:
            return QColor("blue");
    }
}

bool CubeFace::equals(CubeFace other) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(face[i][j] != other.face[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void CubeFace::printDebug(){
    for (int irow = 0; irow < 3; irow++)
    {
        qDebug() << face[irow][0] << "," << face[irow][1] << "," << face[irow][2];
    }
}
