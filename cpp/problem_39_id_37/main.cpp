#include <cassert>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// ANIMAL style brute force
/*
class Solution
{
  public:
    void
    solveSudoku (std::vector<std::vector<char> > &board)
    {
        using coordinates = std::pair<int, int>;
        using char_valid = std::unordered_map<char, bool>;

        std::vector<std::vector<char> > board_cpy = board;
        std::unordered_map<coordinates, char_valid, pair_hash> usable;
        std::vector<char> posibilities
            = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        int size = board.size ();
        std::vector<std::string> buff3x3
            = { "", "", "", "", "", "", "", " ", "" };
        std::vector<std::string> buffx
            = { "", "", "", "", "", "", "", " ", "" };
        std::vector<std::string> buffy
            = { "", "", "", "", "", "", "", " ", "" };
        for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    {
                        if (std::isdigit (board[i][j]))
                            {
                                buffx[i].push_back (board[i][j]);
                            }
                        if (std::isdigit (board[i][j]))
                            {
                                buffy[j].push_back (board[i][j]);
                            }
                    }
            }
        for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    {
                        int loc = i * 3 + j;
                        for (int x = i * 3; x < (i * 3 + 3); x++)
                            {
                                for (int y = j * 3; y < (j * 3 + 3); y++)
                                    {
                                        if (std::isdigit (board[x][y]))
                                            buff3x3[loc].push_back (
                                                board[x][y]);
                                    }
                            }
                    }
            }
        for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    {
                        if (board[i][j] == '.')
                            {
                                for (auto &chr : buffx[i])
                                    {
                                        usable[coordinates (i, j)][chr]
                                            = false;
                                    }
                                for (auto &chr : buffy[j])
                                    {
                                        usable[coordinates (i, j)][chr]
                                            = false;
                                    }
                            }
                    }
            }

        for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    {
                        int loc = i * 3 + j;
                        for (int x = i * 3; x < (i * 3 + 3); x++)
                            {
                                for (int y = j * 3; y < (j * 3 + 3); y++)
                                    {
                                        if (board[x][y] == '.')
                                            {
                                                for (auto &chr : buff3x3[loc])
                                                    {
                                                        usable[coordinates (
                                                            x, y)][chr]
                                                            = false;
                                                    }
                                            }
                                    }
                            }
                    }
            }

        for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    {
                        if (board[i][j] == '.')
                            {
                                for (auto &chr : posibilities)
                                    {
                                        if (usable[coordinates (i, j)].count (
                                                chr)
                                            == 0)
                                            {
                                                usable[coordinates (i, j)][chr]
                                                    = true;
                                            }
                                    }
                            }
                    }
            }

        std::vector<std::vector<int> > constraints[9];
        std::vector<std::vector<int> > permus[9];
        bool done[9] = { false, false, false, false, false,
                         false, false, false, false };
        bool non_1s = true;
        while (non_1s)
            {

                non_1s = false;

                for (int i = 0; i < 9; i++)
                    {
                        if (done[i])
                            continue;

                        constraints[i].clear ();
                    }

                std::vector<std::vector<int> > x_arrs;
                for (int i = 0; i < 9; i++)
                    {
                        x_arrs.push_back ({});
                        if (done[i])
                            continue;
                        for (int j = 0; j < 9; j++)
                            {
                                if (board[i][j] == '.')
                                    {
                                        constraints[i].push_back ({});
                                        for (const auto &[chr, boo] :
                                             usable[coordinates (i, j)])
                                            {
                                                if (boo)
                                                    {
                                                        if (std::find (
                                                                x_arrs[i]
                                                                    .begin (),
                                                                x_arrs[i]
                                                                    .end (),
                                                                chr)
                                                            == x_arrs[i]
                                                                   .end ())
                                                            x_arrs[i]
                                                                .push_back (
                                                                    chr);
                                                        constraints[i]
                                                            .back ()
                                                            .push_back (chr);
                                                    }
                                            }
                                    }
                            }
                    }

                long long combinatory = 0;
                for (int i = 0; i < 9; i++)
                    {
                        if (done[i])
                            continue;
                        permus[i] = generate_valid_permutations (
                            x_arrs[i], constraints[i]);
                        if (combinatory != 0)
                            combinatory *= permus[i].size ();
                        else
                            combinatory += permus[i].size ();
                    }

                std::cout << "\n\n\n\n NUMBER OF TOTAL PERMUTATIOSN IS : "
                          << combinatory << "\n\n\n\n\n";
                for (int i = 0; i < 9; i++)
                    {
                        if (done[i])
                            continue;
                        if (permus[i].size () == 1)
                            {
                                non_1s = true;
                                done[i] = true;
                                int x = 0;
                                for (int j = 0; j < size; j++)
                                    {
                                        if (board[i][j] == '.')
                                            {
                                                usable[coordinates (j, i)]
                                                      [permus[i][0][x]]
                                                    = false;
                                                x++;
                                            }
                                    }
                            }
                    }
            }

        std::vector<int> perm_lock (9, 0);

        std::vector<int> permu_sizes;
        for (int i = 0; i < 9; i++)
            {
                permu_sizes.push_back (permus[i].size ());
            }

        bool valid = isvalidsudoku (board_cpy);
        int fixed = 0;
        while (!valid)
            {
                for (int i = 0; i < size; i++)
                    {
                        int x = 0;
                        for (int j = 0; j < size; j++)
                            {
                                if (board[i][j] == '.')
                                    {
                                        board_cpy[i][j]
                                            = permus[i][perm_lock[i]][x];
                                        x++;
                                    }
                            }
                    }
                bool inc = increment_perm_lock (perm_lock, permu_sizes);

                if (!inc)
                    break;
                valid = isvalidsudoku (board_cpy);
            }

        board = board_cpy;
    }

  private:
    bool
    increment_perm_lock (std::vector<int> &perm_lock,
                         const std::vector<int> &sizes)
    {
        int n = perm_lock.size ();
        for (int pos = n - 1; pos >= 0; pos--)
            {
                if (perm_lock[pos] < sizes[pos] - 1)
                    {
                        perm_lock[pos]++;

                        for (int j = pos + 1; j < n; j++)
                            {
                                perm_lock[j] = 0;
                            }
                        return true;
                    }
            }
        return false;
    }
    bool
    is_valid_for_position (int value, int pos,
                           const std::vector<std::vector<int> > &constraints)
    {
        if (pos < constraints.size () && !constraints[pos].empty ())
            {
                for (int allowed_val : constraints[pos])
                    {
                        if (allowed_val == value)
                            return true;
                    }
                return false;
            }
        return true;
    }

    void
    backtrack (int pos, const std::vector<int> &array,
               const std::vector<std::vector<int> > &constraints,
               std::vector<bool> &used, std::vector<int> &current_permutation,
               std::vector<std::vector<int> > &valid_permutations)
    {
        if (pos == array.size ())
            {
                valid_permutations.push_back (current_permutation);
                return;
            }

        for (std::size_t i = 0; i < array.size (); i++)
            {
                if (!used[i])
                    {
                        int candidate = array[i];
                        if (is_valid_for_position (candidate, pos,
                                                   constraints))
                            {
                                used[i] = true;
                                current_permutation.push_back (candidate);
                                backtrack (pos + 1, array, constraints, used,
                                           current_permutation,
                                           valid_permutations);
                                current_permutation.pop_back ();
                                used[i] = false;
                            }
                    }
            }
    }

    std::vector<std::vector<int> >
    generate_valid_permutations (
        const std::vector<int> &array,
        const std::vector<std::vector<int> > &constraints)
    {
        std::vector<std::vector<int> > valid_permutations;
        std::vector<int> current_permutation;
        std::vector<bool> used (array.size (), false);
        backtrack (0, array, constraints, used, current_permutation,
                   valid_permutations);
        return valid_permutations;
    }

  private:
    struct pair_hash
    {
        template <class t1, class t2>
        std::size_t
        operator() (const std::pair<t1, t2> &p) const
        {
            return std::hash<t1>{}(p.first) ^ (std::hash<t2>{}(p.second) << 1);
        }
    };

  private:
    bool
    isvalidsudoku (std::vector<std::vector<char> > &board)
    {
        int size = board.size ();
        for (int i = 0; i < size; i++)
            {
                std::string buffx, buffy;
                for (int j = 0; j < size; j++)
                    {
                        if (buffx.find (board[i][j]) != std::string::npos)
                            return false;
                        else if (std::isdigit (board[i][j]))
                            buffx.push_back (board[i][j]);
                        else
                            return false;

                        if (buffy.find (board[j][i]) != std::string::npos)
                            return false;
                        else if (std::isdigit (board[j][i]))
                            buffy.push_back (board[j][i]);
                        else
                            return false;
                    }
            }
        // no rows or columns with repeating numbers now on to the 3x3
        // boards

        for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    {
                        std::string buff;
                        for (int x = i * 3; x < (i * 3 + 3); x++)
                            {
                                for (int y = j * 3; y < (j * 3 + 3); y++)
                                    {
                                        if (buff.find (board[x][y])
                                            != std::string::npos)
                                            return false;
                                        else if (std::isdigit (board[x][y]))
                                            buff.push_back (board[x][y]);
                                    }
                            }
                    }
            }
        return true;
    }
};
*/
/*
class Solution
{
  public:
    bool
    isValid (std::vector<std::vector<char> > &board, int row, int col,
             char num)
    {
        // Check row & column
        for (int i = 0; i < 9; i++)
            {
                if (board[row][i] == num || board[i][col] == num)
                    return false;
            }

        // Check 3x3 box
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    {
                        if (board[startRow + i][startCol + j] == num)
                            return false;
                    }
            }
        return true;
    }

    bool
    solve (std::vector<std::vector<char> > &board, int row, int col)
    {
        if (row == 9)
            return true; // Reached end

        if (board[row][col] != '.') // Skip pre-filled cells
            return solve (board, col == 8 ? row + 1 : row, (col + 1) % 9);

        for (char num = '1'; num <= '9'; num++)
            {
                if (isValid (board, row, col, num))
                    {
                        board[row][col] = num;
                        if (solve (board, col == 8 ? row + 1 : row,
                                   (col + 1) % 9))
                            return true;
                        board[row][col] = '.'; // Backtrack
                    }
            }
        return false;
    }

    void
    solveSudoku (std::vector<std::vector<char> > &board)
    {
        solve (board, 0, 0);
    }
};
*/

// CHAT GPTS SOLUTION AMAZING STUFF TBH
// Optimized Sudoku Solver using bitmask, MRV, and incremental propagation.
class Solution
{
  public:
    // Public function to solve the board in-place.
    // The board is a 9x9 grid with digits '1'-'9' and '.' for empty cells.
    void
    solveSudoku (std::vector<std::vector<char> > &board)
    {
        // Initialize bitmasks for rows, columns, and blocks.
        rows.assign (9, 0);
        cols.assign (9, 0);
        blocks.assign (9, 0);
        empties.clear ();

        // Fill in the bitmasks and record positions of empty cells.
        for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                    {
                        if (board[i][j] == '.')
                            {
                                empties.push_back ({ i, j });
                            }
                        else
                            {
                                int d
                                    = board[i][j]
                                      - '1'; // convert char to 0-indexed digit
                                int mask = 1 << d;
                                rows[i] |= mask;
                                cols[j] |= mask;
                                blocks[blockIndex (i, j)] |= mask;
                            }
                    }
            }

        // Start the backtracking recursion.
        solve (board, 0);
    }

  private:
    std::vector<int> rows, cols,
        blocks; // Bitmasks for each row, column, block.
    std::vector<std::pair<int, int> >
        empties; // List of positions for empty cells.

    // Compute block index for cell (i, j).
    int
    blockIndex (int i, int j)
    {
        return (i / 3) * 3 + (j / 3);
    }

    // Recursive backtracking solver.
    bool
    solve (std::vector<std::vector<char> > &board, int pos)
    {
        // If we've filled all empty cells, we're done.
        if (pos == empties.size ())
            return true;

        // Apply the MRV heuristic: choose the empty cell with the fewest
        // candidates.
        int minPos = pos;
        int minCandidates = 10; // More than the maximum possible (9).
        for (int k = pos; k < empties.size (); k++)
            {
                int i = empties[k].first;
                int j = empties[k].second;
                // Allowed candidates are those not already in the row, col, or
                // block.
                int allowed
                    = ~(rows[i] | cols[j] | blocks[blockIndex (i, j)]) & 0x1FF;
                int count = __builtin_popcount (
                    allowed); // Count number of bits set.
                if (count < minCandidates)
                    {
                        minCandidates = count;
                        minPos = k;
                        if (count == 1)
                            break; // Best-case scenario.
                    }
            }
        std::swap (empties[pos], empties[minPos]);

        int i = empties[pos].first;
        int j = empties[pos].second;
        int blk = blockIndex (i, j);
        int allowed = ~(rows[i] | cols[j] | blocks[blk]) & 0x1FF;

        // Try each candidate digit.
        while (allowed)
            {
                int pick = allowed & -allowed; // Get least significant bit.
                allowed -= pick; // Remove candidate from the allowed mask.
                int digit = __builtin_ctz (
                    pick); // Convert bitmask to digit (0-indexed).

                board[i][j] = '1' + digit;
                // Update the bitmasks.
                rows[i] |= pick;
                cols[j] |= pick;
                blocks[blk] |= pick;

                // Recurse for the next empty cell.
                if (solve (board, pos + 1))
                    return true;

                // Backtrack: undo changes.
                rows[i] ^= pick;
                cols[j] ^= pick;
                blocks[blk] ^= pick;
                board[i][j] = '.';
            }

        // No candidate worked, so backtrack.
        std::swap (empties[pos], empties[minPos]); // (Optional) Restore order.
        return false;
    }
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
