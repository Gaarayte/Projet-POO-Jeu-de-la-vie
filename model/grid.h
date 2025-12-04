#pragma once

#include <memory>
#include <vector>

#include "cell.h"
#include "../controller/inputParser.h"

using namespace std;

class CellState;
class Rules;

class Grid
{
private:
    int width;
    int height;
    vector<vector<shared_ptr<Cell>>> cells;
    vector<vector<shared_ptr<CellState>>> nextStateCells;
    bool _isChanged;

public:
    Grid(int w, int h);

    void initialize(const InputParser&);
    int calculateLiveNeighbors(int x, int y) const;
    bool evolve(const RuleStrategy& rule);
    bool isStable() const { return !_isChanged; }
    void applyNextState();

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    shared_ptr<Cell> getCell(int x, int y) const;
    const vector<vector<shared_ptr<Cell>>>& getCells() const { return cells; }
};