#pragma once
#include "CellState.h"

class AliveState : public CellState {
    private:
        AliveState();
    public:
        CellState* handleEvolution(Cell* currentCell, int liveNeighbors, RuleStrategy* rule) override;
        static AliveState* getInstance();

};
