#include "SFMLView.h"
#include "../model/grid.h"
#include "../model/cell.h"
#include "../model/state/cellState.h"

SFMLView::SFMLView() : cellSize(10) {}

SFMLView::~SFMLView() {
    if (window.isOpen()) {
        window.close();
    }
}

void SFMLView::initialize(int width, int height) {
    window.create(sf::VideoMode(width * cellSize, height * cellSize), "Game of Life");
    window.setFramerateLimit(60); 
}

void SFMLView::renderGrid(const Grid& grid, int iteration) {
    window.clear(sf::Color::Black);
    
    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    
    int height = grid.getHeight();
    int width = grid.getWidth();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto cell = grid.getCell(x, y);
            if (cell && cell->getState()->isAlive()) {
                cellShape.setPosition(x * cellSize, y * cellSize);
                cellShape.setFillColor(sf::Color::White);
                window.draw(cellShape);
            }
        }
    }
    
    window.setTitle("Game of Life - Iteration: " + std::to_string(iteration));
}

void SFMLView::updateDisplay() {
    window.display();
}

bool SFMLView::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        }
    }
    return window.isOpen();
}

void SFMLView::waitForExit() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        sf::sleep(sf::milliseconds(100));
    }
}
