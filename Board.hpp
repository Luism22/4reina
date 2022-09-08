#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Board
{
private:
    vector<vector<char>> matr; 
    int size; 
    int conf;
private:
    bool correctIndex(int i, int j);
    int getConflict(int i, int j);
public:
    Board();
    Board(const Board& Matr);
    void generateQueens();
    void print();
    int getSize();
    int conflictNumber();
    void moveFigure(int& row, int& shift);
    friend bool operator==(const Board& first, const Board& second)
    {
        return first.matr == second.matr;
    }
};
