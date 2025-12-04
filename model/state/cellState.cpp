#include <memory>
#include "cellState.h"
#include "aliveState.h"
#include "deadState.h"

using namespace std;

CellState::CellState(const string& name, bool isAlive): name(name), alive(isAlive){}

string CellState::getName() const {
    return name;
}

shared_ptr<CellState> getAliveState() {
    static auto aliveState = make_shared<AliveState>(); 
    return aliveState;
}

shared_ptr<CellState> getDeadState() {
    static auto deadState = make_shared<DeadState>(); 
    return deadState;
}