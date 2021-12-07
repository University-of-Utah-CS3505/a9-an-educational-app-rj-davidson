#ifndef CUBEFACE_H
#define CUBEFACE_H

#include <vector>
#include <QImage>
#include <QColor>
#include <iostream>
#include <string>
using std::string;

class CubeFace
{
public:
    CubeFace();
    CubeFace(char);
    CubeFace(const CubeFace &); // Do we need this?
    CubeFace(string, char);

    // Getters
    std::vector<std::vector<char>> getFace();
    std::vector<char> getRow(int);
    std::vector<char> getCol(int);

    // Setters
    void setRow(int, std::vector<char>);
    void setCol(int, std::vector<char>);

    // Rotate Face
    void rotateClockwise();
    void rotateCounterClockwise();

    // Complete Checker
    bool complete();

    QImage toQImage();

private:
    std::vector<std::vector<char>> face;
};

#endif // CUBEFACE_H
