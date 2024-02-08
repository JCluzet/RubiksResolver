#include "RubiksCube.hpp"

RubiksCube::RubiksCube() {
    // Initialisation de l'état du cube
    cubeState = {
        {'F', std::vector<std::string>(9, "W")},
        {'R', std::vector<std::string>(9, "G")},
        {'U', std::vector<std::string>(9, "R")},
        {'B', std::vector<std::string>(9, "Y")},
        {'L', std::vector<std::string>(9, "B")},
        {'D', std::vector<std::string>(9, "O")}
    };
}
void RubiksCube::makeMoveF() {
    // Rotation de la face F elle-même
    std::vector<std::string> tempF = cubeState['F'];
    cubeState['F'][0] = tempF[6];
    cubeState['F'][1] = tempF[3];
    cubeState['F'][2] = tempF[0];
    cubeState['F'][3] = tempF[7];
    cubeState['F'][5] = tempF[1];
    cubeState['F'][6] = tempF[8];
    cubeState['F'][7] = tempF[5];
    cubeState['F'][8] = tempF[2];

    // Sauvegarde temporaire des états pour les faces adjacentes
    std::vector<std::string> tempU = cubeState['U'];
    std::vector<std::string> tempR = cubeState['R'];
    std::vector<std::string> tempD = cubeState['D'];
    std::vector<std::string> tempL = cubeState['L'];

    // Mise à jour des stickers des faces adjacentes
    // U vers R, R vers D, D vers L, L vers U
    cubeState['R'][0] = tempU[6];
    cubeState['R'][3] = tempU[7];
    cubeState['R'][6] = tempU[8];

    cubeState['D'][0] = tempR[6];
    cubeState['D'][1] = tempR[3];
    cubeState['D'][2] = tempR[0];

    cubeState['L'][2] = tempD[0];
    cubeState['L'][5] = tempD[1];
    cubeState['L'][8] = tempD[2];

    cubeState['U'][6] = tempL[8];
    cubeState['U'][7] = tempL[5];
    cubeState['U'][8] = tempL[2];
}


void RubiksCube::makeMoveB()
{

}

void RubiksCube::makeMoveU()
{

}

void RubiksCube::makeMoveD()
{

}

void RubiksCube::makeMoveL()
{

}

void RubiksCube::makeMoveR()
{

}

void RubiksCube::showRubik() {
    std::cout << std::endl;
    auto printRow = [&](const std::vector<std::string>& face, int row) {
        for (int i = 0; i < 3; ++i) {
            std::cout << face[row * 3 + i] << " ";
        }
    };

    // Affichage de la face U (haut)
    for (int i = 0; i < 3; ++i) {
        std::cout << "       "; // Espaces pour centrer la face U au-dessus des autres
        printRow(cubeState.at('U'), i);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Affichage des faces L (gauche), F (front), et R (droite) sur la même ligne
    for (int i = 0; i < 3; ++i) {
        printRow(cubeState.at('L'), i);
        std::cout << " ";
        printRow(cubeState.at('F'), i);
        std::cout << " ";
        printRow(cubeState.at('R'), i);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Affichage de la face D (bas)
    for (int i = 0; i < 3; ++i) {
        std::cout << "       "; // Espaces pour centrer la face D en dessous des autres
        printRow(cubeState.at('D'), i);
        std::cout << std::endl;
    }

    // Affichage de la face B (arrière) en dessous de D, mais inversée puisqu'elle est à l'opposé de F
    std::cout << std::endl;
    std::cout << "       "; // Espaces pour simuler la face B en bas, inversée
    for (int i = 2; i >= 0; --i) {
        printRow(cubeState.at('B'), i);
        std::cout << std::endl;
        std::cout << "       ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "         U\n       L F R\n         D\n         B\n" << std::endl;
}


void RubiksCube::makeMoves(const std::vector<std::string>& moves) {
    for (const auto& move : moves) {
        char face = move[0];
        if(face == 'F')
            makeMoveF();
        else if(face == 'B')
            makeMoveB();
        else if(face == 'U')
            makeMoveU();
        else if(face == 'D')
            makeMoveD();
        else if(face == 'L')
            makeMoveL();
        else if(face == 'R')
            makeMoveR();
    }
}

