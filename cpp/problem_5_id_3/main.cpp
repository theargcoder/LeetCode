#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
  public:
    int
    lengthOfLongestSubstring (std::string s)
    {
        std::unordered_map<char, bool> chars;

        for (char c = 32; c <= 126; ++c)
            { // ASCII printable range: 32 (space) to 126 (~)
              // THIS INCLUDES UPPERCASES.....
                chars[c] = false;
            }

        int outer_start = 0, difference = 0, largest_difference = 0;
        int size = s.size ();

        for (int i = 0; i < size; i++)
            {
                if (chars[s[i]] == true)
                    {
                        if (difference > largest_difference)
                            {
                                largest_difference = difference;
                                difference = 0;
                            }
                        else
                            {
                                difference = 0;
                            }
                        for (char c = 32; c <= 126; ++c)
                            {
                                chars[c] = false;
                            }
                        outer_start++;
                        i = outer_start;
                        chars[s[i]] = true;
                        difference++;
                    }
                else if (i == size - 1 && chars[s[i]] == false
                         && difference >= largest_difference)
                    {
                        largest_difference = difference + 1;
                    }
                else
                    {
                        chars[s[i]] = true;
                        difference++;
                    }
            }

        return largest_difference;
    }
};

int
main ()
{
    Solution solution;

    std::string str_1 = "abcabcbb";
    int result = solution.lengthOfLongestSubstring (str_1);

    std::cout << str_1 << '\n';
    std::cout << result << '\n';

    std::string str_2 = "bbbbb";
    result = solution.lengthOfLongestSubstring (str_2);

    std::cout << str_2 << '\n';
    std::cout << result << '\n';

    std::string str_3 = "pwwkew";
    result = solution.lengthOfLongestSubstring (str_3);

    std::cout << str_3 << '\n';
    std::cout << result << '\n';

    std::string str_4 = "aab";
    result = solution.lengthOfLongestSubstring (str_4);

    std::cout << str_4 << '\n';
    std::cout << result << '\n';

    std::string str_5 = "dvdf";
    result = solution.lengthOfLongestSubstring (str_5);

    std::cout << str_5 << '\n';
    std::cout << result << '\n';

    return 0;
}
