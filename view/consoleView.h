#pragma once

#include "iView.h"
#include <memory>
#include <string>

class ConsoleView : public IView {
private:
    std::string outputDirectory;

public:
    ConsoleView(const std::string& inputFilePath);
    ~ConsoleView() override;

    void initialize(int width, int height) override;
    void renderGrid(const Grid& grid, int iteration) override;
    void updateDisplay() override;
    bool handleEvents() override;
    void waitForExit() override;
};
