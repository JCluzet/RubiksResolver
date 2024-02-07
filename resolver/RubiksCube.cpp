#include "RubiksCube.hpp"
// Utiliser std::map pour stocker l'état du cube

bool RubiksCube::applyMixSequence(const std::string& sequence) {
    std::istringstream iss(sequence);
    std::string move;
    while (iss >> move) {
        if(parseMove(move) == false) {
            std::cerr << std::endl;
            // std::cerr << "\033[1;31mInvalid move: " << move << "\033[0m" << std::endl;
            return false;
        }
        else
        {
            std::cout << "\033[1;32m" << move << "\033[0m ";
        }
        // put the display to display 
        std::cout.flush();
        // if this is not the last move we sleep for 1 second
        if(iss.rdbuf()->in_avail() != 0) {
            usleep(1000000);
        }
        // Appliquer le mouvement au cube
    }
    std::cout << std::endl;
    return true;
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
    int moveLength = calculMoveLength(move);
    if (moveLength == -1) {
        // std::cerr << "\033[1;31mInvalid lenght move: " << move << "\033[0m" << std::endl;
        return false;
    }
    if (move[0] == 'R') {
        applyMove('R', moveLength);
    } else if (move[0] == 'L') {
        applyMove('L', moveLength);
    } else if (move[0] == 'U') {
        applyMove('U', moveLength);
    } else if (move[0] == 'D') {
        applyMove('D', moveLength);
    } else if (move[0] == 'F') {
        applyMove('F', moveLength);
    } else if (move[0] == 'B') {
        applyMove('B', moveLength);
    }
    else {
        // put a std::cout in RED
        std::cerr << "\033[1;31m" << move << " << Invalid move !\033[0m" << std::endl;
        return false;
    }
    return true;
}

void writeMovesToFile(const std::vector<std::string>& moves, const std::string& filename) {
    std::ofstream file(filename, std::ios_base::app); // Utilisez `std::ios_base::app` pour ajouter à la fin du fichier
    if (file.is_open()) {
        for (const auto& move : moves) {
            file << move << std::endl;
        }
    }
}

#include <algorithm> // Pour std::rotate

void RubiksCube::makeMoves(const std::vector<std::string>& moves) {
    for (const auto& move : moves) {
        char face = move[0];
    }
}

void RubiksCube::applyMove(const char face, const int moveLength) {
    // Votre implémentation ici
    std::vector<std::string> moves;
    for(int i = 0; i < moveLength; i++) {
        moves.push_back(std::string(1, face));
    }
    makeMoves(moves);
    writeMovesToFile(moves, "../Visualizer/moves.txt");
}





