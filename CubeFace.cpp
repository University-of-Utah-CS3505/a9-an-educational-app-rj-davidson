#include "CubeFace.h"

CubeFace::CubeFace()
{
    std::vector<int> row(3, 0);
    std::vector<std::vector<int> > completeFace(3, row);
    face = completeFace;

}

CubeFace::CubeFace(int faceColor)
{
    std::vector<int> row(3, faceColor);
    std::vector<std::vector<int> > completeFace(3, row);
    face = completeFace;
}

CubeFace::CubeFace(const CubeFace &other)
{
    face = other.face;
}

std::vector<std::vector<int>> CubeFace::getFace()
{
    return face;
}

std::vector<int> CubeFace::getRow(int y)
{
    return face[y];
}

std::vector<int> CubeFace::getCol(int x)
{
    std::vector<int> col;
    for (int i = 0; i < (int) face.size(); i++)
        col.push_back(face[i][x]);
    return col;
}

void CubeFace::setRow(int y, std::vector<int> row)
{
    face[y] = row;
}

void CubeFace::setColumn(int x, std::vector<int> col)
{
    for (int i = 0; i < (int) face.size(); i++)
        face[i][x] = col[i];
}
