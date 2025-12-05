#pragma once
#include "cellState.h"

class AliveState : public CellState {
    public:
        CellState* handleEvolution(int liveNeighbors, RuleStrategy* rule) override;
        static AliveState* getInstance();

        AliveState();
};
