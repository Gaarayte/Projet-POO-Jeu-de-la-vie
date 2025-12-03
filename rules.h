#pragma once

#include "cell.h"

class Rules : public Cell {
    public:
        Rules(bool state = false);
        bool applyRules(const Cell& cell, int aliveNeighbors);

        void setState(bool state) {};
        void setNextState(bool state) {
    };
};