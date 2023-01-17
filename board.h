class Board
{
    int n;           // Grid size
    int **grid;      // Grid
    int **immutable; // used to remember which slots are filled in the begining

public:
    Board(int _n)
    {
        n = _n;

        grid = new int *[n];

        // Create grid
        for (int i = 0; i < n; i++)
        {
            grid[i] = new int[n];
        }

        // Initialize with zeros
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = 0;
            }
        }

        // Create grid to track immutables
        for (int i = 0; i < n; i++)
        {
            immutable = new int *[n];
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

    ~Board()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] grid[i];
        }

        delete[] grid;

        for (int i = 0; i < n; i++)
        {
            delete[] immutable[i];
        }

        delete[] immutable;
    }
};