#ifndef CUBEFACE_H
#define CUBEFACE_H

#include <vector>
#include <QImage>
#include <QColor>
#include <iostream>
#include <string>
#include <QDebug>
using std::string;

class CubeFace
{
public:
    CubeFace();
    CubeFace(QVector<QVector<char> >);
    CubeFace(char);
    CubeFace(const CubeFace &); // Do we need this?
    CubeFace(string, char);

    // Getters
    QVector<QVector<char> > getFace();
    QVector<char> getRow(int);
    QVector<char> getCol(int);

    // Setters
    void setRow(int, QVector<char>);
    void setCol(int, QVector<char>);

    // Rotate Face
    void rotateClockwise();
    void rotateCounterClockwise();

    // flip face (needed for cube3Dview
    void flipVertically();
    void flipHorizontally();

    // Complete Checker
    bool complete();

    QImage toQImage();
    QImage toQImageAlt(int);


    void printDebug();

private:
    std::vector<std::vector<char>> face;
    QColor getColor(int, int);
};

#endif // CUBEFACE_H
