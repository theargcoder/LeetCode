#include <iostream>
#include <string>

class Solution
{
  public:
    std::string
    convert (std::string s, int numRows)
    {
        std::string result;
        int input_string_size = s.size ();

        if (input_string_size <= numRows)
            return s;

        if (numRows == 1)
            return s;

        int empty_spaces = numRows - 2;
        std::string container[numRows];

        for (int i = 0; i < numRows; i++)
            container[i] += s[i];

        int L = numRows - 2;
        bool add = false;

        for (int i = numRows; i < input_string_size; i++)
            {
                if (L == 0)
                    add = true;
                if (L == (numRows - 1))
                    add = false;

                container[L] += s[i];

                if (add)
                    L++;
                else
                    L--;
            }

        for (int i = 0; i < numRows; i++)
            {
                result += container[i];
            }

        return result;
    }
};

int
main ()
{
    Solution solution;

    // Test inputs
    std::vector<std::string> inputs = { "PAYPALISHIRING",
                                        "PAYPALISHIRING",
                                        "A",
                                        "HELLO",
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                                        "ABCDEFG",
                                        "ABCDEFG",
                                        "THISISATEST",
                                        "EXAMPLESAREFUN",
                                        "ZIGZAGCONVERSION" };

    // Number of rows
    std::vector<int> numRows = { 3, 4, 1, 2, 5, 7, 1, 6, 3, 8 };

    // Expected outputs
    std::vector<std::string> expected_results = { "PAHNAPLSIIGYIR",
                                                  "PINALSIGYAHRPI",
                                                  "A",
                                                  "HLOEL",
                                                  "AIQBHJPRXZCGKOSYDFLNTWEMU",
                                                  "ABCDEFG",
                                                  "ABCDEFG",
                                                  "TSTHIAIEISS",
                                                  "EAELEXMSPRNAFU",
                                                  "ZOGRNSIICVAEZO" };

    // Run tests and compare results
    for (size_t i = 0; i < inputs.size (); ++i)
        {
            std::string result = solution.convert (inputs[i], numRows[i]);

            if (result == expected_results[i])
                {
                    std::cout << "GOOD" << '\n';
                }
            else
                {
                    std::cout << "BAD" << '\n';
                }

            std::cout << "Result: " << result << '\n';
            std::cout << "Expected: " << expected_results[i] << "\n\n";
        }

    return 0;
}
