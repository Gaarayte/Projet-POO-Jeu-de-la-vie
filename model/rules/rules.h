#pragma once

#include "ruleStrategy.h"
#include "../cell.h"
#include <iostream>

using namespace std;

class Rules : public RuleStrategy {
public:
    Rules(const string& n) : RuleStrategy(n) {}
    Rules();

    bool checkSurvival(int liveNeighbors) const override;

    bool checkBirth(int liveNeighbors) const override;
};