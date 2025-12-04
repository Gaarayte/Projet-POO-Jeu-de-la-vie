#include "cell.h"
#include "aliveState.h"
#include "deadState.h"
#include "ruleStrategy.h"

Cell::Cell(int x, int y, shared_ptr<CellState> initialState) : x(x), y(y), currentState(nullptr) {
    if (initialState) {
        currentState = initialState.get();
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
    return currentState->handleEvolution(liveNeighbors, rule);
}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

