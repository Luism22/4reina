#include "Board.hpp"
#include <vector>

using namespace std;

bool Board::correctIndex(int i, int j)
{
    return (i >= 0 && i < size && j >= 0 && j < size);
}


Board::Board()
{
    size = 8;
    matr = vector<vector<char>>(size);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            this->matr[i].push_back('0');
        }
    }

    conf = this->conflictNumber();
}


Board::Board(const Board& other)
{
    this->size = other.size;
    this->matr = vector<vector<char>>(size);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            this->matr[i].push_back(other.matr[i][j]);
        }
    }
    conf = this->conflictNumber();
}


void Board::generateQueens()
{
    srand(time(NULL));
    for (size_t i = 0; i < 4; i++)
    {
        size_t j = rand() % size;
        matr[i][j] = '*';
    }
}


void Board::print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(3) << matr[i][j];
        }
        cout << endl;
    }
}


int Board::getSize()
{
    return this->size;
}


int Board::conflictNumber()
{
    int conflicts = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matr[i][j] == '*')
            {
                conflicts += getConflict(i, j);
            }
        }
    }

    return conflicts;
}


int Board::getConflict(int i, int j)
{
    int confNum = 0;

    for (int row = 0; row < i; row++) // horizontal before
    {
        int count = 0;
        if (matr[row][j] == '*')
        {
            ++count;
        }
        if (count)
        {
            ++confNum;
            break;
        }
    }

    for (int row = i + 1; row < size; row++) // horizontal after
    {
        int count = 0;
        if (matr[row][j] == '*')
        {
            ++count;
        }
        if (count)
        {
            ++confNum;
            break;
        }
    }

    for (int col = 0; col < j; col++) // vertical before
    {
        int count = 0;
        if (matr[i][col] == '*')
        {
            ++count;
        }
        if (count)
        {
            ++confNum;
            break;
        }
    }

    for (int col = j + 1; col < size; col++) // vertical after
    {
        int count = 0;
        if (matr[i][col] == '*')
        {
            ++count;
        }
        if (count)
        {
            ++confNum;
            break;
        }
    }

    int row = i - 1, col = j - 1;
    while (correctIndex(row, col)) // up-left
    {
        if (matr[row][col] == '*')
        {
            ++confNum;
            break;
        }
        --row, --col;
    } 
  
    row = i + 1, col = j + 1;
    while (correctIndex(row, col)) { 
        if (matr[row][col] == '*')
        {
            ++confNum;
            break;
        }
        ++row, ++col;
    } 

    row = i - 1, col = j + 1;
    while (correctIndex(row, col)) 
    {
        if (matr[row][col] == '*')
        {
            ++confNum;
            break;
        }
        --row, ++col;
    } 

    row = i + 1, col = j - 1;
    while (correctIndex(row, col)) // left-down
    {
        if (matr[row][col] == '*')
        {
            ++confNum;
            break;
        }
        ++row, --col;
    } 

    return confNum;
}


void Board::moveFigure(int& row, int& shift)
{
    for (size_t j = 0; j < size; j++)
    {
        if (matr[row][j] == '*')
        {
            matr[row][j] = '0';
            int col = j + shift;
            if (col >= size)
            {
                col -= size;
            }
            matr[row][col] = '*';
            break;
        }
    }  
    conf = this->conflictNumber();
}
