#pragma once

#include <string>
#include <memory>

using namespace std;

class CellState; //Forward declaration

class RuleStrategy {
public:
    const string name;
    RuleStrategy(const string& n) : name(n) {}
    virtual ~RuleStrategy() = default;
    
    virtual bool checkSurvival(int liveNeighbors) const = 0;
    virtual bool checkBirth(int liveNeighbors) const = 0;

    shared_ptr<CellState> handleEvolution(shared_ptr<CellState> currentState, int liveNeighbors) const; //Handles the evolution of a cell state based on the number of live neighbors
};