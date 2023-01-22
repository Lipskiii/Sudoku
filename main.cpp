#include <iostream>
#include "sudoku.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    std::cout << "WELCOME!\nCHOOSE GAME:\n1. Sudoku\n";
    int game = 1;
    std::scanf("%d", &game);
    switch (game)
    {
    case 1:
        startSudoku();
        break;
    default:
        std::cout << "ERROR";
    }
    // b.printBoard();

    return 0;
}