#include <iostream>
#include <vector>

class Solution
{
  public:
    bool
    isValidSudoku (std::vector<std::vector<char> > &board)
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
                        if (buffy.find (board[j][i]) != std::string::npos)
                            return false;
                        else if (std::isdigit (board[j][i]))
                            buffy.push_back (board[j][i]);
                    }
            }
        // no rows or columns with repeating numbers now on to the 3x3 boards

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

int
main ()
{
    return 0;
}
