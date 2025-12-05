#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <memory>

#include "unitTests.h"
#include "inputParser.h"
#include "ruleStrategy.h"
#include "grid.h"
#include "cell.h"
#include "aliveState.h"
#include "deadState.h"

using namespace std;

class TestRule : public RuleStrategy {
public:
    TestRule(const string& n) : RuleStrategy(n) {}
    bool checkSurvival(int liveNeighbors) const override {
        return liveNeighbors == 2 || liveNeighbors == 3;
    }
    bool checkBirth(int liveNeighbors) const override {
        return liveNeighbors == 3;
    }
};


bool UnitTests::testEvolution(
    Grid& initialGrid, 
    const RuleStrategy& rule, 
    int steps, 
    int expectedAliveCount
) const {
    cout << " > Execution du test d'evolution (" << rule.name << ")..." << endl;
    
    Grid testGrid = initialGrid; 

    for (int i = 0; i < steps; ++i) {
        testGrid.evolve(rule);
        testGrid.applyNextState();
    }

    int actualAliveCount = 0;
    for (int y = 0; y < testGrid.getHeight(); ++y) {
        for (int x = 0; x < testGrid.getWidth(); ++x) {
            if (testGrid.getCell(x, y)->getState()->isAlive()) {
                actualAliveCount++;
            }
        }
    }

    if (actualAliveCount != expectedAliveCount) {
        cerr << "   Echec : Nombre de vivantes apres " << steps << " etapes. Attendu: " << expectedAliveCount << ", Obtenu: " << actualAliveCount << endl;
        return false;
    }

    cout << " > Test d'evolution REUSSI." << endl;
    return true;
}

bool UnitTests::testInputParser(const string& filePath) const {
    cout << " > Execution du test de parsing d'entree (" << filePath << ")..." << endl;
    InputParser parser;
    
    if (parser.parseEvolution("non_existent_file.txt")) {
        cerr << "   Echec : Le parser a reussi a ouvrir un fichier inexistant." << endl;
        return false;
    }

    if (!parser.parseEvolution(filePath)) {
        cerr << "   Echec : Le parsing du fichier valide a echoue." << endl;
        return false;
    }
    
    if (parser.getGridWidth() <= 0 || parser.getGridHeight() <= 0) {
        cerr << "   Echec : Dimensions de grille invalides lues." << endl;
        return false;
    }
    if (parser.getInitialGridData().empty()) {
        cerr << "   Echec : Donnees de grille initiales non lues." << endl;
        return false;
    }

    cout << " > Test de parsing REUSSI." << endl;
    return true;
}

bool UnitTests::testNeighborCalculation() const {
    cout << " > Execution du test de calcul des voisins..." << endl;
    
    Grid grid(5, 5);
    shared_ptr<CellState> aliveState = shared_ptr<CellState>(AliveState::getInstance(), [](CellState*){});

    grid.getCell(2, 2)->setState(aliveState); 
    grid.getCell(1, 2)->setState(aliveState); 
    grid.getCell(3, 2)->setState(aliveState); 
    grid.getCell(2, 1)->setState(aliveState); 
    grid.getCell(2, 3)->setState(aliveState); 
    int neighbors_center = grid.calculateLiveNeighbors(2, 2);
    if (neighbors_center != 4) {
        cerr << "   Echec : Centre (2,2). Attendu: 4, Obtenu: " << neighbors_center << endl;
        return false;
    }

    int neighbors_corner = grid.calculateLiveNeighbors(0, 0);
    if (neighbors_corner != 0) { 
        cerr << "   Echec : Coin (0,0). Attendu: 0, Obtenu: " << neighbors_corner << endl;
        return false;
    }
    
    int neighbors_edge = grid.calculateLiveNeighbors(0, 2);
    if (neighbors_edge != 1) { 
        cerr << "   Echec : Bord (0,2). Attendu: 1, Obtenu: " << neighbors_edge << endl;
        return false;
    }

    cout << " > Test de calcul des voisins REUSSI." << endl;
    return true;
}

void UnitTests::runAllTests() const {
    cout << "\n========================================" << endl;
    cout << " DEMARRAGE DES TESTS UNITAIRES" << endl;
    cout << "========================================" << endl;
    
    bool allPassed = true;

    if (!testNeighborCalculation()) {
        allPassed = false;
    }
    
    if (!testInputParser("test_config.txt")) { 
        allPassed = false;
    }
    
    Grid grid_block(4, 4);
    shared_ptr<CellState> aliveStateBlock = shared_ptr<CellState>(AliveState::getInstance(), [](CellState*){});
    grid_block.getCell(1, 1)->setState(aliveStateBlock);
    grid_block.getCell(1, 2)->setState(aliveStateBlock);
    grid_block.getCell(2, 1)->setState(aliveStateBlock);
    grid_block.getCell(2, 2)->setState(aliveStateBlock);
    
    TestRule conwayRule("Conway");

   cout << "\n========================================" << endl;
    if (allPassed) {
        cout << " TOUS LES TESTS UNITAIRES ONT REUSSI !" << endl;
    } 
    else {
        cout << " DES TESTS UNITAIRES ONT ECHOUE !" << endl;
    }
    cout << "========================================" << endl;
}