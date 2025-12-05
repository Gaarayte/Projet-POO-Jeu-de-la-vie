#pragma once

#include "ruleStrategy.h"
#include "../cell.h"

#include <iostream>

using namespace std;

class Rules : public RuleStrategy {
public:
    Rules(const string& n) : RuleStrategy(n) {}
    Rules();
    
    bool checkSurvival(int liveNeighbors) const override; //Survival occurs with 2 or 3 live neighbors

    bool checkBirth(int liveNeighbors) const override; //Birth occurs with exactly 3 live neighbors
};