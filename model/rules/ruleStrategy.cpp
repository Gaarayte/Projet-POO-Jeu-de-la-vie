#include "ruleStrategy.h"
#include "../state/cellState.h"
#include "deadState.h"
#include "aliveState.h"

using namespace std;

shared_ptr<CellState> RuleStrategy::handleEvolution(shared_ptr<CellState> currentState, int liveNeighbors) const{
    // If the cell is ALIVE
    if (currentState->isAlive()) {
        if (checkSurvival(liveNeighbors)) {
            return currentState; // Survives
        } 
        else {
            return make_shared<DeadState>(); // Dies (underpopulation or overpopulation)
        }
    } 
    // If the cell is DEAD
    else {
        if (checkBirth(liveNeighbors)) {
            return make_shared<AliveState>(); // Birth (reproduction)
        } 
        else {
            return currentState; // Remains dead
        }
    }
}

