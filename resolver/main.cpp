#include "RubiksCube.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <mix_sequence>" << std::endl;
        return 1;
    }
    std::string mixSequence = argv[1];

    RubiksCube cube;
    cube.applyMixSequence(mixSequence);
    std::string solution = cube.solveCube();
    std::cout << "Solution sequence: " << solution << std::endl;

    return 0;
}
