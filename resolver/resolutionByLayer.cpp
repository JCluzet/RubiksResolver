#include "RubiksCube.hpp"

void RubiksCube::resolutionByLayers()
{
    std::cout << "Resolution by layers :" << std::endl;

    std::cout << "1. Make a cross on the yellow layer" << std::endl;

    CrossOnTopLayer();

    std::cout << "2. Put the cross on the white layer" << std::endl;

    PutCrossOnBottomLayer();
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

    // 1 . Trouver un milieu blanc qui est sur la face jaune
    for (int index : {1, 3, 5, 7})
    {
        if (cubeState['U'][index] == "W")
        {
            std::cout << "Arete blanche trouvé"
                      << "a face : U"
                      << "et index : " << index << std::endl;
            std::string color;
            std::string faceSide;
            if (index == 1)
            {
                color = cubeState['B'][7];
                faceSide = "B";
            }
            else if (index == 3)
            {
                color = cubeState['L'][1];
                faceSide = "L";
            }
            else if (index == 5)
            {
                color = cubeState['R'][1];
                faceSide = "R";
            }
            else if (index == 7)
            {
                color = cubeState['F'][1];
                faceSide = "F";
            }
            std::cout << "Couleur sur le coté de cette arrete: " << color << std::endl;
            // turn the face U for the color to be on the face color

            // while()

            switch (index)
            {
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
    }
}

// RubiksCube::RubiksCube() {
//     // Initialisation de l'état du cube
//     solution = "";
//     cubeState = {
//         {'F', std::vector<std::string>(9, "R")}, // GOOD
//         {'R', std::vector<std::string>(9, "G")}, // GOOD
//         {'U', std::vector<std::string>(9, "Y")}, // GOOD
//         {'B', std::vector<std::string>(9, "O")}, // GOOD
//         {'L', std::vector<std::string>(9, "B")}, // GOOD
//         {'D', std::vector<std::string>(9, "W")}  // GOOD
//     };
// }

void RubiksCube::CrossOnTopLayer()
{
    std::cout << "Forming white cross on bottom layer (D):" << std::endl;

    auto hasWhiteEdge = [&]() -> bool
    {
        for (auto &face : {'F', 'R', 'B', 'L', 'D'})
        { // Parcourir toutes les faces sauf U
            for (int index : {1, 3, 5, 7})
            { // Indices possibles pour les arêtes
                if (cubeState[face][index] == "W")
                {
                    std::cout << "Arete trouvee !!!!!!!!!"
                              << "a face :" << face << "et index : " << index << std::endl;
                    std::cout << "cubestate : " << cubeState['B'][1] << std::endl;
                    return true; // Une arête blanche est trouvée
                }
            }
        }
        std::cout << "Plus darete chef ! " << std::endl;
        return false; // Aucune arête blanche n'est trouvée
    };

    while (hasWhiteEdge())
    {
        // Pour chaque arête blanche qui n'est pas sur la face jaune (U)
        for (auto &face : {'F', 'R', 'B', 'L', 'D'})
        { // Exclure la face U car nous cherchons les arêtes non situées sur U
            for (int index : {1, 3, 5, 7})
            { // Indices possibles pour les arêtes
                // Vérifier si l'arête à cet index est blanche
                if (cubeState[face][index] == "W")
                { // Si une arête blanche est trouvée
                    std::cout << "White edge found on face " << face << " at index " << index << std::endl;

                    // Si l'arête est sur la face blanche (D dans notre cas)
                    if (face == 'D')
                    {
                        if (index == 3)
                        {
                            while (cubeState['U'][3] == "W")
                                parseMove("U", true);
                        }
                        else if (index == 5)
                        {
                            while (cubeState['U'][5] == "W")
                                parseMove("U", true);
                        }
                        else if (index == 1)
                        {
                            while (cubeState['U'][7] == "W")
                                parseMove("U", true);
                        }
                        else if (index == 7)
                        {
                            while (cubeState['U'][1] == "W")
                                parseMove("U", true);
                        }

                        // Effectuer un double tour de la face correspondante
                        switch (index)
                        {
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
                    else
                    {
                        switch (face)
                        {
                        case 'F':
                            if (index == 3 || index == 5)
                            {
                                while (cubeState['U'][index] == "W")
                                    parseMove("U", true);
                                if (index == 3)
                                    parseMove("L'", true);
                                else
                                    parseMove("R", true);
                            }
                            else
                            {
                                while (cubeState['U'][7] == "W" && index != 1)
                                    parseMove("U", true);
                                parseMove("F", true);
                                if (index == 1)
                                {
                                    while (cubeState['U'][5] == "W")
                                        parseMove("U", true);
                                    parseMove("R", true);
                                }
                                else
                                {
                                    while (cubeState['U'][3] == "W")
                                        parseMove("U", true);
                                    parseMove("L'", true);
                                }
                            }
                            break;
                        case 'B':
                            if (index == 3 || index == 5)
                            {
                                while (cubeState['U'][index] == "W")
                                    parseMove("U", true);
                                if (index == 3)
                                    parseMove("R'", true);
                                else
                                    parseMove("L", true);
                            }
                            else
                            {
                                while (cubeState['U'][1] == "W" && index != 7)
                                    parseMove("U", true);
                                parseMove("B", true);
                                if (index == 1)
                                {
                                    while (cubeState['U'][5] == "W")
                                        parseMove("U", true);
                                    parseMove("R'", true);
                                }
                                else
                                {
                                    while (cubeState['U'][3] == "W")
                                        parseMove("U", true);
                                    parseMove("L", true);
                                }
                            }
                            break;
                        case 'R':
                            if (index == 3 || index == 5)
                            {
                                if (index == 3)
                                {
                                    while (cubeState['U'][7] == "W")
                                        parseMove("U", true);
                                    parseMove("F'", true);
                                }
                                else
                                {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B", true);
                                }
                            }
                            else
                            {
                                while (cubeState['U'][5] == "W" && index != 1)
                                    parseMove("U", true);
                                parseMove("R", true);
                                if (index == 1)
                                {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B", true);
                                }
                                else
                                {
                                    while (cubeState['U'][7] == "W")
                                        parseMove("U", true);
                                    parseMove("F'", true);
                                }
                            }
                            break;
                        case 'L':
                            if (index == 3 || index == 5)
                            {
                                if (index == 3)
                                {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B'", true);
                                }
                                else
                                {
                                    while (cubeState['U'][7] == "W")
                                        parseMove("U", true);
                                    parseMove("F", true);
                                }
                            }
                            else
                            {
                                while (cubeState['U'][3] == "W" && index != 1)
                                    parseMove("U", true);
                                parseMove("L", true);
                                if (index == 7)
                                {
                                    while (cubeState['U'][1] == "W")
                                        parseMove("U", true);
                                    parseMove("B'", true);
                                }
                                else
                                {
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
// v    oid RubiksCube::CrossOnTopLayer() {
//         std::cout << "Forming white cross on bottom layer (D):" << std::endl;

// 1 . Trouver un milieu blanc qui nest pas sur la face jaune
// 2 . regarder son index et sa face
//          --> si il est sur la face blanc
//                 --> il est sur lindex 1 ou 3 ou 5 ou 7
//                    --> regarder si il ya une face blanche a linverse, si il est en 1 il faut checker la face opposé en 7, si il est en 3 il faut checker la face opposé en 5, en 5 il faut checker la face opposé en 3 et en 7 il faut checker la face opposé en 1
//                        --> si ya une face blanche en face, on tourne la face UP (jaune) pour que le blanc ne soit pas en face de la face blanche
//                        --> maintenant que la face en face est libre
//                           --> si il est en 1 , il faut tourner 2 fois le front
//                            --> si il est en 3 , il faut tourner 2 fois left
//                           --> si il est en 5 , il faut tourner 2 fois right
//                           --> si il est en 7 , il faut tourner 2 fois back
//           --> si il est ni sur la face blanche, ni sur la jaune
//                  --> soit il est sur la face rouge, soit la orange
//                           --> soit il est en index 3
//                               --> checker si au meme index, a la face jaune, ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 2 fois la face bleu (LEFT)
//                           --> soit il est en index 5
//                               --> checker si au meme index, a la face jaune, ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 2 fois la face vert (RIGHT)
//                           --> soit il est en index 1
//                              --> checker si a lindex | 1 SI ORANGE ; 7 SI ROUGE| de la face jaune, si ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index (| 1 SI ORANGE ; 7 SI ROUGE|) sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 1 fois la face sur lequel est le milieu blanc quon veut bouger
//                                      --> checker si a lindex 5 de la face jaune, il ya un milieu blanc, si oui, tourner la face jusqua quil y en ai plus.
//                                      --> tourner 2 fois la face verte droite (RIGHT)
//                           --> soit il est en index 7
//                              --> checker si a lindex | 1 SI ORANGE ; 7 SI ROUGE| de la face jaune, si ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index (| 1 SI ORANGE ; 7 SI ROUGE|) sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 1 fois la face sur lequel est le milieu blanc quon veut bouger
//                                      --> checker si a lindex 3 de la face jaune, il ya un milieu blanc, si oui, tourner la face jusqua quil y en ai plus.
//                                      --> tourner 2 fois la face bleu gauche (LEFT)
//                  --> soit il est sur la bleu, soit la verte
//                           --> soit il est en index 1
//                               --> checker si au meme index, a la face jaune, ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 2 fois la face orange (BACK)
//                           --> soit il est en index 7
//                               --> checker si au meme index, a la face jaune, ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 2 fois la face rouge (FRONT)
//                           --> soit il est en index 3
//                              --> checker si a lindex | 3 SI BLEU ; 5 SI VERT| de la face jaune, si ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index (| 3 SI BLEU ; 5 SI VERT|) sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 1 fois la face sur lequel est le milieu blanc quon veut bouger
//                                      --> checker si a lindex 1 de la face jaune, il ya un milieu blanc, si oui, tourner la face jusqua quil y en ai plus.
//                                      --> tourner 2 fois la face orange (BACK)
//                           --> soit il est en index 5
//                              --> checker si a lindex | 3 SI BLEU ; 5 SI VERT| de la face jaune, si ya un blanc
//                                    OUI --> tourner la face UP (jaune) jusqua quil yai plus de blanc a cet index (| 3 SI BLEU ; 5 SI VERT|) sur la face jaune
//                                    --> maintenant que la face en face est libre, tourner 1 fois la face sur lequel est le milieu blanc quon veut bouger
//                                      --> checker si a lindex 7 de la face jaune, il ya un milieu blanc, si oui, tourner la face jusqua quil y en ai plus.
//                                      --> tourner 2 fois la face rouge (FRONT)

// les fonctions de mouvements sont disponible et ressemble a cela :

// pour appeler un mouvement, il suffit de faite cube.parseMove("F", true);
// ou encore cube.parseMove("F'", true);
// ou encore cube.parseMove("F2", true);
// elle represente
// void RubiksCube::makeMoveF() {
//     // Rotation de la face F elle-même
//     std::vector<std::string> tempF = cubeState['F'];
//     cubeState['F'][0] = tempF[6];
//     cubeState['F'][1] = tempF[3];
//     cubeState['F'][2] = tempF[0];
//     cubeState['F'][3] = tempF[7];
//     cubeState['F'][5] = tempF[1];
//     cubeState['F'][6] = tempF[8];
//     cubeState['F'][7] = tempF[5];
//     cubeState['F'][8] = tempF[2];

//     // Sauvegarde temporaire des états pour les faces adjacentes
//     std::vector<std::string> tempU = cubeState['U'];
//     std::vector<std::string> tempR = cubeState['R'];
//     std::vector<std::string> tempD = cubeState['D'];
//     std::vector<std::string> tempL = cubeState['L'];

//     // Mise à jour des stickers des faces adjacentes
//     // U vers R, R vers D, D vers L, L vers U
//     cubeState['R'][0] = tempU[6];
//     cubeState['R'][3] = tempU[7];
//     cubeState['R'][6] = tempU[8];

//     cubeState['D'][0] = tempR[6];
//     cubeState['D'][1] = tempR[3];
//     cubeState['D'][2] = tempR[0];

//     cubeState['L'][2] = tempD[0];
//     cubeState['L'][5] = tempD[1];
//     cubeState['L'][8] = tempD[2];

//     cubeState['U'][6] = tempL[8];
//     cubeState['U'][7] = tempL[5];
//     cubeState['U'][8] = tempL[2];
// }