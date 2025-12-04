#include "rules.h"
#include <iostream>

Rules::Rules() : RuleStrategy("Jeu de la vie") {}

bool Rules::checkSurvival(int liveNeighbors) const {
        return liveNeighbors == 2 || liveNeighbors == 3;
};

bool Rules::checkBirth(int liveNeighbors) const {
        return liveNeighbors == 3;
};