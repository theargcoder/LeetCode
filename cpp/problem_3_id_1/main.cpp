#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int>
    twoSum (std::vector<int> &nums, int target)
    {
        std::vector<int> result;
        int size = nums.size ();
        int i = 0, j;
        bool sum_equal;

        while (i != size)
            {
                j = i + 1;
                while (j != size)
                    {
                        sum_equal = (nums[i] + nums[j]) == target;
                        if (sum_equal)
                            {
                                result.push_back (i);
                                result.push_back (j);
                                break;
                            }
                        j++;
                    }
                i++;
            }

        return std::move (result);
    }
};

int
main ()
{
    Solution solution;
    std::vector<int> input;
    input.push_back (2);
    input.push_back (7);
    input.push_back (11);
    input.push_back (15);

    std::vector<int> result = solution.twoSum (input, 9);

    std::cout << "case 1" << '\n';
    for (int i : result)
        {
            std::cout << i << '\n';
        }

    input.clear ();
    input.push_back (3);
    input.push_back (2);
    input.push_back (4);

    result = solution.twoSum (input, 6);

    std::cout << "case 2" << '\n';
    for (int i : result)
        {
            std::cout << i << '\n';
        }

    input.clear ();
    input.push_back (3);
    input.push_back (3);

    result = solution.twoSum (input, 6);

    std::cout << "case 3" << '\n';
    for (int i : result)
        {
            std::cout << i << '\n';
        }
    return 0;
}
