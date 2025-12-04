#pragma once

#include <string>
#include <memory>

#include "grid.h" 

using namespace std;

class InputParser;
class RuleStrategy;

class UnitTests {
public:
    UnitTests() = default;

    bool testEvolution(
        Grid& initialGrid, 
        const RuleStrategy& rule, 
        int steps,
        int expectedAliveCount 
    ) const;


    bool testInputParser(const string& filePath) const;

    bool testNeighborCalculation() const;

    void runAllTests() const;
};
