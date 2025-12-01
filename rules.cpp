#include "rules.h"


Rules::Rules (bool state) : Cell() {}

bool Rules::applyRules(const Cell& cell, int aliveNeighbors) {
    if (cell.isAlive()) {
        return (aliveNeighbors == 2 || aliveNeighbors == 3);
    } else {
        return (aliveNeighbors == 3);
    }
};
