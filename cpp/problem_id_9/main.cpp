#include <iostream>
#include <string>

// safe solution working perfectly
class Solution
{
  public:
    bool
    isPalindrome (int x)
    {
        if (x < 0)
            return false;

        std::string number = std::to_string (x);
        int size = number.size ();

        if (size == 1)
            return true;

        if ((size % 2) == 0)
            {
                int middle_right = size / 2;
                int middle_left = middle_right - 1;

                while (middle_left >= 0)
                    {
                        if (number[middle_left] != number[middle_right])
                            {
                                return false;
                            }
                        middle_left--;
                        middle_right++;
                    }
                return true;
            }
        else
            {
                int middle = size / 2;
                int middle_left = middle - 1;
                int middle_right = middle + 1;

                while (middle_left >= 0)
                    {
                        if (number[middle_left] != number[middle_right])
                            {
                                return false;
                            }
                        middle_left--;
                        middle_right++;
                    }
                return true;
            }
    }
};

int
main ()
{
    Solution solution;

    std::vector<int> inputs{ 121, -121, 10,        234565432,  -2345432,
                             1,   2,    123455432, 1234554321, 12345678 };

    std::vector<bool> expected_outputs{ true, false, false, true, false,
                                        true, true,  false, true, false };

    for (int i = 0; i < inputs.size (); i++)
        {
            bool output = solution.isPalindrome (inputs[i]);
            std::cout << "case " << i << " is: ";

            if (output == expected_outputs[i])
                {
                    std::cout << "CORRECT " << '\n';
                }
            else
                {
                    std::cout << " NOT RIGHT" << '\n';
                }
        }
    return 0;
}
