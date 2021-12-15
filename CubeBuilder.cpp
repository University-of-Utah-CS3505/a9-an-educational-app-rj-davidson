#include "CubeBuilder.h"

Cube CubeBuilder::generateRandomCube(){
//    Cube c;
//    for (int i = 0; i < 20; i++)
//    {
//        int randomFace = rand() % 5;
//        c.setCurrentFace(randomFace);

//        int randomMove = rand() % 7;
//        c.move(randomMove);
//    }
//    c.setCurrentFace(0);
//    return c;
    Cube c;
    QVector<QVector<char>> face0Chars{QVector<char>{'g', 'y', 'r'},
                                             QVector<char>{'w', 'g', 'o'},
                                             QVector<char>{'y', 'b', 'w'}};
    QVector<QVector<char>> face1Chars{QVector<char>{'g', 'y', 'r'},
                                             QVector<char>{'w', 'r', 'o'},
                                             QVector<char>{'y', 'b', 'w'}};
    QVector<QVector<char>> face2Chars{QVector<char>{'g', 'y', 'r'},
                                             QVector<char>{'w', 'b', 'o'},
                                             QVector<char>{'y', 'b', 'w'}};
    QVector<QVector<char>> face3Chars{QVector<char>{'g', 'y', 'r'},
                                             QVector<char>{'w', 'y', 'o'},
                                             QVector<char>{'y', 'b', 'w'}};
    QVector<QVector<char>> face4Chars{QVector<char>{'g', 'y', 'r'},
                                             QVector<char>{'w', 'o', 'o'},
                                             QVector<char>{'y', 'b', 'w'}};
    QVector<QVector<char>> face5Chars{QVector<char>{'g', 'y', 'r'},
                                             QVector<char>{'w', 'w', 'o'},
                                             QVector<char>{'y', 'b', 'w'}};
    QVector<CubeFace> faces{CubeFace(face0Chars), CubeFace(face1Chars), CubeFace(face2Chars), CubeFace(face3Chars), CubeFace(face4Chars), CubeFace(face5Chars)};
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep1Cube(){
    Cube c;
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep2Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep3Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCornersMainFace", 'x'));
    faces.append(CubeFace("firstCornersLeftFace", 'x'));
    faces.append(CubeFace("firstCornersAboveFace", 'x'));
    faces.append(CubeFace("firstCornersRightFace", 'x'));
    faces.append(CubeFace("firstCornersBelowFace", 'x'));
    faces.append(CubeFace("firstCornersOppositeFace", 'x'));
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep4Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("neighborRightMainFace", 'x'));
    faces.append(CubeFace("neighborRightLeftFace", 'x'));
    faces.append(CubeFace("neighborRightAboveFace", 'x'));
    faces.append(CubeFace("neighborRightRightFace", 'x'));
    faces.append(CubeFace("neighborRightBelowFace", 'x'));
    faces.append(CubeFace('w'));
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep5Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("neighborLeftMainFace", 'x'));
    faces.append(CubeFace("neighborLeftLeftFace", 'x'));
    faces.append(CubeFace("neighborLeftAboveFace", 'x'));
    faces.append(CubeFace("neighborLeftRightFace", 'x'));
    faces.append(CubeFace("neighborLeftBelowFace", 'x'));
    faces.append(CubeFace('w'));
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep6Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("finalCrossMainFace", 'x'));
    faces.append(CubeFace("finalCrossLeftFace", 'x'));
    faces.append(CubeFace("finalCrossAboveFace", 'x'));
    faces.append(CubeFace("finalCrossRightFace", 'x'));
    faces.append(CubeFace("finalCrossBelowFace", 'x'));
    faces.append(CubeFace('w'));
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep7Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("finalCornersMainFace", 'y'));
    faces.append(CubeFace("finalCornersLeftFace", 'g'));
    faces.append(CubeFace("finalCornersAboveFace", 'r'));
    faces.append(CubeFace("finalCornersRightFace", 'b'));
    faces.append(CubeFace("finalCornersBelowFace", 'o'));
    faces.append(CubeFace("finalCornersOppositeFace", 'w'));
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep8Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace('x'));
    faces.append(CubeFace('x'));
    faces.append(CubeFace('x'));
    faces.append(CubeFace('x'));
    faces.append(CubeFace('x'));
    faces.append(CubeFace('x'));
    c.setCubeFaces(faces);
    c.setCurrentFaceID(0);
    return c;
}
