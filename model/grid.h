#pragma once

#include <memory>
#include <vector>

#include "cell.h"
#include "../controller/inputParser.h"

using namespace std;

class CellState; //Forward declaration
class Rules; //Forward declaration

class Grid
{
private:
    int width;
    int height;
    vector<vector<shared_ptr<Cell>>> cells;
    vector<vector<shared_ptr<CellState>>> nextStateCells;
    vector<int> getCurrentGridStateVector() const;

public:
    Grid(int w, int h);

    void initialize(const InputParser&);
    int calculateLiveNeighbors(int x, int y) const;
    bool evolve(const RuleStrategy& rule);
    bool isStable() const;
    void applyNextState();
    void setCell(int x, int y, shared_ptr<Cell> cell);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    shared_ptr<Cell> getCell(int x, int y) const;
    const vector<vector<shared_ptr<Cell>>>& getCells() const { return cells; }};