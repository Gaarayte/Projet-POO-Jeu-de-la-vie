#include "cell.h"
#include <iostream>

Cell::Cell(int x, int y) : alive(false) {}

bool Cell::isAlive() const {
    return alive;
}

void Cell::setAlive(bool state) {
    alive = state;
}
