#include <iostream>
#include <string>

#include <cstddef> // For std::size_t
#include <string>

/*
std::size_t
rfind_with_dot_match (const std::string &str, const std::string &substr,
                      std::size_t pos = std::string::npos)
{
    if (substr.empty () || substr.size () > str.size ())
        {
            return std::string::npos;
        }

    // Limit the starting position to the valid range
    pos = std::min (pos, str.size () - substr.size ());

    for (std::size_t i = pos + 1; i-- > 0;)
        {
            bool match = true;
            for (std::size_t j = 0; j < substr.size (); ++j)
                {
                    char str_char = str[i + j];
                    char substr_char = substr[j];
                    if (substr_char != '.' && str_char != substr_char)
                        {
                            match = false;
                            break;
                        }
                }
            if (match)
                {
                    return i;
                }
        }

    return std::string::npos;
}

class Solution
{
  public:
    bool
    isMatch (std::string s, std::string p)
    {
        if (p == ".*")
            return true;

        int s_size = s.size ();
        int p_size = p.size ();

        if (s_size == 1 && s == " ")
            {
                if (p_size == 1)
                    return false;
                for (int i = 0; i < p_size; i++)
                    {

                        if (i % 2 != 0)
                            {
                                if (p[i] != '*')
                                    {
                                        return false;
                                    }
                            }
                    }
                return true;
            }

        int s_st = 0, p_st = 0;
        int s_en = s_size - 1, p_en = p_size - 1;

        std::size_t star_pos = p.find ('*');
        if (star_pos == std::string::npos)
            {
                if (s_size != p_size)
                    {
                        return false;
                    }
                for (s_st = 0; s_st < s_size; s_st++)
                    {
                        if (s[s_st] != p[s_st] && p[s_st] != '.')
                            return false;
                    }
                return true;
            }
        else
            {
                for (s_st = 0; s_st < (star_pos - 1); s_st++)
                    {
                        if (s[s_st] != p[p_st] && p[p_st] != '.'
                            && p[s_st] != p[star_pos - 1])
                            return false;
                        p_st++;
                    }

                if (p[p_st] == '.')
                    {
                        if (star_pos + 1 == p_size)
                            {
                                return true;
                            }

                        std::size_t next_star_pos = p.find ('*', star_pos + 1);
                        if (next_star_pos == std::string::npos)
                            {
                                std::string p_end_str = p.substr (
                                    star_pos + 1, p_size - star_pos - 1);
                                int s_last = s_size - 1;
                                for (int i = p_end_str.size () - 1; i >= 0;
                                     i--)
                                    {
                                        if (s[s_last] != p_end_str[i]
                                            && p_end_str[i] != '.')
                                            return false;
                                        s_last--;
                                    }
                                return true;
                            }
                        else
                            {
                                std::string bewteen_stars
                                    = p.substr (star_pos + 1,
                                                next_star_pos - star_pos - 2);
                                if (bewteen_stars.size () == 0)
                                    {
                                        p.erase (star_pos + 1,
                                                 next_star_pos - star_pos);
                                        return isMatch (s, p);
                                    }
                                else
                                    {

                                        std::size_t pattern_pos
                                            = rfind_with_dot_match (
                                                s, bewteen_stars);
                                        if (pattern_pos == std::string::npos)
                                            {
                                                return false;
                                            }
                                        else
                                            {
                                                std::string input_1
                                                    = s.substr (
                                                        pattern_pos
                                                            + bewteen_stars
                                                                  .size (),
                                                        s_size - pattern_pos
                                                            - bewteen_stars
                                                                  .size ());
                                                std::string input_2
                                                    = p.substr (
                                                        next_star_pos - 1,
                                                        p_size - next_star_pos
                                                            + 1);
                                                return isMatch (input_1,
                                                                input_2);
                                            }
                                    }
                            }
                    }
                else
                    {
                        if (star_pos + 1 == p_size)
                            {
                                if (s_st >= s_size)
                                    {
                                        return true;
                                    }
                                else
                                    {
                                        return s[s_st] == p[p_st];
                                    }
                            }
                        std::size_t pos_first_not
                            = s.find_first_not_of (p[p_st], s_st);
                        if (pos_first_not == s_st)
                            {
                                std::string input_1
                                    = s.substr (s_st, s_size - s_st);
                                std::string input_2 = p.substr (
                                    star_pos + 1, p_size - star_pos - 1);

                                return isMatch (input_1, input_2);
                            }
                        else if (pos_first_not != std::string::npos)
                            {
                                std::size_t next_star_pos
                                    = p.find ('*', star_pos + 1);

                                if (next_star_pos == std::string::npos)
                                    {
                                        next_star_pos = p_size;
                                    }
                                std::string bewteen_stars
                                    = p.substr (star_pos + 1,
                                                next_star_pos - star_pos - 2);

                                int repeats = pos_first_not - s_st;
                                int bewteen_stars_repeats = 0;
                                int x = 0;
                                for (int i = s_st; i < pos_first_not; i++)
                                    {
                                        if (x >= bewteen_stars.size ())
                                            break;
                                        if (s[i] == bewteen_stars[x])
                                            bewteen_stars_repeats++;
                                        else
                                            break;
                                        x++;
                                    }

                                if (bewteen_stars_repeats <= repeats)
                                    {
                                        std::string input_1 = s.substr (
                                            pos_first_not
                                                - bewteen_stars_repeats,
                                            s_size - pos_first_not
                                                + bewteen_stars_repeats);
                                        std::string input_2
                                            = p.substr (star_pos + 1,
                                                        p_size - star_pos - 1);

                                        return isMatch (input_1, input_2);
                                    }
                                else
                                    {
                                        return false;
                                    }
                            }
                        else if (s[s_st] == p[p_st])
                            {
                                pos_first_not = s_size;
                                std::size_t next_star_pos
                                    = p.find ('*', star_pos + 1);

                                int number;

                                if (next_star_pos == std::string::npos)
                                    {
                                        next_star_pos = p_size;
                                        number = next_star_pos - star_pos - 1;
                                    }
                                else
                                    {
                                        number = next_star_pos - star_pos - 2;
                                    }

                                std::string bewteen_stars;
                                if (number != 0)
                                    {
                                        bewteen_stars = p.substr (
                                            star_pos + 1,
                                            next_star_pos - star_pos - 2);
                                    }
                                else
                                    {
                                        bewteen_stars = "";
                                    }

                                int repeats = s_size;
                                int bewteen_stars_repeats = 0;
                                int x = 0;
                                for (int i = s_st; i < pos_first_not; i++)
                                    {
                                        if (x >= bewteen_stars.size ())
                                            {
                                                break;
                                            }
                                        if (s[i] == bewteen_stars[x])
                                            bewteen_stars_repeats++;
                                        else
                                            return false;
                                        x++;
                                    }

                                if (bewteen_stars_repeats <= repeats
                                    && bewteen_stars.size () < repeats)
                                    {
                                        p.erase (star_pos + 1,
                                                 next_star_pos - star_pos);

                                        return isMatch (s, p);
                                    }
                                else
                                    {
                                        return false;
                                    }
                            }
                        else
                            {
                                p.erase (p_st, star_pos - p_st + 1);

                                return isMatch (s, p);
                            }
                    }
            }
    }
};
*/

class Solution
{
  public:
    bool
    isMatch (std::string s, std::string p)
    {
        const int m = s.length ();
        const int n = p.length ();
        // dp[i][j] := true if s[0..i) matches p[0..j)
        std::vector<std::vector<bool> > dp (m + 1, std::vector<bool> (n + 1));
        dp[0][0] = true;

        auto isMatch = [&] (int i, int j) -> bool {
            return j >= 0 && p[j] == '.' || s[i] == p[j];
        };

        for (int j = 0; j < p.length (); ++j)
            if (p[j] == '*' && dp[0][j - 1])
                dp[0][j + 1] = true;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (p[j] == '*')
                    {
                        // The minimum index of '*' is 1.
                        const bool noRepeat = dp[i + 1][j - 1];
                        const bool doRepeat
                            = isMatch (i, j - 1) && dp[i][j + 1];
                        dp[i + 1][j + 1] = noRepeat || doRepeat;
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
    Solution solution;

    if (solution.isMatch ("a", ".*..") == true)
        {
            std::cout << '\n' << " ITS GOOD" << '\n';
        }
    else
        {
            std::cout << '\n' << " ITS NO BUENO" << '\n';
        }
    return 0;
}
