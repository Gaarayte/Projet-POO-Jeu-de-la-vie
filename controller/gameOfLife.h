#pragma once

#include <string>
#include <memory>

#include "ruleStrategy.h"
#include "grid.h"
#include "gameLogger.h"
#include "inputParser.h"
#include "../view/iView.h"

using namespace std;

class GameOfLife {
private:
    unique_ptr<Grid> _grid;
    unique_ptr<RuleStrategy> _ruleStrategy;
    unique_ptr<GameLogger> _logger;
    unique_ptr<IView> _view; 
    
    int _currentIteration;
    int _delayMs = 0;

    bool initialize(const InputParser& parser);

public:
    GameOfLife(const string& configFilePath, unique_ptr<IView> view);
    
    void setDelay(int ms) { _delayMs = ms; }
    void runSimulation();
};