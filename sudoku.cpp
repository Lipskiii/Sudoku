
#include "sudoku.h"
#include <iostream>

void startSudoku()
{
    Board b = Board(9);
    // b.printBoard();
    setupSudokuBoard(b);
    while (gameloop(b))
    {
    };
}

void setupSudokuBoard(Board &b)
{
    // b.setCell(3, 3, 5);

    if (!b.generateSudoku(79))
    {
        std::cout << "Couldnt generate Sudoku" << std::endl;
        return;
    }

    // b.printBoard();
}

bool gameloop(Board &b)
{
    b.printBoard();
    while (!b.isFull())
    {
        std::string command; // Command which states what the player wants to do
        int paraX, paraY;    // Parameters to say where to perform given command
        int value;           // Parameter to say which value to put into cell
        std::cin >> command;
        if (command == "Put" || command == "put")
        {
            std::cin >> paraX >> paraY >> value;
            std::cout << "Put: " << paraX << " " << paraY << " " << value << std::endl;
            b.setCell(paraX - 1, paraY - 1, value);
        }
        else if (command == "Hint" || command == "hint")
        {
            std::cin >> paraX >> paraY;
            int hint = b.getHint(paraX - 1, paraY - 1);
            std::cout << "Hint: " << paraX << " " << paraY << " " << hint << std::endl;
            b.setCell(paraX - 1, paraY - 1, hint);
        }

        b.printBoard();
    }
    return false;
}