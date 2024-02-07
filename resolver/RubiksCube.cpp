#include "RubiksCube.hpp"

// Utiliser std::map pour stocker l'état du cube


void RubiksCube::applyMixSequence(const std::string& sequence) {
    std::istringstream iss(sequence);
    std::string move;
    while (iss >> move) {
        std::cout << "Applying move: " << move << std::endl;

        // Appliquer le mouvement au cube
    }
}

std::string RubiksCube::solveCube() {
    std::string solution = "R U R' U'";
    std::cout << "Solution: " << solution << std::endl;
    return solution;
}

int RubiksCube::calculMoveLength(const std::string& move) {
    if(move.length() > 2) {
        return -1;
    }
    if(move.length() == 1) {
        return 1;
    }
    if (move[1] == '\'') {
        return 3;
    }
    else if (move[1] == '2') {
        return 2;
    }
    else {
        return -1;
    }
}

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

    // Connexion du signal de mouvement du contrôleur à la méthode parseMove
    // controller.moveSignal.connect(boost::bind(&RubiksCube::parseMove, this, _1));


}


bool RubiksCube::parseMove(const std::string& move) {
    std::cout << "Applying move: " << move << std::endl;
    int moveLength = calculMoveLength(move);
    if (moveLength == -1) {
        std::cerr << "Invalid move: " << move << std::endl;
        return false;
    }
    if (move == "R") {
        applyMove('R', moveLength);
    } else if (move == "L") {
        applyMove('L', moveLength);
    } else if (move == "U") {
        applyMove('U', moveLength);
    } else if (move == "D") {
        applyMove('D', moveLength);
    } else if (move == "F") {
        applyMove('F', moveLength);
    } else if (move == "B") {
        applyMove('B', moveLength);
    }
    else {
        std::cerr << "Invalid move: " << move << std::endl;
        return false;
    }
    return true;
}

void RubiksCube::applyMove(const char face, const int moveLength) {
    for(int i = 0; i < moveLength; i++)
    {
        controller.sendMove(face);
    }
    
}





