#include "consoleView.h"
#include "../model/grid.h"
#include "../model/cell.h"
#include "../model/state/cellState.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

ConsoleView::ConsoleView(const string& inputFilePath) {
    (void)inputFilePath; // Unused parameter
}

ConsoleView::~ConsoleView() {
}

void ConsoleView::initialize(int width, int height) {
    // cout << "Initialisation de la vue Console (" << width << "x" << height << ")" << endl;
    // cout << "Les resultats seront sauvegardes dans : " << outputDirectory << endl;
}

void ConsoleView::renderGrid(const Grid& grid, int iteration) {
    // 1. Display on console
    cout << "\033[2J\033[1;1H"; 
    cout << "Iteration: " << iteration << endl;
    
    int height = grid.getHeight();
    int width = grid.getWidth();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto cell = grid.getCell(x, y);
            if (cell && cell->getState()->isAlive()) {
                cout << "O ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void ConsoleView::updateDisplay() {
    cout << flush;
    this_thread::sleep_for(chrono::milliseconds(200));
}

bool ConsoleView::handleEvents() {
    return true;
}

void ConsoleView::waitForExit() {
    cout << "Appuyez sur entree pour quitter..." << endl;
    cin.ignore();
    cin.get();
}
