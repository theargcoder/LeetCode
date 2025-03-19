#include <array>
#include <deque>
#include <iostream>
#include <math.h>
#include <vector>

class Solution
{
  public:
    std::string
    multiply (std::string num1, std::string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size (), m = num2.size ();
        std::vector<int> res (n + m, 0);

        for (int i = n - 1; i >= 0; i--)
            {
                for (int j = m - 1; j >= 0; j--)
                    {
                        int product = (num1[i] - '0') * (num2[j] - '0');
                        int sum = res[i + j + 1] + product;
                        res[i + j + 1] = sum % 10;
                        res[i + j] += sum / 10;
                    }
            }

        int idx = 0;
        while (idx < res.size () && res[idx] == 0)
            {
                idx++;
            }

        std::string product;
        for (; idx < res.size (); idx++)
            {
                product.push_back (res[idx] + '0');
            }

        return product;
    }
};

int
main ()
{
    Solution sol;
    std::vector<std::vector<std::string> > testcases{ { "2", "3" },
                                                      { "123", "456" } };
    std::vector<int> expect{ "6", "56088" };
    for (int i = 0; i < testcases.size (); i++)
        {
            std::string response
                = sol.multiply (testcases[i].front (), testcases[i].back ());
            std::cout << "\n\n RESULT IS : " << response << '\n';
            std::cout << "EXPECTED IS : " << expect[i] << '\n';
        }
    return 0;
}
