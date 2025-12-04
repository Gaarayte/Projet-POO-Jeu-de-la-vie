#include "cell.h"
#include "aliveState.h"
#include "deadState.h"
#include "ruleStrategy.h"

Cell::Cell(int x, int y, int initialState) : x(x), y(y), currentState(nullptr) {
    if (initialState == 1) {
        currentState = AliveState::getInstance();
    } else {
        currentState = DeadState::getInstance();
    }
}

void Cell::setState(CellState* newState) {
    if(newState) {
        currentState = newState;
    }
}

CellState* Cell::getState() const {
    return currentState;
}

CellState* Cell::evolve(int liveNeighbors, RuleStrategy* rule) {
    return currentState->handleEvolution(this, liveNeighbors, rule);
}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

