#pragma once
#include "cellState.h"

class AliveState : public CellState {
    private:
        AliveState();
    public:
        CellState* handleEvolution(int liveNeighbors, RuleStrategy* rule) override;
        static AliveState* getInstance();
};
