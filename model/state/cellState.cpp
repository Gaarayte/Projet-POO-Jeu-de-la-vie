#include "cellState.h"

using namespace std;

CellState::CellState(const string& name, bool isAlive): name(name), alive(isAlive){}

string CellState::getName() const {
    return name;
}