#pragma once

#include "ruleStrategy.h"
#include "../cell.h"
#include <iostream>

class Rules : public RuleStrategy {
public:
    Rules();

    bool checkSurvival(int liveNeighbors) const override;

    bool checkBirth(int liveNeighbors) const override;
};