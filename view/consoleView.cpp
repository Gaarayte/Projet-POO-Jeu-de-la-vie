#include "ConsoleView.h"
#include "../model/grid.h"
#include "../model/cell.h"
#include "../model/state/cellState.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

ConsoleView::ConsoleView() {
}

ConsoleView::~ConsoleView() {
}

void ConsoleView::initialize(int width, int height) {
    cout << "Initialisation de la vue Console (" << width << "x" << height << ")" << endl;
}

void ConsoleView::renderGrid(const Grid& grid) {
    // Efface l'écran (codes ANSI)
    cout << "\033[2J\033[1;1H"; 
    
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
    // délai
    this_thread::sleep_for(chrono::milliseconds(200));
}

bool ConsoleView::handleEvents() {
    // Rien à gérer en mode console
    return true;
}
