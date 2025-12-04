#pragma once

#include "CellState.h"

class Cell {
    private :
        bool alive;
        int x;
        int y;
        CellState* currentState;
    
    public :
        Cell(int x, int y, int initialState) ;
        ~Cell() = default;

        // Method
        void invertState();

        // Accessors 
        CellState* getState() const;
        CellState* evolve(int liveNeighbors, RuleStrategy* rule);
        int getX() const;
        int getY() const;

        // Setters
        void setState(CellState* newState);

   
};