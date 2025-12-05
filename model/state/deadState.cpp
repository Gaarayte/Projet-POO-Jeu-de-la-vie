#include "deadState.h"
#include "aliveState.h"
#include "../rules/ruleStrategy.h"
#include <iostream>

DeadState::DeadState(): CellState("Dead", false) {}

DeadState* DeadState::getInstance() {
    //The first time this function is called, the instance is created.
    //The object will be automatically destroyed at the end of the program by C++.
    static DeadState instance; 
    return &instance;
}

CellState* DeadState::handleEvolution(int liveNeighbors, RuleStrategy* rule) {
    if (rule->checkBirth(liveNeighbors)) {//Becomes alive
        return AliveState::getInstance();
    } else {//Remains dead
        return DeadState::getInstance();
    }
}