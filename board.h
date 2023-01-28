class Board
{
private:
    int n;            // Grid size
    int **playgrid;   // Grid
    int **solvegrid;  // Used to store the solved grid
    bool **immutable; // used to remember which slots are filled in the begining

public:
    Board(int _n)
    {
        n = _n;

        playgrid = new int *[n];
        solvegrid = new int *[n];

        // Create grid
        for (int i = 0; i < n; i++)
        {
            playgrid[i] = new int[n];
            solvegrid[i] = new int[n];
        }

        // Initialize with zeros
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                playgrid[i][j] = 0;
                solvegrid[i][j] = 0;
            }
        }

        immutable = new bool *[n];

        // Create grid to track immutables
        for (int i = 0; i < n; i++)
        {
            immutable[i] = new bool[n];
        }

        // Initialize with zeros
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                immutable[i][j] = 0;
            }
        }
    }

    void printBoard(); // Prints current board state to screen
    bool isFull();     // Returns true if the current board is complete
    void resetBoard(); // Resets all mutable values to 0

    int getCell(int x, int y);                                  // Returns content of cell at (x, y)
    void setCell(int x, int y, int value);                      // Assigns content of cell (x, y) to value
    bool getImmutability(int x, int y);                         // Returns immutablility of cell (x, y)
    void setImmutability(int x, int y, bool newImmutableValue); // Assigns immutability of cell (x, y) to newImmutableValue
    int getSize();
    int getHint(int x, int y); // Returns the solution for cell (x, y)

    bool generateSudoku(int preFilled); // Fills the board with a valid sudoku puzzle
    bool solveSudoku(int x, int y);     // Solves current state of board returns true if possible, false if it isn't
    bool isAllowedHere(int x, int y, int value);
};

int *getPermutation(int n);
