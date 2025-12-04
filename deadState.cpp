#include "deadState.h"
#include "ruleStrategy.h"
#include <iostream>

DeadState::DeadState(): CellState("Dead", false) {}

DeadState* DeadState::getInstance() {
    // La première fois qu'on appelle cette fonction, l'objet est créé.
    // L'objet sera automatiquement détruit à la fin du programme par le C++.
    static DeadState instance; 
    return &instance;
}

CellState* DeadState::handleEvolution(Cell* currentCell, int liveNeighbors, RuleStrategy* rule) {
    return rule->getNextState(this, liveNeighbors);
}