#include "RubiksCube.hpp"

void RubiksCube::resolutionByLayers()
{
    std::cout << "Resolution by layers :" << std::endl;

    std::cout << "1. Make a cross on the yellow layer" << std::endl;

    CrossOnTopLayer();

    std::cout << "2. Put the cross on the white layer" << std::endl;
     std::cout << "Click on a key to continue" << std::endl;
    getchar();

    // PutCrossOnBottomLayer();
}


bool RubiksCube::checkCornerDown(int index) {
    switch(index) {
        case 0:
            if (cubeState['L'][6] != "B" && cubeState['F'][6] != "R")
                return true;
        case 2:
            if (cubeState['F'][8] != "R" && cubeState['R'][8] != "G")
                return true;
        case 6:
            if (cubeState['L'][0] != "B" && cubeState['B'][0] != "O")
                return true;
        case 8:
            if (cubeState['R'][2] != "G" && cubeState['B'][2] != "O")
                return true;
    }
    return false;
}

// 8 positions differentes possibles, plusieurs orientations possibles
// corners possibles sooit orange/vert;orange/bleu soit rouge/vert;rouge/bleu


// fonction qui retire le corner de la bottom layer (turn la face sur laquelle il est (right/left) puis qui le retire avec up U et qui remet la croix blanche ensuite)
// fonction qui met le corner blanc a la bonne position en fonction de l'index 1 2 3 ou 4 de l'autre fonction
// fonction qui fait l'algorithme en fonction de l'orientation


bool isBottomLayer(char face, int index) {
    if (face == 'D')
        return (true);
    else if (face == 'B')
        if (index == 0 || index == 1 || index == 2)
            return (true);
    else if (face == 'R' || face == 'L' || face == 'F')
        if (index == 6 || index == 7 || index == 8)
            return (true);
    return (false);
}

int whichCorner(char face, int index) {
    switch(index) {
        case 0:
            if (face == 'F')
                return 5;
            else if (face == 'B')
                return 3;
            else if (face == 'D')
                return 1;
            else if (face == 'U' || face == 'L')
                return 7;
            else if (face == 'R')
                return 6;
            break;
        case 2:
            if (face == 'F')
                return 6;                
            else if (face == 'B')
                return 4;
            else if (face == 'D')
                return 2;
            else if (face == 'U' || face == 'R')
                return 8;
            else if (face == 'L')
                return 5;
            break;
        case 6:
            if (face == 'F')
                return 1;
            else if (face == 'B')
                return 7;
            else if (face == 'D' || face == 'L')
                return 3;
            else if (face == 'U')
                return 5;
            else if (face == 'R')
                return 2;
            break;
        case 8:
            if (face == 'F')
                return 2;
            else if (face == 'B')
                return 8;
            else if (face == 'D' || face == 'R')
                return 4;
            else if (face == 'U')
                return 6;
            else if (face == 'L')
                return 1;
            break;
    }
}

char* RubiksCube::whichColor(char face, int index, int cornerPosition) {
    char *colors;
    switch(cornerPosition) {
        case 1:
            if (cubeState['F'][6] == "R" || cubeState['L'][8] == "R" || cubeState['D'][0] == "R") {
                colors[0] = 'R';
                if (cubeState['F'][6] == "B" || cubeState['L'][8] == "B" || cubeState['D'][0] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][6] == "G" || cubeState['L'][8] == "G" || cubeState['D'][0] == "G")
                    colors[1] = 'G';
            } else if (cubeState['F'][6] == "O" || cubeState['L'][8] == "O" || cubeState['D'][0] == "O") {
                colors[0] = 'O';
                if (cubeState['F'][6] == "B" || cubeState['L'][8] == "B" || cubeState['D'][0] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][6] == "G" || cubeState['L'][8] == "G" || cubeState['D'][0] == "G")
                    colors[1] = 'G';
            }
            break;
        case 2:
            if (cubeState['F'][8] == "R" || cubeState['R'][6] == "R" || cubeState['D'][2] == "R") {
                colors[0] = 'R';
                if (cubeState['F'][8] == "B" || cubeState['R'][6] == "B" || cubeState['D'][2] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][8] == "G" || cubeState['R'][6] == "G" || cubeState['D'][2] == "G")
                    colors[1] = 'G';
            } else if (cubeState['F'][8] == "O" || cubeState['R'][6] == "O" || cubeState['D'][2] == "O") {
                colors[0] = 'O';
                if (cubeState['F'][8] == "B" || cubeState['R'][6] == "B" || cubeState['D'][2] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][8] == "G" || cubeState['R'][6] == "G" || cubeState['D'][2] == "G")
                    colors[1] = 'G';
            }
            break;
        case 3:
            if (cubeState['B'][0] == "R" || cubeState['L'][6] == "R" || cubeState['D'][6] == "R") {
                colors[0] = 'R';
                if (cubeState['B'][0] == "B" || cubeState['L'][6] == "B" || cubeState['D'][6] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][0] == "G" || cubeState['L'][6] == "G" || cubeState['D'][6] == "G")
                    colors[1] = 'G';
            } else if (cubeState['B'][0] == "O" || cubeState['L'][6] == "O" || cubeState['D'][6] == "O") {
                colors[0] = 'O';
                if (cubeState['B'][0] == "B" || cubeState['L'][6] == "B" || cubeState['D'][6] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][0] == "G" || cubeState['L'][6] == "G" || cubeState['D'][6] == "G")
                    colors[1] = 'G';
            }
            break;
        case 4:
            if (cubeState['B'][2] == "R" || cubeState['R'][8] == "R" || cubeState['D'][8] == "R") {
                colors[0] = 'R';
                if (cubeState['B'][2] == "B" || cubeState['R'][8] == "B" || cubeState['D'][8] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][2] == "G" || cubeState['R'][8] == "G" || cubeState['D'][8] == "G")
                    colors[1] = 'G';
            } else if (cubeState['B'][2] == "O" || cubeState['R'][8] == "O" || cubeState['D'][8] == "O") {
                colors[0] = 'O';
                if (cubeState['B'][2] == "B" || cubeState['R'][8] == "B" || cubeState['D'][8] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][2] == "G" || cubeState['R'][8] == "G" || cubeState['D'][8] == "G")
                    colors[1] = 'G';
            }
            break;
        case 5:
            if (cubeState['F'][0] == "R" || cubeState['L'][2] == "R" || cubeState['U'][6] == "R") {
                colors[0] = 'R';
                if (cubeState['F'][0] == "B" || cubeState['L'][2] == "B" || cubeState['U'][6] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][0] == "G" || cubeState['L'][2] == "G" || cubeState['U'][6] == "G")
                    colors[1] = 'G';
            } else if (cubeState['F'][0] == "O" || cubeState['L'][2] == "O" || cubeState['U'][6] == "O") {
                colors[0] = 'O';
                if (cubeState['F'][0] == "B" || cubeState['L'][2] == "B" || cubeState['U'][6] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][0] == "G" || cubeState['L'][2] == "G" || cubeState['U'][6] == "G")
                    colors[1] = 'G';
            }
            break;
        case 6:
            if (cubeState['F'][2] == "R" || cubeState['R'][0] == "R" || cubeState['U'][8] == "R") {
                colors[0] = 'R';
                if (cubeState['F'][2] == "B" || cubeState['R'][0] == "B" || cubeState['U'][8] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][2] == "G" || cubeState['R'][0] == "G" || cubeState['U'][8] == "G")
                    colors[1] = 'G';
            } else if (cubeState['F'][2] == "O" || cubeState['R'][0] == "O" || cubeState['U'][8] == "O") {
                colors[0] = 'O';
                if (cubeState['F'][2] == "B" || cubeState['R'][0] == "B" || cubeState['U'][8] == "B")
                    colors[1] = 'B';
                else if (cubeState['F'][2] == "G" || cubeState['R'][0] == "G" || cubeState['U'][8] == "G")
                    colors[1] = 'G';
            }
            break;
        case 7:
            if (cubeState['B'][6] == "R" || cubeState['L'][0] == "R" || cubeState['U'][0] == "R") {
                colors[0] = 'R';
                if (cubeState['B'][6] == "B" || cubeState['L'][0] == "B" || cubeState['U'][0] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][6] == "G" || cubeState['L'][0] == "G" || cubeState['U'][0] == "G")
                    colors[1] = 'G';
            } else if (cubeState['B'][6] == "O" || cubeState['L'][0] == "O" || cubeState['U'][0] == "O") {
                colors[0] = 'O';
                if (cubeState['B'][6] == "B" || cubeState['L'][0] == "B" || cubeState['U'][0] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][6] == "G" || cubeState['L'][0] == "G" || cubeState['U'][0] == "G")
                    colors[1] = 'G';
            }
            break;
        case 8:
            if (cubeState['B'][8] == "R" || cubeState['R'][2] == "R" || cubeState['U'][2] == "R") {
                colors[0] = 'R';
                if (cubeState['B'][8] == "B" || cubeState['R'][2] == "B" || cubeState['U'][2] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][8] == "G" || cubeState['R'][2] == "G" || cubeState['U'][2] == "G")
                    colors[1] = 'G';
            } else if (cubeState['B'][8] == "O" || cubeState['R'][2] == "O" || cubeState['U'][2] == "O") {
                colors[0] = 'O';
                if (cubeState['B'][8] == "B" || cubeState['R'][2] == "B" || cubeState['U'][2] == "B")
                    colors[1] = 'B';
                else if (cubeState['B'][8] == "G" || cubeState['R'][2] == "G" || cubeState['U'][2] == "G")
                    colors[1] = 'G';
            }
            break;
    }
    return (colors);
}

int RubiksCube::combination(char face, int index) {
    int cornerPosition = whichCorner(face, index);
    char *colors = whichColor(face, index, cornerPosition);
    if (colors[0] == 'R') {
        if (colors[1] == 'B')
            return 1;
        else
            return 2;
    } else if (colors[0] == 'O') {
        if (colors[1] == 'B')
            return 3;
        else
            return 4;
    }
}

bool isItFacingYou(int cornerPosition, char face) {
    switch(cornerPosition) {
        case 1:
            if (face == 'L')
                return (false);
            return (true);
        case 2:
            if (face == 'F')
                return (false);
            return (true);
        case 3:
            if (face == 'B')
                return (false);
            return (true);
        case 4:
            if (face == 'R')
                return (false);
            return (true);
    }
}

void doCornerAlgorithm(int whereToGo, char face) {
    if (face == 'U')
        doUpAlgo() // WHILE FACE FACING YOU R' D2 R D R' D' R
    else if (isItFacingYou(whereToGo, face))
        doFacingYouAlgo(); // F D F'
    else
        doFacingRightAlgo(); // R' D' R
}

void RubiksCube::PutWhiteCorners() {
    auto hasWhiteCorner = [&]() -> bool {
        for (auto &face : {'F', 'R', 'B', 'L', 'U', 'D'}) {
            for (int index : {0, 2, 6, 8}) {
                if (cubeState[face][index] == "W") {
                    if (face == 'D' && checkCornerDown(index))
                        break;
                    std::cout << "Corner trouve a face :" << face << "et index : " << index << std::endl;
                    return true;
                }
            }
        }
        std::cout << "Plus de corners blancs chef ! " << std::endl;
        return false;
    };

    while (hasWhiteCorner()) {
        for (auto &face : {'F', 'R', 'B', 'L', 'D', 'U'}) {
            for (int index : {0, 2, 6, 8}) {
                if (cubeState[face][index] == "W") {
                    int whereToGo = combination(face, index);
                    if (isBottomLayer())
                        getOutOfBottomLayer();
                    char new_face = putCornerInPosition(whereToGo);
                    doCornerAlgorithm(whereToGo, new_face);
                }
            }
        }
    }
}

void RubiksCube::PutCrossOnBottomLayer()
{
    std::cout << "Put the cross on the white layer (D):" << std::endl;

    // 1 . find a white edge that is on the yellow face
    // 2 . look at its index
    // 3.       --> find the color on the edge that is not white
    // 4.          --> if the index is 1 , find the color in the index 7 of the B face
    // 5.          --> if the index is 3 , find the color in the index 1 of the L face
    // 6.          --> if the index is 5 , find the color in the index 1 of the R face
    // 7.          --> if the index is 7 , find the color in the index 1 of the F face
    // 8.       --> SAVE THE COLOR
    // 9.       --> turn the face UP (yellow) until the color is on the face color ( U = YELLOW, F = RED, R = GREEN, B = ORANGE, L = BLUE, D = WHITE)
    // 10. when the color is on the face color, turn this face 2 times

    // Boucle pour chaque position possible d'une arête blanche sur la face U
    for (int index : {1, 3, 5, 7}) {
        // Vérifie si l'arête à cet index est blanche
        if (cubeState['U'][index] == "W") {
            std::string color; // Pour stocker la couleur adjacente à l'arête blanche
            char targetFace; // Pour stocker la face cible pour cette couleur

            // Déterminer la couleur adjacente et la face cible
            if (index == 1) {
                color = cubeState['B'][7]; targetFace = 'B';
            } else if (index == 3) {
                color = cubeState['L'][1]; targetFace = 'L';
            } else if (index == 5) {
                color = cubeState['R'][1]; targetFace = 'R';
            } else if (index == 7) {
                color = cubeState['F'][1]; targetFace = 'F';
            }

            // Affiche la couleur et la face cible
            std::cout << "Couleur adjacente: " << color << ", Face cible: " << targetFace << std::endl;

            // Tourner la face U jusqu'à ce que l'arête blanche soit au-dessus de sa face cible
            while (cubeState[targetFace][4] != color) {
                parseMove("U", true);
            }

            // Une fois en position, tourner la face cible 2 fois pour placer l'arête en bas
            std::string move = std::string(1, targetFace);
            move = move + "2";
            parseMove(move, true);
        }
    }
}

void RubiksCube::CrossOnTopLayer()
{
    std::cout << "Forming white cross on bottom layer (D):" << std::endl;

    auto hasWhiteEdge = [&]() -> bool {
        for (auto &face : {'F', 'R', 'B', 'L', 'D'}) {
            for (int index : {1, 3, 5, 7}) {
                if (cubeState[face][index] == "W") {
                    std::cout << "Arrete trouvee a face :" << face << " et index : " << index << std::endl;
                    return (true);
                }
            }
        }
        std::cout << "Plus darete chef ! " << std::endl;
        return (false);
    };

    while (hasWhiteEdge()) {
        for (auto &face : {'F', 'R', 'B', 'L', 'D'}) {
            for (int index : {1, 3, 5, 7}) {
                if (cubeState[face][index] == "W") {
                    if (face == 'W' && checkCornerDown(index))
                        break;
                    std::cout << "White edge found on face " << face << " at index " << index << std::endl;
                    if (face == 'D') {
                        if (index == 3)
                            while (cubeState['U'][3] == "W")
                                parseMove("U", true);
                        else if (index == 5)
                            while (cubeState['U'][5] == "W")
                                parseMove("U", true);
                        else if (index == 1)
                            while (cubeState['U'][7] == "W")
                                parseMove("U", true);
                        else if (index == 7)
                            while (cubeState['U'][1] == "W")
                                parseMove("U", true);

                        switch (index) {
                        case 1:
                            parseMove("F2", true);
                            break;
                        case 3:
                            parseMove("L2", true);
                            break;
                        case 5:
                            parseMove("R2", true);
                            break;
                        case 7:
                            parseMove("B2", true);
                            break;
                        }
                    }
                    else {
                        switch (face) {
                        case 'F':
                            if (index == 3 || index == 5) {
                                while (cubeState['U'][index] == "W")
                                    parseMove("U", true);
                                if (index == 3)
                                    parseMove("L'", true);
                                else
                                    parseMove("R", true);
                            } else {
                                while (cubeState['U'][7] == "W" && index != 1)
                                    parseMove("U", true);
                                parseMove("F", true);
                                if (index == 1) {
                                    while (cubeState['U'][5] == "W")
                                        parseMove("U", true);
                                    parseMove("R", true);
                                } else {
                                    while (cubeState['U'][3] == "W")
                                        parseMove("U", true);
                                    parseMove("L'", true);
                                }
                            }
                            break;
                        case 'B':
                            if (index == 3 || index == 5) {
                                while (cubeState['U'][index] == "W")
                                    parseMove("U", true);
                                if (index == 5)
                                    parseMove("R'", true);
                                else
                                    parseMove("L", true);
                            } else {
                                while (cubeState['U'][1] == "W" && index != 7)
                                    parseMove("U", true);
                                parseMove("B", true);
                                if (index == 1) {
                                    while (cubeState['U'][5] == "W")
                                        parseMove("U", true);
                                    parseMove("R'", true);
                                } else {
                                    while (cubeState['U'][3] == "W")
                                        parseMove("U", true);
                                    parseMove("L", true);
                                }
                            }
                            break;
                        case 'R':
                            if (index == 3 || index == 5) {
                                if (index == 3) {
                                    while (cubeState['U'][7] == "W")
                                        parseMove("U", true);
                                    parseMove("F'", true);
                                } else {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B", true);
                                }
                            } else {
                                while (cubeState['U'][5] == "W" && index != 1)
                                    parseMove("U", true);
                                parseMove("R", true);
                                if (index == 1) {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B", true);
                                }
                                else {
                                    while (cubeState['U'][7] == "W")
                                        parseMove("U", true);
                                    parseMove("F'", true);
                                }
                            }
                            break;
                        case 'L':
                            if (index == 3 || index == 5) {
                                if (index == 3) {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B'", true);
                                } else {
                                    while (cubeState['U'][7] == "W")
                                        parseMove("U", true);
                                    parseMove("F", true);
                                }
                            } else {
                                while (cubeState['U'][3] == "W" && index != 1)
                                    parseMove("U", true);
                                parseMove("L", true);
                                if (index == 7) {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B'", true);
                                } else {
                                    while (cubeState['U'][7] == "W")
                                        parseMove("U", true);
                                    parseMove("F", true);
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}