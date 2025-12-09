#pragma once
#include <memory>

#include "state/cellState.h"

using namespace std;

class Cell {
    private :
        bool alive;
        int x;
        int y;
        shared_ptr<CellState> currentState;
    
    public :
        Cell(int x, int y, shared_ptr<CellState> initialState);
        ~Cell() = default;

        // Accessors 
        shared_ptr<CellState> getState() const;
        CellState* evolve(int liveNeighbors, RuleStrategy* rule);

        // Setters
        void setState(shared_ptr<CellState> newState);

   
};