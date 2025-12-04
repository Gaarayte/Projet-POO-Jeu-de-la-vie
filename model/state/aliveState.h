#pragma once
#include "cellState.h"

class AliveState : public CellState {
    private:
        AliveState();
    public:
        CellState* handleEvolution(Cell* currentCell, int liveNeighbors, RuleStrategy* rule) override;
        static AliveState* getInstance();

};
