#ifndef CUBEBUILDER_H
#define CUBEBUILDER_H

#include "Cube.h"

class CubeBuilder
{

// Will build the cube based on what the user is on
public:
    static Cube generateRandomCube();
    static Cube generateDebugCube();
    static Cube generateSolvedCube();
    static Cube generateTutorialStep1Cube();
    static Cube generateTutorialStep2Cube();
    static Cube generateTutorialStep3Cube();
    static Cube generateTutorialStep4Cube();
    static Cube generateTutorialStep5Cube();
    static Cube generateTutorialStep6Cube();
    static Cube generateTutorialStep7Cube();
    static Cube generateTutorialStep8Cube();
};

#endif // CUBEBUILDER_H
