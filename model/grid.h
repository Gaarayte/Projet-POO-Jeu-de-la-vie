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
    vector<int> _stateNMin2; // Stockage du N-2, utilisation vecteur 1D
    int width;
    int height;
    vector<vector<shared_ptr<Cell>>> cells;
    vector<vector<shared_ptr<CellState>>> nextStateCells;
    bool _isChanged;
    vector<int> getCurrentGridStateVector() const; //Méthode de convertion grille 2D -> 1D

public:
    Grid(int w, int h);

    void initialize(const InputParser&);
    int calculateLiveNeighbors(int x, int y) const;
    bool evolve(const RuleStrategy& rule);
    bool isStable() const;
    void applyNextState();
    void updateStateNMin2();

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    shared_ptr<Cell> getCell(int x, int y) const;
    const vector<vector<shared_ptr<Cell>>>& getCells() const { return cells; }
};