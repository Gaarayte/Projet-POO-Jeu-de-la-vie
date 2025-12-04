#pragma once

#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;

class Grid;

class GameLogger {
private:
    ofstream _logFile;
    
public:
    GameLogger(const string& fileName);
    ~GameLogger();


    bool logState(const Grid* grid, int iteration, int width, int height);
    void closeLogger();
};