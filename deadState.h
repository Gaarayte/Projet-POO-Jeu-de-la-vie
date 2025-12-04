#pragma once

#include "CellState.h"


class DeadState : public CellState {
    private:
        DeadState();

    public:
        CellState* handleEvolution(Cell* currentCell, int liveNeighbors, RuleStrategy* rule) override;
        
        static DeadState* getInstance();

};