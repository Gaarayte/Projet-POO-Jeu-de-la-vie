#include "cellState.h"

using namespace std;

CellState::CellState(const string& name, bool isAlive): name(name), alive(isAlive){}

bool CellState::isAlive() const {
    return alive;
}

string CellState::getName() const {
    return name;
}