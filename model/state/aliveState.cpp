#include "aliveState.h"
#include "deadState.h"
#include "../rules/ruleStrategy.h"
#include <iostream>

AliveState::AliveState() : CellState("Alive", true) {}

AliveState* AliveState::getInstance() {
    // La première fois qu'on appelle cette fonction, l'objet est créé.
    // L'objet sera automatiquement détruit à la fin du programme par le C++.
    static AliveState instance; 
    return &instance;
}

CellState* AliveState::handleEvolution(int liveNeighbors, RuleStrategy* rule) {
    if (rule->checkSurvival(liveNeighbors)) {
        return AliveState::getInstance();
    } else {
        return DeadState::getInstance();
    }
}

