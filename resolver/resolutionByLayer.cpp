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
                    // checker les couleurs sur le cote du cube qu'on regarde donc index

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