#include "RubiksCube.hpp"
// Utiliser std::map pour stocker l'état du cube

bool RubiksCube::checkParsing(const std::string& sequence) {
    std::istringstream iss(sequence);
    std::string move;

    while (iss >> move) {
        if(parseMove(move, false) == false) {
            std::cerr << "\033[1;31mInvalid move: " << move << "\033[0m" << std::endl;
            return false;
        }
    }
    return true;
}

bool RubiksCube::applyMixSequence(const std::string& sequence) {
    std::istringstream iss(sequence);
    std::string move;
    showRubik();
    while (iss >> move) {
        if(parseMove(move, true) == false) {
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
        showRubik();
        
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




bool RubiksCube::parseMove(const std::string& move, bool enableMove) {
    int moveLength = calculMoveLength(move);
    if (moveLength == -1) {
        // std::cerr << "\033[1;31mInvalid lenght move: " << move << "\033[0m" << std::endl;
        return false;
    }
    if (move[0] == 'R') {
        if (enableMove)
            applyMove('R', moveLength);
    } else if (move[0] == 'L') {
        if (enableMove)
            applyMove('L', moveLength);
    } else if (move[0] == 'U') {
        if (enableMove)
            applyMove('U', moveLength);
    } else if (move[0] == 'D') {
        if (enableMove)        
            applyMove('D', moveLength);
    } else if (move[0] == 'F') {
        if (enableMove)            
            applyMove('F', moveLength);
    } else if (move[0] == 'B') {
        if (enableMove)    
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



void RubiksCube::applyMove(const char face, const int moveLength) {
    // Votre implémentation ici
    std::vector<std::string> moves;
    for(int i = 0; i < moveLength; i++) {
        moves.push_back(std::string(1, face));
    }
    makeMoves(moves);
    writeMovesToFile(moves, "../Visualizer/moves.txt");
}





