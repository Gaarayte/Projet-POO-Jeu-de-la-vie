#pragma once

#include "ruleStrategy.h"
#include "../cell.h"
#include <iostream>

class Rules : public RuleStrategy {
public:
    Rules() : RuleStrategy("Jeu de la vie") {}

    bool checkSurvival(int liveNeighbors) const override {
        return liveNeighbors == 2 || liveNeighbors == 3;
    }

    bool checkBirth(int liveNeighbors) const override {
        return liveNeighbors == 3;
    }
};