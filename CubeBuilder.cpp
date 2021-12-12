#include "CubeBuilder.h"

Cube CubeBuilder::randomCube(){
    Cube c;
    for (int i = 0; i < 20; i++)
    {
        int randomFace = rand() % 5 + 0;
        c.setCurrentFace(randomFace);

        int randomMove = rand() % 7 + 0;
        c.move(randomMove);
    }
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep1Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep2Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep3Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep4Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep5Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep6Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep7Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep8Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFace(0);
    return c;
}
