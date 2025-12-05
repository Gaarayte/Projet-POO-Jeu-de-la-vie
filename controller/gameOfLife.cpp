#include <iostream>
#include <stdexcept>


#include "gameOfLife.h"
#include "state/aliveState.h" 
#include "state/deadState.h"
#include "rules/rules.h"
#include "inputParser.h"
#include "grid.h"
#include "gameLogger.h"
#include "cell.h"

using namespace std;


bool GameOfLife::initialize(const InputParser& parser) {
    _currentIteration = 0;
    
    _logger = make_unique<GameLogger>("simulation_log.txt");

    int width = parser.getGridWidth();
    int height = parser.getGridHeight();
    _grid = make_unique<Grid>(width, height);

    string ruleName = parser.getRuleName();
    _ruleStrategy = make_unique<Rules>(ruleName); 

    const auto& initialData = parser.getInitialGridData();

    if (initialData.size() != (size_t)height || (height > 0 && initialData[0].size() != (size_t)width)) {
         cerr << "Erreur: Dimensions de la grille lues sont incoherentes." << endl;
         return false;
    }

    shared_ptr<CellState> aliveState = shared_ptr<CellState>(AliveState::getInstance(), [](CellState*){});
    shared_ptr<CellState> deadState = shared_ptr<CellState>(DeadState::getInstance(), [](CellState*){});
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            shared_ptr<Cell> newCell = make_shared<Cell>(x, y, (initialData[y][x] == 1) ? aliveState : deadState);
            _grid->setCell(x, y, newCell);
        }
    }

    if (_view) {
        _view->initialize(width, height);
    }

    return true;
}

GameOfLife::GameOfLife(const string& configFilePath, unique_ptr<IView> view) 
    : _view(move(view)), _currentIteration(0) 
{
    InputParser parser;

    if (!parser.parseEvolution(configFilePath)) {
        throw runtime_error("Erreur: Impossible de parser le fichier de configuration.");
    }

    if (!initialize(parser)) {
        throw runtime_error("Echec de l'initialisation de GameOfLife.");
    }
}


void GameOfLife::runSimulation() {
    if (!_grid || !_ruleStrategy || !_view) {
        cerr << "Erreur: Simulation non initialisee correctement." << endl;
        return;
    }

    cout << "Demarrage de la simulation (" << _grid->getWidth() << "x" << _grid->getHeight() 
              << ", boucle infinie)." << endl;

    _currentIteration = 0;
    while (true) {

        _view->renderGrid(*_grid, _currentIteration);
        _view->updateDisplay(); 
        _logger->logState(_grid.get(), _currentIteration, _grid->getWidth(), _grid->getHeight());

        _grid->evolve(*_ruleStrategy); 

        _grid->applyNextState();

        if (!_view->handleEvents()) {
            cout << "Simulation arretee par l'utilisateur a l'iteration " << _currentIteration + 1 << "." << endl;
            break;
        }
        _currentIteration++;
    }

    _view->renderGrid(*_grid, _currentIteration);
    _view->updateDisplay();
    _logger->closeLogger();
    
    cout << "Simulation terminee." << endl;
    _view->waitForExit();
}