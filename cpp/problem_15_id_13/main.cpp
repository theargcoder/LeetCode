#include <iostream>
#include <string>

class Solution
{
  public:
    int
    romanToInt (std::string s)
    {
        int result = 0;
        std::unordered_map<char, int> roman_char_int;
        roman_char_int['I'] = 1;
        roman_char_int['V'] = 5;
        roman_char_int['X'] = 10;
        roman_char_int['L'] = 50;
        roman_char_int['C'] = 100;
        roman_char_int['D'] = 500;
        roman_char_int['M'] = 1000;

        int size = s.size ();

        int prev = 0;
        for (int i = size - 1; i >= 0; i--)
            {
                int curr = roman_char_int[s[i]];
                if (prev > curr)
                    {
                        result -= curr;
                    }
                else
                    {
                        result += curr;
                    }
                prev = curr;
            }

        return result;
    }
};

int
main ()
{
    Solution solution;

    std::cout << "result is: " << solution.romanToInt ("IV") << '\n';
    std::cout << "result is: " << solution.romanToInt ("VII") << '\n';
    std::cout << "result is: " << solution.romanToInt ("III") << '\n';
    std::cout << "result is: " << solution.romanToInt ("MMCI") << '\n';
    return 0;
}
