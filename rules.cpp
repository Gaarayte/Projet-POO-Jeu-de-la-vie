#include "Rules.h

Rules::Rules (bool state) : Cell(state) {}

bool Rules::applyRules(const Cell& cell, int aliveNeighbors) {
    if (cell.getState()) {
        return (aliveNeighbors == 2 || aliveNeighbors == 3);
    } else {
        return (aliveNeighbors == 3);
    }
};
