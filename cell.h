#ifndef CELL_H
#define CELL_H

using namespace std;

class Cell {
    private :
        bool alive;
    
    public :
        Cell(int x, int y) : alive(false) {}

        bool isAlive();

        void setAlive(bool state);

};
#endif