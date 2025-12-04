#include "cell.h"
#pragma once
#include <string>

using namespace std;

class Cell;
class Rules;

class CellState : public Cell {
    protected:
        string name;
        bool alive;

    public:
        CellState(const string& name, bool isAlive);

        virtual ~CellState() = default;
        virtual CellState* handleEvolution(Cell* currentCell, int liveNeighbors, RuleStrategy* rule) = 0;

        bool isAlive() const {};

        string getName() const;
};