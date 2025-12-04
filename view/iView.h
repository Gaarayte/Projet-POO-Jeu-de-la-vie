#pragma once

#include <memory>

class Grid; 

class IView {
public:
    virtual ~IView() = default; 

    virtual void initialize(int width, int height) = 0; 

    virtual void renderGrid(const Grid& grid) = 0; 

    virtual void updateDisplay() = 0; 

    virtual bool handleEvents() = 0; 
};