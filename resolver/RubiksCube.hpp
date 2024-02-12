#ifndef RUBIKSCUBE_HPP
#define RUBIKSCUBE_HPP

#include <unistd.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

class RubiksCube {
private:
    std::map<char, std::vector<std::string>> cubeState;
    std::string solution;


bool generateAndTestMoves(std::vector<std::string>& sequence, const std::vector<std::string>& moves, int currentDepth, int maxDepth);
void findCrossWhiteSolution();
std::vector<std::pair<char, int>> findWhiteEdges();
void makeMove(const std::string& move);
void PutCrossOnBottomLayer();
void PutWhiteCorners();
bool checkCornerDown(int index);
char* whichColor(char face, int index, int cornerPosition);
int combination(char face, int index);
void getOutOfBottomLayer(char face, int index);
void doCornerAlgorithm(int whereToGo);
void putCornerInPosition(int whereToGo, int whereWeAre);
void doUpAlgo(int whereToGo);
void doFacingYouAlgo(int whereToGo);
void doFacingRightAlgo(int whereToGo);
char whichFace(int whereToGo);
void sendUpAlgo(char face);
void sendFacingYouALgo(char face);
void sendFacingRightAlgo(char face);



    void resolutionByLayers();
    void CrossOnTopLayer();
    int calculMoveLength(const std::string& move);
    void makeMoves(const std::vector<std::string>& moves);
    void resolutionPercentage() const;
    void makeMoveF();
    void makeMoveB();
    void makeMoveU();
    void makeMoveD();
    void makeMoveL();
    void makeMoveR();
    void showRubik();


public:
    RubiksCube(); // Constructeur
    ~RubiksCube() = default; // Destructeur

bool isCrossWhiteFormed();
    bool checkParsing(const std::string& sequence);
    bool applyMixSequence(const std::string& sequence);
    void applyMove(const char face, const int moveLength);
    bool parseMove(const std::string& move, bool applyMove);
    std::string solveCube();
};

#endif // RUBIKSCUBE_HPP
