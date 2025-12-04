#pragma once
#include "cellState.h"


class DeadState : public CellState {
    private:
        DeadState();

    public:
        CellState* handleEvolution(int liveNeighbors, RuleStrategy* rule) override;
        
        static DeadState* getInstance();

};