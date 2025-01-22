#include <deque>
#include <iostream>
#include <string>

class Solution
{
  public:
    std::string
    intToRoman (int num)
    {
        std::deque<char> roman_encoded;
        char roman_chars[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

        int reminder;
        int curr = 0, next = 2;
        while (num > 0)
            {
                reminder = num % 10;

                num = num / 10;

                if (0 < reminder && reminder < 4)
                    {
                        for (int i = (reminder); i > 0; i--)
                            {
                                roman_encoded.push_front (roman_chars[curr]);
                            }
                    }
                if (reminder == 4)
                    {
                        roman_encoded.push_front (roman_chars[curr + 1]);
                        roman_encoded.push_front (roman_chars[curr]);
                    }
                if (reminder == 5)
                    {
                        roman_encoded.push_front (roman_chars[curr + 1]);
                    }
                if (5 < reminder && reminder < 9)
                    {
                        for (int i = (reminder - 5); i > 0; i--)
                            {
                                roman_encoded.push_front (roman_chars[curr]);
                            }
                        roman_encoded.push_front (roman_chars[curr + 1]);
                    }
                if (reminder == 9)
                    {
                        roman_encoded.push_front (roman_chars[next]);
                        roman_encoded.push_front (roman_chars[curr]);
                    }
                curr += 2;
                if (next != 6)
                    next += 2;
            }

        std::string roman;
        for (auto i : roman_encoded)
            {
                roman += i;
            }
        return roman;
    }
};

int
main ()
{
    Solution solution;

    std::cout << "result is: " << solution.intToRoman (3999) << '\n';
    return 0;
}
