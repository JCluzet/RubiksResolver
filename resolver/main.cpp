#include "RubiksCube.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <mix_sequence>" << std::endl;
        return 1;
    }
    std::string mixSequence = argv[1];

    RubiksCube cube;
    std::cout << "Checking parsing... ";
    if (cube.checkParsing(mixSequence) == false) {
        std::cerr << "Error while parsing mix sequence" << std::endl;
        return 1;
    }
    std::cout << "\033[1;32mOK\033[0m" << std::endl << std::endl;
    std::cout << "====  START MIXING CUBE  ====" << std::endl;
    if (cube.applyMixSequence(mixSequence) == false) {
        std::cerr << "Error while applying mix sequence" << std::endl;

        return 1;
    }
    std::cout << "==== END OF MIXING CUBE ====" << std::endl << std::endl;
    std::cout << "==== STARTING SOLVING ====" << std::endl;
    std::string solution = cube.solveCube();
    std::cout << "Solution sequence: " << solution << std::endl;
    std::cout << "==== END OF SOLVING ====" << std::endl;

    return 0;
}
