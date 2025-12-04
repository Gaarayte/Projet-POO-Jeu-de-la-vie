#pragma once
#include <string>

using namespace std;

class Cell;
class RuleStrategy;

class CellState {
    protected:
        string name;
        bool alive;

    public:
        CellState(const string& name, bool isAlive);

        virtual ~CellState() = default;
        virtual CellState* handleEvolution(Cell* currentCell, int liveNeighbors, RuleStrategy* rule) = 0;

        bool isAlive() const { return alive; }

        string getName() const;
};