#pragma once

#include <memory>
#include <vector>

#include "cell.h"

class CellState;
class Rules;

class Grid
{
private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Cell>>> cells;
    std::vector<std::vector<std::shared_ptr<CellState>>> nextStateCells;

public:
    Grid(int w, int h);

    void initialize(const InputParser& parser);
    int calculateLiveNeighbors(int x, int y) const;
    bool evolve(const RuleStrategy& rule);
    bool isStable() const { return false; }
    void applyNextState();

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::shared_ptr<Cell> getCell(int x, int y) const;
    const std::vector<std::vector<std::shared_ptr<Cell>>>& getCells() const { return cells; }
};