#include <iostream>
#include <string>

class Solution
{
  public:
    int
    reverse (int x)
    {
        int reversed = 0;

        if (x == 0)
            {
                return 0;
            }

        bool negative = false;
        if (x < 0)
            negative = true;

        while (x != 0)
            {
                int remainder = x % 10;
                x = x / 10;

                if (reversed >= (INT32_MAX / 10) || reversed <= INT32_MIN / 10)
                    return 0;
                reversed = (reversed * 10) + remainder;
            }

        return reversed;
    }
};

int
main ()
{
    Solution solution;
    std::cout << "reversing : " << 1 << " output : " << solution.reverse (1)
              << '\n';
    std::cout << "reversing : " << 100
              << " output : " << solution.reverse (100) << '\n';
    std::cout << "reversing : " << 123
              << " output : " << solution.reverse (123) << '\n';
    std::cout << "reversing : " << -123
              << " output : " << solution.reverse (-123) << '\n';
    std::cout << "reversing : " << 120
              << " output : " << solution.reverse (120) << '\n';
    return 0;
}
