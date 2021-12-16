#include "CubeBuilder.h"

Cube CubeBuilder::generateRandomCube(){
    Cube c;
    for (int i = 0; i < 20; i++)
    {
        int randomFace = rand() % 5;
        c.setCurrentFaceID(randomFace);

        RotationDirection dir = CLOCKWISE;
        if(rand() % 2 == 1) {
            dir = COUNTERCLOCKWISE;
        }

        switch(rand() % 5) {
        case 0:
            c.moveF(dir);
            break;
        case 1:
            c.moveU(dir);
            break;
        case 2:
            c.moveR(dir);
            break;
        case 3:
            c.moveD(dir);
            break;
        case 4:
            c.moveL(dir);
            break;
        }
    }
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateDebugCube() {
    Cube c;
    QVector<QVector<char>> face0Chars{QVector<char>{'g', 'y', 'r'},
                                      QVector<char>{'w', 'g', 'o'},
                                      QVector<char>{'y', 'b', 'w'}};

    QVector<QVector<char>> face1Chars{QVector<char>{'g', 'y', 'r'},
                                      QVector<char>{'w', 'r', 'o'},
                                      QVector<char>{'y', 'b', 'w'}};

    QVector<QVector<char>> face2Chars{QVector<char>{'g', 'y', 'r'},
                                      QVector<char>{'w', 'y', 'o'},
                                      QVector<char>{'y', 'b', 'w'}};

    QVector<QVector<char>> face3Chars{QVector<char>{'g', 'y', 'r'},
                                      QVector<char>{'w', 'o', 'o'},
                                      QVector<char>{'y', 'b', 'w'}};

    QVector<QVector<char>> face4Chars{QVector<char>{'g', 'y', 'r'},
                                      QVector<char>{'w', 'w', 'o'},
                                      QVector<char>{'y', 'b', 'w'}};

    QVector<QVector<char>> face5Chars{QVector<char>{'g', 'y', 'r'},
                                      QVector<char>{'w', 'b', 'o'},
                                      QVector<char>{'y', 'b', 'w'}};

    QVector<CubeFace> faces{CubeFace(face0Chars), CubeFace(face1Chars), CubeFace(face2Chars), CubeFace(face3Chars), CubeFace(face4Chars), CubeFace(face5Chars)};
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);
    // No solve mode
    c.setSolverFunction([](Cube)->bool{
        return false;
    });
    return c;
}

Cube CubeBuilder::generateSolvedCube() {
    Cube c;
    // No solve mode
    c.setSolverFunction([](Cube)->bool{
        return false;
    });
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
    faces.append(CubeFace("firstCrossBelowFace", 'x'));
    faces.append(CubeFace("firstCrossLeftFace", 'x'));
    faces.append(CubeFace("firstCrossMainFace", 'x'));
    faces.append(CubeFace("firstCrossRightFace", 'x'));
    faces.append(CubeFace("firstCrossAboveFace", 'x'));
    faces.append(CubeFace("firstCrossOppositeFace", 'x'));
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);

    c.setSolverFunction([](Cube c)->bool{
        c = c.getBaseCube();
        CubeFace frontSolution(QVector<QVector<char>>{
                                   QVector<char>{'x', 'g', 'x' },
                                   QVector<char>{'x', 'g', 'x' },
                                   QVector<char>{'x', 'x', 'x' }
                               });
        CubeFace upSolution(QVector<QVector<char>>{
                                   QVector<char>{'x', 'r', 'x' },
                                   QVector<char>{'r', 'r', 'r' },
                                   QVector<char>{'x', 'r', 'x' }
                               });
        CubeFace rightSolution(QVector<QVector<char>>{
                                   QVector<char>{'x', 'w', 'x' },
                                   QVector<char>{'x', 'w', 'x' },
                                   QVector<char>{'x', 'x', 'x' }
                               });
        CubeFace emptyFace('x');
        bool frontCorrect = c.getFace(0).equals(frontSolution);
        bool leftCorrect = c.getFace(1).equals(emptyFace);
        bool upCorrect = c.getFace(2).equals(upSolution);
        bool rightCorrect = c.getFace(3).equals(rightSolution);
        bool downCorrect = c.getFace(4).equals(emptyFace);
        bool backCorrect = c.getFace(5).equals(emptyFace);

    return frontCorrect && leftCorrect && upCorrect && rightCorrect && downCorrect && backCorrect;
    });

    return c;
}

Cube CubeBuilder::generateTutorialStep3Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("firstCornersBelowFace", 'x'));
    faces.append(CubeFace("firstCornersLeftFace", 'x'));
    faces.append(CubeFace("firstCornersMainFace", 'r'));
    faces.append(CubeFace("firstCornersRightFace", 'x'));
    faces.append(CubeFace("firstCornersAboveFace", 'x'));
    faces.append(CubeFace("firstCornersOppositeFace", 'x'));
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);

    c.setSolverFunction([](Cube c)->bool{
        c = c.getBaseCube();
        CubeFace frontSolution(QVector<QVector<char>>{
                                   QVector<char>{'g', 'g', 'g' },
                                   QVector<char>{'x', 'g', 'x' },
                                   QVector<char>{'x', 'x', 'x' }
                               });
        CubeFace upSolution(QVector<QVector<char>>{
                                   QVector<char>{'r', 'r', 'r' },
                                   QVector<char>{'r', 'r', 'r' },
                                   QVector<char>{'r', 'r', 'r' }
                               });
        CubeFace rightSolution(QVector<QVector<char>>{
                                   QVector<char>{'w', 'w', 'w' },
                                   QVector<char>{'x', 'w', 'x' },
                                   QVector<char>{'x', 'x', 'x' }
                               });
        CubeFace emptyFace('x');
        bool frontCorrect = c.getFace(0).equals(frontSolution);
        bool leftCorrect = c.getFace(1).equals(emptyFace);
        bool upCorrect = c.getFace(2).equals(upSolution);
        bool rightCorrect = c.getFace(3).equals(rightSolution);
        bool downCorrect = c.getFace(4).equals(emptyFace);
        bool backCorrect = c.getFace(5).equals(emptyFace);

    return frontCorrect && leftCorrect && upCorrect && rightCorrect && downCorrect && backCorrect;
    });

    return c;
}

Cube CubeBuilder::generateTutorialStep4Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("neighborRightBelowFace", 'x'));
    faces.append(CubeFace("neighborRightLeftFace", 'x'));
    faces.append(CubeFace("neighborRightMainFace", 'x'));
    faces.append(CubeFace("neighborRightRightFace", 'x'));
    faces.append(CubeFace('w'));
    faces.append(CubeFace("neighborRightAboveFace", 'x'));
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep5Cube(){
//    Cube c;
//    QVector<CubeFace> faces;
//    faces.append(CubeFace("neighborLeftMainFace", 'x'));
//    faces.append(CubeFace("neighborLeftLeftFace", 'x'));
//    faces.append(CubeFace("neighborLeftAboveFace", 'x'));
//    faces.append(CubeFace("neighborLeftRightFace", 'x'));
//    faces.append(CubeFace("neighborLeftBelowFace", 'x'));
//    faces.append(CubeFace('w'));
//    c.setCubeFaces(faces);
//    c.setCurrentFace(0);
//    return c;
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("finalCrossBelowFace", 'x'));
    faces.append(CubeFace("finalCrossLeftFace", 'x'));
    faces.append(CubeFace("finalCrossMainFace", 'x'));
    faces.append(CubeFace("finalCrossRightFace", 'x'));
    faces.append(CubeFace('w'));
    faces.append(CubeFace("finalCrossAboveFace", 'x'));
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep6Cube(){
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("finalEdgesBelowFace", 'o'));
    faces.append(CubeFace("finalEdgesLeftFace", 'g'));
    faces.append(CubeFace("finalEdgesMainFace", 'y'));
    faces.append(CubeFace("finalEdgesRightFace", 'b'));
    faces.append(CubeFace('w'));
    faces.append(CubeFace("finalEdgesAboveFace", 'r'));
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep7Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("finalCornersBelowFace", 'o'));
    faces.append(CubeFace("finalCornersLeftFace", 'g'));
    faces.append(CubeFace("finalCornersMainFace", 'y'));
    faces.append(CubeFace("finalCornersRightFace", 'b'));
    faces.append(CubeFace('w'));
    faces.append(CubeFace("finalCornersAboveFace", 'r'));
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);
    return c;
}

Cube CubeBuilder::generateTutorialStep8Cube(){
    // TODO: Implement correctly
    Cube c;
    QVector<CubeFace> faces;
    faces.append(CubeFace("orientCornersBelowFace", 'o'));
    faces.append(CubeFace("orientCornersLeftFace", 'g'));
    faces.append(CubeFace("orientCornersMainFace", 'y'));
    faces.append(CubeFace("orientCornersRightFace", 'b'));
    faces.append(CubeFace('w'));
    faces.append(CubeFace('r'));
    c.setCubeFaces(faces, true);
    c.setCurrentFaceID(0);
    return c;
}
