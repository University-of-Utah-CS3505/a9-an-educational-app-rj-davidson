#ifndef CUBEFACE_H
#define CUBEFACE_H

#include <vector>

class CubeFace
{
public:
    CubeFace();
    CubeFace(int);
    CubeFace(const CubeFace &); // Do we need this?

    // Getters
    std::vector<std::vector<int>> getFace();
    std::vector<int> getRow(int);
    std::vector<int> getCol(int);

    // Setters
    void setRow(int, std::vector<int>);
    void setColumn(int, std::vector<int>);
private:
    std::vector<std::vector<int>> face;
};

#endif // CUBEFACE_H
