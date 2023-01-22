#include "board.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

void Board::printBoard()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "|";
        for (int j = 0; j < n; j++)
        {
            if (getCell(i, j) == 0)
            {
                std::cout << " .  ";
            }
            else
            {
                std::cout << " " << getCell(i, j) << "  ";
            }
        }

        std::cout << "|" << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;
}

bool Board::isFull()
{
    return false;
}

void Board::resetBoard()
{
}

int Board::getCell(int x, int y)
{
    return grid[x][y];
}

void Board::setCell(int x, int y, int value)
{
    grid[x][y] = value;
}

bool Board::getImmutability(int x, int y)
{
    return immutable[x][y];
}

void Board::setImmutability(int x, int y, bool newImmutableValue)
{
    immutable[x][y] = newImmutableValue;
}

int Board::getSize()
{
    return n;
}

bool Board::generateSudoku(int preFilled)
{
    int size = getSize();
    int *perm = getPermutation(size);

    // Fill diagonal with generated Permutation
    for (int i = 0; i < size; i++)
    {
        setCell(i, i, perm[i]);
    }

    // Filled diagonal allows us to generate a full sudoku with a solving algorithm
    bool isSolved = solveSudoku(0, 0);

    if (!isSolved)
    {
        return false;
    }
    return true;
}

bool Board::solveSudoku(int x, int y)
{
    // Check if we are at the bottom of the board
    if (x == getSize())
    {
        return true;
    }

    if (getCell(x, y) != 0)
    {
        if (y == getSize() - 1) // If at the right side of the board, go down one line
        {
            if (solveSudoku(x + 1, 0))
                return true;
        }
        else
        {
            if (solveSudoku(x, y + 1)) // If not at the end of the line, go one to the right
                return true;
        }
        return false;
    }

    for (int i = 1; i <= getSize(); i++)
    {
        if (isAllowedHere(x, y, i))
        {
            setCell(x, y, i);
            if (y == getSize() - 1) // If at the right side of the board, go down one line
            {
                if (solveSudoku(x + 1, 0))
                    return true;
            }
            else
            {
                if (solveSudoku(x, y + 1)) // If not at the end of the line, go one to the right
                    return true;
            }
        }
    }
    setCell(x, y, 0);
    return false;
}

bool Board::isAllowedHere(int x, int y, int value)
{
    bool isAllowed = true;

    // Check Row and Column if value is allowed here
    for (int i = 0; i < getSize(); i++)
    {
        if (getCell(x, i) == value)
        {
            isAllowed = false;
        }

        if (getCell(i, y) == value)
        {
            isAllowed = false;
        }
    }

    int blockSize = (int)sqrt(getSize());

    int blockRow = blockSize * (x / blockSize);
    int blockColumn = blockSize * (y / blockSize);

    for (int i = 0; i < sqrt(getSize()); i++)
    {
        for (int j = 0; j < sqrt(getSize()); j++)
        {
            if (getCell(blockRow + i, blockColumn + j) == value)
            {
                return false;
            }
        }
    }

    return isAllowed;
}

int *getPermutation(int n)
{
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        int r = (rand() % n) + 1;
        int temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }

    return a;
}