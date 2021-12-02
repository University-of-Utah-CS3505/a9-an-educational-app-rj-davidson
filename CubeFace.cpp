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
