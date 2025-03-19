#include <array>
#include <deque>
#include <iostream>
#include <math.h>
#include <vector>

// ALMOST WORKING
// Couldn't get it to work :(
/*
class Solution
{
  public:
    bool
    isMatch (std::string s, std::string p)
    {
        int p_size = p.size ();
        int s_size = s.size ();
        if (p_size == 1 && p == "*")
            return true;

        bool pivoted = false;
        int i_pivot, j_pivot, i = 0, j = 0;
        while (i < s_size && j < p_size)
            {
                if (p[j] == '*')
                    {
                        while (j < p_size && p[j] == '*')
                            {
                                j++;
                            }
                        if (j == p_size)
                            return true;
                        while (i < s_size && j < p_size && p[j] == '?')
                            {
                                i++;
                                j++;
                            }
                        size_t nex_j = p.find_first_of ({ '*', '?' }, j);
                        if (nex_j == std::string::npos)
                            nex_j = p.size ();
                        auto str_nj = p.substr (j, nex_j - j);
                        size_t found = s.find (str_nj, i);
                        if (found == std::string::npos)
                            return false;
                        else
                            {
                                i = (int)found + str_nj.size ();
                                if (!pivoted)
                                    {
                                        pivoted = true;
                                        i_pivot = i;
                                        j_pivot = j;
                                    }
                                j = (int)nex_j;
                            }
                    }
                else if (s[i] == p[j] || p[j] == '?')
                    {
                        i++;
                        j++;
                    }
                else
                    {
                        if (pivoted)
                            {
                                i = i_pivot;
                                j = j_pivot;
                                pivoted = false;
                            }
                        else
                            {
                                return false;
                            }
                    }
            }
        bool cool = true;
        while (j < p_size && p[j] == '*')
            {
                j++;
            }
        return (i == s_size && j == p_size);
    }
};
*/
using namespace std;
class Solution
{
  public:
    bool
    isMatch (string s, string p)
    {
        const int m = s.length ();
        const int n = p.length ();
        // dp[i][j] := true if s[0..i) matches p[0..j)
        vector<vector<bool> > dp (m + 1, vector<bool> (n + 1));
        dp[0][0] = true;

        auto isMatch = [&] (int i, int j) -> bool {
            return j >= 0 && p[j] == '?' || s[i] == p[j];
        };

        for (int j = 0; j < p.length (); ++j)
            if (p[j] == '*')
                dp[0][j + 1] = dp[0][j];

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (p[j] == '*')
                    {
                        const bool matchEmpty = dp[i + 1][j];
                        const bool matchSome = dp[i][j + 1];
                        dp[i + 1][j + 1] = matchEmpty || matchSome;
                    }
                else if (isMatch (i, j))
                    {
                        dp[i + 1][j + 1] = dp[i][j];
                    }

        return dp[m][n];
    }
};
int
main ()
{
    Solution sol;
    std::vector<std::vector<std::string> > testcases{ { "aa", "a" },
                                                      { "aa", "*" },
                                                      { "cb", "?a" } };
    std::vector<bool> expect{ false, true, false };
    for (int i = 0; i < testcases.size (); i++)
        {
            bool response
                = sol.isMatch (testcases[i].front (), testcases[i].back ());
            std::cout << "\n\n RESULT IS : ";
            if (response == true)
                std::cout << "true" << '\n';
            else
                std::cout << "false" << '\n';

            std::cout << "EXPECTED IS : ";
            if (expect[i] == true)
                std::cout << "true" << '\n';
            else
                std::cout << "false" << '\n';
        }
    return 0;
}
