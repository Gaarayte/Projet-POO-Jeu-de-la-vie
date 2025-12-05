#include "../controller/inputParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

InputParser::InputParser() : _ruleName("Conway"), _gridWidth(0), _gridHeight(0) {}

// Reads the configuration file to extract grid dimensions and initial grid
bool InputParser::readFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier " << fileName << endl;
        return false;
    }

    string line;
    
    // Read the parameter line (Width Height)
    if (getline(file, line)) {
        stringstream ss(line);
        
        // The first line is expected to contain: Width Height
        if (ss >> _gridWidth >> _gridHeight) {
            if (_gridWidth <= 0 || _gridHeight <= 0) {
                cerr << "Erreur: Parametres de grille invalides." << endl;
                return false;
            }
        } 
        else {
            cerr << "Erreur: Format de la ligne de parametres invalide." << endl;
            return false;
        }
    } 
    else {
        cerr << "Erreur: Fichier vide ou illisible (" << fileName << ")." << endl;
        return false;
    }

    _initialGridData.clear();
    
    // Read the grid data
    for (int y = 0; y < _gridHeight; ++y) {
        if (!getline(file, line)) {
            cerr << "Erreur: Nombre de lignes de grille insuffisant (attendu " << _gridHeight << ")." << endl;
            return false;
        }
        
        stringstream ss_grid(line);
        vector<int> row;
        int state;
        
        // Parse each cell state in the row
        for (int x = 0; x < _gridWidth; ++x) {
            if (ss_grid >> state) {
                row.push_back(state);
            } 
            else {
                cerr << "Erreur: Nombre de colonnes insuffisant (attendu " << _gridWidth << " à la ligne " << y + 1 << ")." << endl;
                return false;
            }
        }
        _initialGridData.push_back(row);
    }

    return true;
}

bool InputParser::parseEvolution(const string& fileName) {
    return readFile(fileName);
}