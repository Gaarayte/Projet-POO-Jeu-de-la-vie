#include <iostream>
#include <stdexcept>
#include <vector> 

#include "grid.h"
#include "cell.h"
#include "state/cellState.h" 
#include "ruleStrategy.h" 
#include "state/deadState.h"
#include "../controller/inputParser.h"

using namespace std;

shared_ptr<CellState> getDeadState() {
    static auto deadState = make_shared<DeadState>(); 
    return deadState;
}

Grid::Grid(int w, int h) : 
    width(w), 
    height(h),
    cells(h, vector<shared_ptr<Cell>>(w)),
    nextStateCells(h, vector<shared_ptr<CellState>>(w)),
    _isChanged(true)
{
    if (w <= 0 || h <= 0) {
        throw invalid_argument("Grid dimensions must be positive.");
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x] = make_shared<Cell>(x, y, getDeadState()); 
            nextStateCells[y][x] = getDeadState();
        }
    }
}

void Grid::initialize(const InputParser&) {
    cout << "Initialisation de la grille." << endl;
}

int Grid::calculateLiveNeighbors(int x, int y) const {
    int aliveCount = 0;

    for (int j = y - 1; j <= y + 1; ++j) {
        for (int i = x - 1; i <= x + 1; ++i) {
            if (i == x && j == y) {
                continue;
            }

            if (i >= 0 && i < width && j >= 0 && j < height) {
                if (cells[j][i]->getState()->isAlive()) {
                    aliveCount++;
                }
            } 
        }
    }

    return aliveCount;
}

bool Grid::evolve(const RuleStrategy& rule) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int aliveNeighbors = calculateLiveNeighbors(x, y);
            
            shared_ptr<CellState> currentState = shared_ptr<CellState>(cells[y][x]->getState());
            shared_ptr<CellState> nextState = rule.handleEvolution(currentState, aliveNeighbors); //completer rulestrategy..

            nextStateCells[y][x] = nextState;
        }
    }

    return true; 
}

void Grid::applyNextState() {
_isChanged = false; // Réinitialise le flag au début de l'application
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            shared_ptr<Cell> cell = cells[y][x];
            shared_ptr<CellState> nextState = nextStateCells[y][x];

            
            if (cell->getState()->isAlive() != nextState->isAlive()) { 
                cell->setState(nextState.get()); 
                _isChanged = true; // Marque la grille comme modifiée
            }
        }
    }
}

vector<int> Grid::getCurrentGridStateVector() const {
    vector<int> state;
    state.reserve(width * height);
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // 1 pour vivant, 0 pour mort
            state.push_back(cells[y][x]->getState()->isAlive() ? 1 : 0);
        }
    }
    return state;
}

void Grid::updateStateNMin2() {
    _stateNMin2 = getCurrentGridStateVector();
}

bool Grid::isStable() const {
    if (!_isChanged){
        return true;
    }
    if (_stateNMin2.empty()) {
        return false; 
    }
    vector<int> stateN = getCurrentGridStateVector();
    if (stateN == _stateNMin2) {
        return true; 
    }
    return false;
}

void Grid::setCell(int x, int y, shared_ptr<Cell> cell) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        cells[y][x] = cell;
    } 
    else {
        cerr << "Avertissement: Tentative de définir une cellule en dehors des limites de la grille (" << x << ", " << y << ")." << endl;
    }
}


shared_ptr<Cell> Grid::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return cells[y][x];
    }
    return nullptr; 
}