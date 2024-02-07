// RubiksCube.h

#ifndef RUBIKSCUBE_HPP
#define RUBIKSCUBE_HPP
#include "CubeController.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>

class RubiksCube
{
private:
    CubeController controller;
    std::map<char, std::vector<std::string>> cubeState = {
        {'F', std::vector<std::string>(9, "W")}, // Face avant
        {'R', std::vector<std::string>(9, "G")}, // Face droite
        {'U', std::vector<std::string>(9, "R")}, // Face supérieure
        {'B', std::vector<std::string>(9, "Y")}, // Face arrière
        {'L', std::vector<std::string>(9, "B")}, // Face gauche
        {'D', std::vector<std::string>(9, "O")}  // Face inférieure
    };
    int calculMoveLength(const std::string &move);

public:
    ~RubiksCube() = default; // Destructeur
    RubiksCube();            // Constructeur

    void applyMixSequence(const std::string &sequence);
    void applyMove(const char face, const int moveLength);

    bool parseMove(const std::string &move);
    std::string solveCube();
};

#endif // RUBIKSCUBE_H
