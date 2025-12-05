#include <iostream>

#include "gameLogger.h"
#include "grid.h"
#include "cell.h"
#include "cellState.h"

#define ALIVE_CHAR '1'
#define DEAD_CHAR '0'

using namespace std;

GameLogger::GameLogger(const string& fileName) {
    _logFile.open(fileName, ios::out);
    // Si le fichier log ne peut pas être ouvert, un message d'erreur est affiché
    if (!_logFile.is_open()) {
        cerr << "Erreur GameLogger: Impossible d'ouvrir le fichier de log " << fileName << endl;
    }
}

// Destructeur : fermeture le fichier de log lors de la destruction de l'objet
GameLogger::~GameLogger() {
    closeLogger();
}

// Ferme le fichier de log si ouvert
void GameLogger::closeLogger() {
    if (_logFile.is_open()) {
        _logFile.close();
    }
}

// Enregistre l'état actuel de la grille dans le fichier de log
bool GameLogger::logState(const Grid* grid, int iteration, int width, int height) {
    if (!_logFile.is_open()) {
        return false;
    }

    // En-tête de l'itération
    _logFile << "--- ITERATION " << iteration << " (" << width << "x" << height << ") ---" << endl;

    // Parcours la grille pour enregistrer l'état de chaque cellule
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
        _logFile << endl; // Nouvelle ligne à chaque rangée
    }

    _logFile << endl; 
    _logFile.flush(); // Force l écriture dans le fichier

    return true;
}