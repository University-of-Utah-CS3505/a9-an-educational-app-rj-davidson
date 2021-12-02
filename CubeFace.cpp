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

void CubeFace::setColumn(int x, std::vector<char> col)
{
    for (int i = 0; i < (int) face.size(); i++)
        face[i][x] = col[i];
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
                    image.setPixelColor(j, i, QColor("black")); // TODO: QColor orange
                    break;
                default:
                    image.setPixelColor(j, i, QColor("blue"));
            }
        }
    }

    return image;
}
