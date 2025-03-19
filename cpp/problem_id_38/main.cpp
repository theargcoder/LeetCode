#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    std::string
    countAndSay (int n)
    {
        if (n == 1)
            return to_ret;

        std::string newly;
        char prev = to_ret.front ();
        size_t st = 0;
        size_t en = to_ret.find_first_not_of (prev);
        while (en < to_ret.size ())
            {
                newly += std::to_string (en - st);
                newly += prev;
                prev = to_ret[en];
                st = en;
                en = to_ret.find_first_not_of (prev, en);
            }
        newly += std::to_string (to_ret.size () - st);
        newly += prev;

        to_ret = newly;

        return countAndSay (n - 1);
    }

  private:
    std::string to_ret = "1";
};

int
main ()
{
    // Example Sudoku board (empty cells as '.')
    std::vector<std::vector<char> > board
        = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    Solution solver;

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now ();

    solver.solveSudoku (board);

    // Stop measuring time
    auto stop = std::chrono::high_resolution_clock::now ();

    // Compute duration in microseconds
    auto duration_micro
        = std::chrono::duration_cast<std::chrono::microseconds> (stop - start);
    auto duration_mill
        = std::chrono::duration_cast<std::chrono::milliseconds> (stop - start);

    // Print solved board
    std::cout << "Solved Sudoku:\n";
    for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                {
                    std::cout << board[i][j] << " ";
                    if (j == 2 || j == 5)
                        std::cout << "  ";
                }
            std::cout << "\n";
            if (i == 2 || i == 5)
                std::cout << "\n";
        }

    // Print execution time
    std::cout << "\nExecution Time: " << duration_micro.count ()
              << " microseconds\n";
    std::cout << "\nExecution Time: " << duration_mill.count ()
              << " milliseconds\n";

    return 0;
}
