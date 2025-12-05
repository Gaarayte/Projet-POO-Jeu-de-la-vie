#include <memory>
#include "cellState.h"
#include "aliveState.h"
#include "deadState.h"

using namespace std;

CellState::CellState(const string& name, bool isAlive): name(name), alive(isAlive){}

string CellState::getName() const {
    return name;//Return the name of the state
}