#pragma once

#include <string>
#include <memory>

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
        virtual CellState* handleEvolution(int liveNeighbors, RuleStrategy* rule) = 0;

        bool isAlive() const { return alive; }
        shared_ptr<CellState> getAliveState(); // Pour les tests unitaires
        shared_ptr<CellState> getDeadState();

        string getName() const;
};