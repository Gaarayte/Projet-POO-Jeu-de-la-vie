#pragma once

#include "iView.h"
#include <SFML/Graphics.hpp>

class SFMLView : public IView {
private:
    sf::RenderWindow window;
    int cellSize;

public:
    SFMLView();
    ~SFMLView() override;

    void initialize(int width, int height) override;
    void renderGrid(const Grid& grid, int iteration) override;
    void updateDisplay() override;
    bool handleEvents() override;
    void waitForExit() override;
};