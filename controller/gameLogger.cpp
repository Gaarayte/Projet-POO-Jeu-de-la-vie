#include <iostream>

#include "gameLogger.h"
#include "grid.h"
#include "cell.h"
#include "cellState.h"

#define ALIVE_CHAR '1'
#define DEAD_CHAR '0'

using namespace std;

GameLogger::GameLogger(const std::string& fileName) {
    _logFile.open(fileName, ios::out);
    if (!_logFile.is_open()) {
        cerr << "Erreur GameLogger: Impossible d'ouvrir le fichier de log " << fileName << endl;
    }
}

GameLogger::~GameLogger() {
    closeLogger();
}

void GameLogger::closeLogger() {
    if (_logFile.is_open()) {
        _logFile.close();
    }
}

bool GameLogger::logState(const Grid* grid, int iteration, int width, int height) {
    if (!_logFile.is_open()) {
        return false;
    }

    _logFile << "--- ITERATION " << iteration << " (" << width << "x" << height << ") ---" << endl;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            shared_ptr<Cell> cell = grid->getCell(x, y); 

            if (cell && cell->getState()->isAlive()) {
                _logFile << ALIVE_CHAR;
            } 
	    else {
                _logFile << DEAD_CHAR;
            }
        }
        _logFile << endl; 
    }

    _logFile << endl; 
    _logFile.flush(); 

    return true;
}