#include "aliveState.h"
#include "rules.h"
#include <iostream>

AliveState::AliveState() : CellState("Alive", true) {}

AliveState* AliveState::getInstance() {
    // La première fois qu'on appelle cette fonction, l'objet est créé.
    // L'objet sera automatiquement détruit à la fin du programme par le C++.
    static AliveState instance; 
    return &instance;
}

CellState* AliveState::handleEvolution(Cell* currentCell, int liveNeighbors, Rules* rule) {
    return rule->getNextState(this, liveNeighbors);
}

