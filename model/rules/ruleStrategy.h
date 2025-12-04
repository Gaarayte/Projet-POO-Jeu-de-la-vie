#pragma once

#include <string>
#include <memory>

using namespace std;

class CellState;

class RuleStrategy {
public:
    const string name;
    RuleStrategy(const string& n) : name(n) {}
    virtual ~RuleStrategy() = default;
    
    virtual bool checkSurvival(int liveNeighbors) const = 0;
    virtual bool checkBirth(int liveNeighbors) const = 0;

    shared_ptr<CellState> handleEvolution(shared_ptr<CellState> currentState, int liveNeighbors) const;
};