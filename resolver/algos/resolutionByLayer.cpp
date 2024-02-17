#include "../RubiksCube.hpp"

void RubiksCube::resolutionByLayers()
{
    std::cout << "Resolution by layers :" << std::endl;

    std::cout << "1. Make a cross on the yellow layer" << std::endl;

    CrossOnTopLayer();

    std::cout << "2. Put the cross on the white layer" << std::endl;
    //  std::cout << "Click on a key to continue" << std::endl;
    // getchar();

    PutCrossOnBottomLayer();

    std::cout << "3. Put White Corners in Position" << std::endl;

    PutWhiteCorners();

    std::cout << "4. Next a venir" << std::endl;

    // PutColoredEdges();

    return ;
}


int RubiksCube::getIndexofColoroOnFace(std::string color, char face)
{
    for (int i = 0; i < 9; i++)
    {
        if (cubeState[face][i] == color)
        {
            std::cout << "index de la couleur " << color << " sur la face " << face << " est : " << i << std::endl;
            return i;
        }
    }
    return -1;
}


bool RubiksCube::checkCornerDown(int index) {
    std::cout << "CheckCornerDown()" << std::endl;
    switch(index) {
        case 0:
            if (cubeState['L'][6] != "B" && cubeState['F'][6] != "R")
                return true;
        case 2:
            if (cubeState['F'][8] != "R" && cubeState['R'][6] != "G")
                return true;
        case 6:
            if (cubeState['L'][6] != "B" && cubeState['B'][0] != "O")
                return true;
        case 8:
            if (cubeState['R'][8] != "G" && cubeState['B'][2] != "O")
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
    std::cout << "isBottomLayer()" << std::endl;
    if (face == 'D')
        return (true);
    else if (face == 'B') {
        if (index == 0 || index == 1 || index == 2)
            return (true);
    } else if (face == 'R' || face == 'L' || face == 'F') {
        if (index == 6 || index == 7 || index == 8)
            return (true);
    }
    return (false);
}

int whichCorner(char face, int index) {
    std::cout << "whichCorner()" << std::endl;
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

std::string RubiksCube::whichColor(char face, int index, int cornerPosition) {
    std::cout << "whichColor()" << std::endl;
    std::cout << "CornerPosition = " << cornerPosition << std::endl;
    std::string colors;
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
            // std::cout << "Valeurs : B[8]: " << cubeState['B'][8] << " R[2]: " << cubeState['R'][2] << " U[2]: " << cubeState['U'][2] << std::endl;
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
    std::cout << "Colors Found: " << colors[0] << ", " << colors[1] << std::endl;
    return (colors);
}

int RubiksCube::combination(char face, int index) {
    std::cout << "combination()" << std::endl;
    int cornerPosition = whichCorner(face, index);
    std::string colors = whichColor(face, index, cornerPosition);
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
    std::cout << "isItFacingYou()" << std::endl;
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

void RubiksCube::getOutOfBottomLayer(char face, int index) {
    std::cout << "getOutOfBottomLayer()" << std::endl;
    int corner = whichCorner(face, index);
    switch(corner) {
        case 1:
            parseMove("L'", true); // L' U L
            parseMove("U", true);
            parseMove("L", true);
            break;
        case 2:
            parseMove("F'", true); // F' U F
            parseMove("U", true);
            parseMove("F", true);
            break;
        case 3:
            parseMove("B'", true); // B' U B
            parseMove("U", true);
            parseMove("B", true);
            break;
        case 4:
            parseMove("R'", true); // R' U R
            parseMove("U", true);
            parseMove("R", true);
            break;
    }
}

int actualiseWhereWeAre(int whereWeAre) {
        if (whereWeAre == 1)
            return(5);
        else if (whereWeAre == 2)
            return(6);
        else if (whereWeAre == 3)
            return(7);
        else if (whereWeAre == 4)
            return(8);
        if (whereWeAre == 5)
            return(7);
        else if (whereWeAre == 6)
            return(5);
        else if (whereWeAre == 7)
            return(8);
        else if (whereWeAre == 8)
            return(6);
}

void RubiksCube::putCornerInPosition(int whereToGo, int whereWeAre) {
    std::cout << "putCornerInPosition()" << std::endl;
    std::cout << "WhereWeAre: " << whereWeAre << std::endl;
    std::cout << "WhereToGo: " << whereToGo << std::endl;
    whereWeAre = actualiseWhereWeAre(whereWeAre);
    int i = whereWeAre - whereToGo;
    while (i != 4) {
    std::cout << "WhereWeAre Boucle: " << whereWeAre << std::endl;
        parseMove("U", true);
        whereWeAre = actualiseWhereWeAre(whereWeAre);
        i = whereWeAre - whereToGo;
    }
}

void RubiksCube::sendUpAlgo(char face) {
    std::cout << "sendUpAlgo()" << std::endl;
    std::cout << "Face : " << face << std::endl;
    std::string moveWithPrime = std::string(1, face) + '\'';

    // Define the moves in the algorithm
    std::vector<std::string> moves = {
        moveWithPrime,
        "U2",
        std::string(1, face),
        "U",
        moveWithPrime,
        "U'",
        std::string(1, face)
    };

    // Perform each move in the algorithm
    for (const auto& move : moves) {
        parseMove(move, true);
    }
}

void RubiksCube::doUpAlgo(int whereToGo) {
    std::cout << "doUpAlgo()" << std::endl;
    switch(whereToGo) {
        case 1: // F' D2 F D F' D' F
            sendUpAlgo('L');
            break;
        case 2: // R' D2 R D R' D' R
            sendUpAlgo('F');
            break;
        case 3: // L' D2 L D L' D' L
            sendUpAlgo('B');
            break;
        case 4: // B' D2 B D B' D' B
            sendUpAlgo('R');
            break;
    }
}

void RubiksCube::sendFacingYouALgo(char face) {
    std::cout << "sendFacingYouALgo()" << std::endl;
    std::cout << "Face : " << face << std::endl;
    std::string moveWithPrime = std::string(1, face) + '\'';

    // Define the moves in the algorithm
    std::vector<std::string> moves = {
        std::string(1, face),
        "U",
        moveWithPrime,
    };

    // Perform each move in the algorithm
    for (const auto& move : moves) {
        parseMove(move, true);
    }
}

void RubiksCube::doFacingYouAlgo(int whereToGo) {
    std::cout << "doFacingYouAlgo()" << std::endl;
    switch(whereToGo) {
        case 1: // L D L'
            sendFacingYouALgo('F');
            break;
        case 2: //F D F'
            sendFacingYouALgo('R');
            break;
        case 3: // B D B'
            sendFacingYouALgo('L');
            break;
        case 4: // R D R'
            sendFacingYouALgo('B');
            break;
    }
}

void RubiksCube::sendFacingRightAlgo(char face) {
    std::cout << "sendFacingRightAlgo()" << std::endl;
    std::cout << "Face : " << face << std::endl;
    std::string moveWithPrime = std::string(1, face) + '\'';

    // Define the moves in the algorithm
    std::vector<std::string> moves = {
        moveWithPrime,
        "U",
        std::string(1, face),
    };

    // Perform each move in the algorithm
    for (const auto& move : moves) {
        parseMove(move, true);
    }
}

void RubiksCube::doFacingRightAlgo(int whereToGo) {
    std::cout << "doFacingRightAlgo()" << std::endl;
    switch(whereToGo) {
        case 1: // F' D' F
            sendFacingRightAlgo('L');
            break;
        case 2: // R' D' R
            sendFacingRightAlgo('F');
            break;
        case 3: // L' D' L
            sendFacingRightAlgo('B');
            break;
        case 4: // B' D' B
            sendFacingRightAlgo('R');
            break;
    }
}


char RubiksCube::whichFace(int whereToGo) {
    std::cout << "whichFace()" << std::endl;
    switch(whereToGo) {
        case 1:
            if (cubeState['U'][6] == "W")
                return ('U');
            else if (cubeState['L'][2] == "W")
                return ('L');
            else if (cubeState['F'][0] == "W")
                return ('F');
            break;
        case 2:
            if (cubeState['U'][8] == "W")
                return ('U');
            else if (cubeState['R'][0] == "W")
                return ('R');
            else if (cubeState['F'][2] == "W")
                return ('F');
            break;
        case 3:
            if (cubeState['U'][0] == "W")
                return ('U');
            else if (cubeState['L'][0] == "W")
                return ('L');
            else if (cubeState['B'][6] == "W")
                return ('B');
            break;
        case 4:
            if (cubeState['U'][2] == "W")
                return ('U');
            else if (cubeState['R'][2] == "W")
                return ('R');
            else if (cubeState['B'][8] == "W")
                return ('B');
            break;
    }
}

void RubiksCube::doCornerAlgorithm(int whereToGo) {
    std::cout << "doCornerAlgorithm()" << std::endl;
    char face = whichFace(whereToGo);
    if (face == 'U')
        doUpAlgo(whereToGo); // WHILE FACE FACING YOU R' D2 R D R' D' R
    else if (isItFacingYou(whereToGo, face))
        doFacingYouAlgo(whereToGo); // F D F'
    else
        doFacingRightAlgo(whereToGo); // R' D' R
}

bool RubiksCube::checkWhiteFace() {
    for (int i = 0; i < 9; i++) {
        if (cubeState['D'][i] != "W")
            return (false);
    }
    for (auto &face : {'F', 'R', 'L'})
        for (int i = 6; i < 9; i++) {
            if (cubeState[face][i] != cubeState[face][4])
                return (false);
        }
    for (int i = 0; i < 2; i++) {
        if (cubeState['B'][i] != cubeState['B'][4])
            return (false);
    }
    return (true);

}

void RubiksCube::PutWhiteCorners() {
    std::cout << "PutWhiteCorners()" << std::endl;
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
                    if (!(face == 'D' && checkCornerDown(index))) {
                        std::cout << "Corner trouve a face :" << face << "et index : " << index << std::endl;
                        int whereToGo = combination(face, index);
                        std::cout << "Corner Number To Go: " << whereToGo << std::endl;
                        if (isBottomLayer(face, index))
                            getOutOfBottomLayer(face, index);
                        putCornerInPosition(whereToGo, whichCorner(face, index));
                        doCornerAlgorithm(whereToGo);
                        if (checkWhiteFace())
                            return ;
                    }
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
    int index = -1;
    while((index = getIndexofColoroOnFace("W", 'U')) != -1)
    {
        std::cout << "index actuel : " << index << std::endl;
        std::cout << "je rentre dans le 1" << std::endl;
        // Vérifie si l'arête à cet index est blanche
        if (cubeState['U'][index] == "W") {
            std::cout << "je rentre dans le 2" << std::endl;
            std::string color; // Pour stocker la couleur adjacente à l'arête blanche
            char targetFace; // Pour stocker la face cible pour cette couleur

            // Déterminer la couleur adjacente
            if (index == 1) {
                color = cubeState['B'][7];
            } else if (index == 3) {
                color = cubeState['L'][1];
            } else if (index == 5) {
                color = cubeState['R'][1];
            } else if (index == 7) {
                color = cubeState['F'][1];
            }

            if (color == "R") {
                targetFace = 'F';
            }
            else if (color == "G") {
                targetFace = 'R';
            }
            else if (color == "O") {
                targetFace = 'B';
            }
            else if (color == "B") {
                targetFace = 'L';
            }
            else if (color == "W") {
                targetFace = 'D';
            }
            else if (color == "Y") {
                targetFace = 'U';
            }

            // Affiche la couleur et la face cible
            std::cout << "Couleur adjacente: " << color << ", Face cible: " << targetFace << std::endl;

            // Tourner la face U jusqu'à ce que l'arête blanche soit au-dessus de sa face cible
            if (targetFace == 'B')
            {
                while (cubeState['B'][7] != "O")
                    parseMove("U", true);
            }
            else 
            {
                while (cubeState[targetFace][1] != color)
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