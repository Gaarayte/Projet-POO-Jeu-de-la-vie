#include "grid.h"
#include <iostream>
#include <stdexcept>
#include "cell.h"
#include "state/cellState.h" 
#include "ruleStrategy.h" 
#include "state/deadState.h"
#include "../controller/inputParser.h"

std::shared_ptr<CellState> getDeadState() {
    static auto deadState = std::make_shared<DeadState>(); 
    return deadState;
}

Grid::Grid(int w, int h) : 
    width(w), 
    height(h),
    cells(h, std::vector<std::shared_ptr<Cell>>(w)),
    nextStateCells(h, std::vector<std::shared_ptr<CellState>>(w))
{
    if (w <= 0 || h <= 0) {
        throw std::invalid_argument("Grid dimensions must be positive.");
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x] = std::make_shared<Cell>(x, y, getDeadState()); 
            nextStateCells[y][x] = getDeadState();
        }
    }
}

void Grid::initialize(const InputParser& parser) {
    std::cout << "Initialisation de la grille." << std::endl;
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
            
            std::shared_ptr<CellState> currentState = std::shared_ptr<CellState>(cells[y][x]->getState());
            std::shared_ptr<CellState> nextState = rule.handleEvolution(currentState, aliveNeighbors);

            nextStateCells[y][x] = nextState;
        }
    }

    return true; 
}

bool Grid::isStable() const { return false; }

void Grid::applyNextState() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x]->setState(nextStateCells[y][x]);
        }
    }
}

std::shared_ptr<Cell> Grid::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return cells[y][x];
    }
    return nullptr; 
}