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
    if(faceString == "firstCrossMainFace")
        face[1][1] = 'r';
    if(faceString == "firstCrossRightFace")
        face[0][1] = 'r';
    if(faceString == "firstCrossBelowFace")
        face[1][0] = 'r';
    if(faceString == "firstCrossAboveFace")
        face[1][1] = 'r';
    if(faceString == "firstCrossLeftFace")
        face[2][1] = 'r';

    //start corners

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
    std::vector<char> r0 = getRow(0);
    std::vector<char> r1 = getRow(1);
    std::vector<char> r2 = getRow(2);

    for (int i = 0; i < (int) face.size(); i++)
    {
        face[i][0] = r2[i];
        face[i][1] = r1[i];
        face[i][0] = r0[i];
    }
}

void CubeFace::rotateCounterClockwise()
{
    std::vector<char> c0 = getCol(0);
    std::vector<char> c1 = getCol(1);
    std::vector<char> c2 = getCol(2);

    for (int i = 0; i < (int) face.size(); i++)
    {
        face[0][i] = c2[i];
        face[0][i] = c1[i];
        face[0][i] = c0[i];
    }
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
