#pragma once

#include "iView.h"
#include <memory>

class ConsoleView : public IView {
private:

public:
    ConsoleView();
    ~ConsoleView() override;

    void initialize(int width, int height) override;
    void renderGrid(const Grid& grid) override;
    void updateDisplay() override;
    bool handleEvents() override;
};
