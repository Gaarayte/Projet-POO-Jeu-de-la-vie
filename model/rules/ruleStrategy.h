#pragma once

#include <string>

class RuleStrategy {
public:
    const std::string name;
    RuleStrategy(const std::string& n) : name(n) {}
    virtual ~RuleStrategy() = default;
    
    virtual bool checkSurvival(int liveNeighbors) const = 0;
    virtual bool checkBirth(int liveNeighbors) const = 0;
};