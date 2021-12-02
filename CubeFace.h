#ifndef CUBEFACE_H
#define CUBEFACE_H

#include <vector>

class CubeFace
{
public:
    CubeFace();
    CubeFace(char);
    CubeFace(const CubeFace &); // Do we need this?

    // Getters
    std::vector<std::vector<char>> getFace();
    std::vector<char> getRow(int);
    std::vector<char> getCol(int);

    // Setters
    void setRow(int, std::vector<char>);
    void setColumn(int, std::vector<char>);

    // Complete Checker
    bool complete();
private:
    std::vector<std::vector<char>> face;
};

#endif // CUBEFACE_H
