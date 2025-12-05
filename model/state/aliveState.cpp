#include "aliveState.h"
#include "deadState.h"
#include "../rules/ruleStrategy.h"
#include <iostream>

AliveState::AliveState() : CellState("Alive", true) {}

AliveState* AliveState::getInstance() {
    //The first time this function is called, the instance is created.
    //The object will be automatically destroyed at the end of the program by C++.
    static AliveState instance; 
    return &instance;
}

CellState* AliveState::handleEvolution(int liveNeighbors, RuleStrategy* rule) {
    if (rule->checkSurvival(liveNeighbors)) { //Remains alive
        return AliveState::getInstance();
    } else { //Dies
        return DeadState::getInstance();
    }
}

