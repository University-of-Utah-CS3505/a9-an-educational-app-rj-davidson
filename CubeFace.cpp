#include "CubeFace.h"

CubeFace::CubeFace()
{
    std::vector<char> row(3, 'g');
    std::vector<std::vector<char> > completeFace(3, row);
    face = completeFace;

}

CubeFace::CubeFace(char faceColor)
{
    std::vector<char> row(3, faceColor);
    std::vector<std::vector<char> > completeFace(3, row);
    face = completeFace;
}

CubeFace::CubeFace(const CubeFace &other)
{
    face = other.face;
}

CubeFace::CubeFace(string faceString, char faceColor)
{
    std::vector<char> row(3, faceColor);
    std::vector<std::vector<char> > completeFace(3, row);
    face = completeFace;
    //start cross
    if(faceString == "firstCrossMainFace") {
        face[1][1] = 'r';
        face[1][0] = 'r';
        face[0][1] = 'r';
        face[1][2] = 'r';
        face[2][1] = 'g';
    }
    if(faceString == "firstCrossRightFace") {
        face[1][0] = 'w';
        face[1][1] = 'w';
    }
    if(faceString == "firstCrossBelowFace") {
        face[0][1] = 'r';
        face[1][1] = 'g';
    }
//    if(faceString == ""){
//        face[2][1] = 'b';
//        face[1][1] = 'b';
//    }
//    if(faceString == "firstCrossLeftFace")
//        face[2][1] = 'r';

    //first corners
    if(faceString == "firstCornersMainFace"){
        face[0][0] = 'r';
        face[0][1] = 'r';
        face[0][2] = 'r';
        face[1][0] = 'r';
        face[1][1] = 'r';
        face[1][2] = 'r';
        face[2][0] = 'r';
        face[2][1] = 'r';
    }
    if(faceString == "firstCornersRightFace"){
        face[0][0] = 'w';
        face[1][0] = 'w';
        face[1][1] = 'w';
        face[2][2] = 'r';
    }
    if(faceString == "firstCornersBelowFace"){
        face[0][0] = 'g';
        face[0][1] = 'g';
        face[1][1] = 'g';
        face[2][2] = 'w';
    }
//    if(faceString == "firstCornersAboveFace")
//        face[1][1] = 'r';
//    if(faceString == "firstCornersLeftFace")
//        face[2][1] = 'r';
//    if(faceString == "firstCornersOppositeFace")
//        face[2][1] = 'r';

    //neighbor right
    if(faceString == "neighborRightMainFace"){
        face[2][1] = 'b';
        face[1][1] = 'y';
    }
    if(faceString == "neighborRightRightFace"){
        face[0][2] = 'b';
        face[1][2] = 'b';
        face[1][1] = 'b';
        face[2][2] = 'b';
    }
    if(faceString == "neighborRightBelowFace"){
        face[0][1] = 'o';
        face[1][1] = 'o';
        face[2][0] = 'o';
        face[2][1] = 'o';
        face[2][2] = 'o';
    }
    if(faceString == "neighborRightAboveFace"){
        face[0][0] = 'r';
        face[0][1] = 'r';
        face[1][1] = 'r';
        face[0][2] = 'r';
    }
    if(faceString == "neighborRightLeftFace"){
        face[0][0] = 'g';
        face[1][0] = 'g';
        face[2][0] = 'g';
        face[1][1] = 'g';
    }

    //neighbor left
    if(faceString == "neighborRightMainFace"){
        face[2][1] = 'g';
        face[1][1] = 'y';
    }
    if(faceString == "neighborRightRightFace"){
        face[0][2] = 'b';
        face[1][2] = 'b';
        face[1][1] = 'b';
        face[2][2] = 'b';
    }
    if(faceString == "neighborRightBelowFace"){
        face[0][1] = 'o';
        face[1][1] = 'o';
        face[2][0] = 'o';
        face[2][1] = 'o';
        face[2][2] = 'o';
    }
    if(faceString == "neighborRightAboveFace"){
        face[0][0] = 'r';
        face[0][1] = 'r';
        face[1][1] = 'r';
        face[0][2] = 'r';
    }
    if(faceString == "neighborRightLeftFace"){
        face[0][0] = 'g';
        face[1][0] = 'g';
        face[2][0] = 'g';
        face[1][1] = 'g';
    }

    //final cross
    if(faceString == "finalCrossMainFace")
        face[1][1] = 'r';
    if(faceString == "finalCrossRightFace")
        face[1][0] = 'r';
    if(faceString == "finalCrossBelowFace")
        face[0][1] = 'r';
    if(faceString == "finalCrossAboveFace")
        face[2][1] = 'r';
    if(faceString == "finalCrossLeftFace")
        face[1][2] = 'r';

    //final corners
    if(faceString == "finalCornersMainFace"){
        face[0][0] = 'o';
        face[0][2] = 'g';
        face[2][0] = 'r';
    }
    if(faceString == "finalCornersRightFace"){
        face[0][0] = 'y';
    }
    if(faceString == "finalCornersBelowFace"){
        face[0][0] = 'b';
    }
    if(faceString == "finalCornersAboveFace"){
        face[2][0] = 'y';
    }
    if(faceString == "finalCornersLeftFace"){
        face[0][2] = 'y';
    }
}

std::vector<std::vector<char>> CubeFace::getFace()
{
    return face;
}

std::vector<char> CubeFace::getRow(int y)
{
    return face[y];
}

std::vector<char> CubeFace::getCol(int x)
{
    std::vector<char> col;
    for (int i = 0; i < (int) face.size(); i++)
        col.push_back(face[i][x]);
    return col;
}

void CubeFace::setRow(int y, std::vector<char> row)
{
    face[y] = row;
}

void CubeFace::setCol(int x, std::vector<char> col)
{
    for (int i = 0; i < (int) face.size(); i++)
        face[i][x] = col[i];
}

void CubeFace::rotateClockwise()
{
    const std::vector<char> r0 = getRow(0);
    const std::vector<char> r1 = getRow(1);
    const std::vector<char> r2 = getRow(2);

    for (int i = 0; i < (int) face.size(); i++)
    {
        face[i][0] = r2[i];
        face[i][1] = r1[i];
        face[i][2] = r0[i];
    }
}

void CubeFace::rotateCounterClockwise()
{
    const std::vector<char> c0 = getCol(0);
    const std::vector<char> c1 = getCol(1);
    const std::vector<char> c2 = getCol(2);

    for (int i = 0; i < (int) face.size(); i++)
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
    std::vector<char> r0 = getRow(0);
    std::vector<char> r2 = getRow(2);

    setRow(0, r2);
    setRow(2, r0);
}

/*
 * Flips face vertically (mirrors along x axis) (needed for cube3Dview
 */
void CubeFace::flipHorizontally()
{
    std::vector<char> c0 = getCol(0);
    std::vector<char> c2 = getCol(2);

    setCol(0, c2);
    setCol(2, c0);
}

bool CubeFace::complete()
{
    char standard = face[0][0];
    for (std::vector<char> row : face)
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

    for (int i = 0; i < (int) face.size(); i++)
    {
        for (int j = 0; j < (int) face[i].size(); j++)
        {
            switch(face[i][j])
            {
                case 'g':
                    image.setPixelColor(j, i, QColor("green"));
                    break;
                case 'r':
                    image.setPixelColor(j, i, QColor("red"));
                    break;
                case 'y':
                    image.setPixelColor(j, i, QColor("yellow"));
                    break;
                case 'w':
                    image.setPixelColor(j, i, QColor("white"));
                    break;
                case 'o':
                    image.setPixelColor(j, i, QColor("orange"));
                    break;
                case 'x':
                    image.setPixelColor(j, i, QColor("grey"));
                default:
                    image.setPixelColor(j, i, QColor("blue"));
            }
        }
    }

    return image;
}

void CubeFace::printDebug(){
    for (int irow = 0; irow < 3; irow++)
    {
        qDebug()<< face[irow][0] << "," << face[irow][1] << "," << face[irow][2];
    }
}

