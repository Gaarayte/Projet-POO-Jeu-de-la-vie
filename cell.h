#pragma once

class Cell {
    private :
        bool alive;
    
    public :
        Cell(int x, int y) : alive(false) {}

        bool isAlive() const;

        void setAlive(bool state);
};