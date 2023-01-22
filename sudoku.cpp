
#include "sudoku.h"
#include <iostream>

void startSudoku()
{
    Board b = Board(9);
    // b.printBoard();
    setupSudokuBoard(b);
}

void setupSudokuBoard(Board &b)
{
    // b.setCell(3, 3, 5);

    if (!b.generateSudoku(10))
    {
        std::cout << "Couldnt generate Sudoku" << std::endl;
    }
    else
    {

        b.printBoard();
    }
}