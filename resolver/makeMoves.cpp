#include "RubiksCube.hpp"

RubiksCube::RubiksCube() {
    // Initialisation de l'état du cube
    solution = "";
    cubeState = {
        {'F', std::vector<std::string>(9, "R")}, // GOOD
        {'R', std::vector<std::string>(9, "G")}, // GOOD
        {'U', std::vector<std::string>(9, "Y")}, // GOOD
        {'B', std::vector<std::string>(9, "O")}, // GOOD
        {'L', std::vector<std::string>(9, "B")}, // GOOD
        {'D', std::vector<std::string>(9, "W")}  // GOOD
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


void RubiksCube::makeMoveB() {
    // Rotation de la face B elle-même
    std::vector<std::string> tempB = cubeState['B'];
    cubeState['B'][0] = tempB[6];
    cubeState['B'][1] = tempB[3];
    cubeState['B'][2] = tempB[0];
    cubeState['B'][3] = tempB[7];
    cubeState['B'][5] = tempB[1];
    cubeState['B'][6] = tempB[8];
    cubeState['B'][7] = tempB[5];
    cubeState['B'][8] = tempB[2];

    // Sauvegarde temporaire des états pour les faces adjacentes
    std::vector<std::string> tempU = cubeState['U'];
    std::vector<std::string> tempR = cubeState['R'];
    std::vector<std::string> tempD = cubeState['D'];
    std::vector<std::string> tempL = cubeState['L'];

    // Mise à jour des stickers des faces adjacentes pour la rotation de B
    cubeState['U'][0] = tempR[2];
    cubeState['U'][1] = tempR[5];
    cubeState['U'][2] = tempR[8];

    cubeState['L'][0] = tempU[2];
    cubeState['L'][3] = tempU[1];
    cubeState['L'][6] = tempU[0];

    cubeState['D'][6] = tempL[0];
    cubeState['D'][7] = tempL[3];
    cubeState['D'][8] = tempL[6];

    cubeState['R'][2] = tempD[8];
    cubeState['R'][5] = tempD[7];
    cubeState['R'][8] = tempD[6];
}

void RubiksCube::makeMoveU() {
    // Rotation de la face U elle-même
    std::vector<std::string> tempU = cubeState['U'];
    cubeState['U'][0] = tempU[6];
    cubeState['U'][1] = tempU[3];
    cubeState['U'][2] = tempU[0];
    cubeState['U'][3] = tempU[7];
    cubeState['U'][5] = tempU[1];
    cubeState['U'][6] = tempU[8];
    cubeState['U'][7] = tempU[5];
    cubeState['U'][8] = tempU[2];

    // Sauvegarde temporaire des états pour les faces adjacentes
    std::vector<std::string> tempF = cubeState['F'];
    std::vector<std::string> tempR = cubeState['R'];
    std::vector<std::string> tempB = cubeState['B'];
    std::vector<std::string> tempL = cubeState['L'];

    // Mise à jour des stickers des faces adjacentes pour la rotation de U
    cubeState['F'][0] = tempR[0];
    cubeState['F'][1] = tempR[1];
    cubeState['F'][2] = tempR[2];

    cubeState['R'][0] = tempB[8];
    cubeState['R'][1] = tempB[7];
    cubeState['R'][2] = tempB[6];

    cubeState['B'][8] = tempL[0];
    cubeState['B'][7] = tempL[1];
    cubeState['B'][6] = tempL[2];

    cubeState['L'][0] = tempF[0];
    cubeState['L'][1] = tempF[1];
    cubeState['L'][2] = tempF[2];
}


void RubiksCube::makeMoveD() {
    // Rotation de la face D elle-même
    std::vector<std::string> tempD = cubeState['D'];
    cubeState['D'][0] = tempD[6];
    cubeState['D'][1] = tempD[3];
    cubeState['D'][2] = tempD[0];
    cubeState['D'][3] = tempD[7];
    cubeState['D'][5] = tempD[1];
    cubeState['D'][6] = tempD[8];
    cubeState['D'][7] = tempD[5];
    cubeState['D'][8] = tempD[2];

    // Sauvegarde temporaire des états pour les faces adjacentes
    std::vector<std::string> tempF = cubeState['F'];
    std::vector<std::string> tempR = cubeState['R'];
    std::vector<std::string> tempB = cubeState['B'];
    std::vector<std::string> tempL = cubeState['L'];

    cubeState['F'][6] = tempL[6];
    cubeState['F'][7] = tempL[7];
    cubeState['F'][8] = tempL[8];

    cubeState['R'][6] = tempF[6];
    cubeState['R'][7] = tempF[7];
    cubeState['R'][8] = tempF[8];

    cubeState['L'][6] = tempB[2];
    cubeState['L'][7] = tempB[1];
    cubeState['L'][8] = tempB[0];

    cubeState['B'][2] = tempR[6];
    cubeState['B'][1] = tempR[7];
    cubeState['B'][0] = tempR[8];
}

void RubiksCube::makeMoveL() {
    // Rotation de la face L elle-même dans le sens des aiguilles d'une montre
    std::vector<std::string> tempL = cubeState['L'];
    cubeState['L'][0] = tempL[6];
    cubeState['L'][1] = tempL[3];
    cubeState['L'][2] = tempL[0];
    cubeState['L'][3] = tempL[7];
    cubeState['L'][5] = tempL[1];
    cubeState['L'][6] = tempL[8];
    cubeState['L'][7] = tempL[5];
    cubeState['L'][8] = tempL[2];

    // Sauvegarde temporaire des états pour les faces adjacentes
    std::vector<std::string> tempF = cubeState['F'];
    std::vector<std::string> tempU = cubeState['U'];
    std::vector<std::string> tempB = cubeState['B'];
    std::vector<std::string> tempD = cubeState['D'];

    // Mise à jour des stickers des faces adjacentes pour la rotation de L
    cubeState['U'][0] = tempB[0];
    cubeState['U'][3] = tempB[3];
    cubeState['U'][6] = tempB[6];

    cubeState['F'][0] = tempU[0];
    cubeState['F'][3] = tempU[3];
    cubeState['F'][6] = tempU[6];

    cubeState['D'][0] = tempF[0];
    cubeState['D'][3] = tempF[3];
    cubeState['D'][6] = tempF[6];

    cubeState['B'][0] = tempD[0];
    cubeState['B'][3] = tempD[3];
    cubeState['B'][6] = tempD[6];
}

void RubiksCube::makeMoveR() {
    // Rotation de la face R elle-même dans le sens des aiguilles d'une montre
    std::vector<std::string> tempR = cubeState['R'];
    cubeState['R'][0] = tempR[6];
    cubeState['R'][1] = tempR[3];
    cubeState['R'][2] = tempR[0];
    cubeState['R'][3] = tempR[7];
    cubeState['R'][5] = tempR[1];
    cubeState['R'][6] = tempR[8];
    cubeState['R'][7] = tempR[5];
    cubeState['R'][8] = tempR[2];

    // Sauvegarde temporaire des états pour les faces adjacentes
    std::vector<std::string> tempF = cubeState['F'];
    std::vector<std::string> tempU = cubeState['U'];
    std::vector<std::string> tempB = cubeState['B'];
    std::vector<std::string> tempD = cubeState['D'];

    // Mise à jour des stickers des faces adjacentes pour la rotation de R correctement
    cubeState['U'][2] = tempF[2];
    cubeState['U'][5] = tempF[5];
    cubeState['U'][8] = tempF[8];

    cubeState['F'][2] = tempD[2];
    cubeState['F'][5] = tempD[5];
    cubeState['F'][8] = tempD[8];

    cubeState['D'][2] = tempB[2];
    cubeState['D'][5] = tempB[5];
    cubeState['D'][8] = tempB[8];

    cubeState['B'][2] = tempU[2];
    cubeState['B'][5] = tempU[5];
    cubeState['B'][8] = tempU[8];
}



void RubiksCube::showRubik() {
    std::cout << std::endl;

    auto printColorSquare = [&](const std::string& colorCode) {
        // Map des codes de couleur au code ANSI correspondant pour le fond
        std::map<std::string, std::string> colorMap = {
            {"W", "\033[47m  \033[0m"}, // Blanc
            {"G", "\033[42m  \033[0m"}, // Vert
            {"R", "\033[41m  \033[0m"}, // Rouge
            {"B", "\033[44m  \033[0m"}, // Bleu
            {"O", "\033[48;5;208m  \033[0m"},// Orange (pas de code ANSI direct, utilisation du jaune)
            {"Y", "\033[103m  \033[0m"} // Jaune
        };

        // Afficher le carré de couleur
        std::cout << colorMap[colorCode];
    };

    auto printRow = [&](const std::vector<std::string>& face, int row) {
        for (int i = 0; i < 3; ++i) {
            printColorSquare(face[row * 3 + i]);
            std::cout << ""; // Espace entre les carrés pour une meilleure lisibilité
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

    resolutionPercentage();
}

void RubiksCube::resolutionPercentage() const {
    int totalCorrect = 0;
    const int totalStickers = 54; // 9 stickers * 6 faces

    // Parcourir chaque face pour compter les stickers corrects
    for (auto& face : cubeState) {
        char centerColor = face.second[4][0]; // Le sticker central définit la couleur cible
        int correctCount = std::count_if(face.second.begin(), face.second.end(), [centerColor](const std::string& sticker) {
            return sticker[0] == centerColor;
        });
        totalCorrect += correctCount;
    }

    // Calcul du pourcentage de résolution
    double percentage = (static_cast<double>(totalCorrect) / totalStickers) * 100;

    // Affichage du pourcentage de résolution
    std::cout << "Résolution du Rubik's Cube : " << percentage << "% complété." << std::endl;
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

