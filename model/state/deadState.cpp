#include "deadState.h"
#include "rules.h"
#include <iostream>

DeadState::DeadState(): CellState("Dead", false) {}

DeadState* DeadState::getInstance() {
    static DeadState instance; 
    return &instance;
}

CellState* DeadState::handleEvolution(Cell* currentCell, int liveNeighbors, Rules* rule) {
    return rule->getNextState(this, liveNeighbors);
}