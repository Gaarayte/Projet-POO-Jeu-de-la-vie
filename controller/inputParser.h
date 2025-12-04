#pragma once
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Grid;
class RuleStrategy;

class InputParser {
private:
    string _ruleName;
    int _maxIterations;
    int _gridWidth;
    int _gridHeight;
    vector<vector<int>> _initialGridData; 
    
    bool readFile(const string& fileName); 

public:
    InputParser();

    bool parseEvolution(const string& fileName);

    int getGridWidth() const { return _gridWidth; }
    int getGridHeight() const { return _gridHeight; }
    int getMaxIterations() const { return _maxIterations; }
    string getRuleName() const { return _ruleName; }
    
    const vector<vector<int>>& getInitialGridData() const { return _initialGridData; }
};
