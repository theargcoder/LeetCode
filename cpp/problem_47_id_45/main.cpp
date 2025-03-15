#include <iostream>
#include <vector>

class Solution
{
  public:
    int
    jump (std::vector<int> &nums)
    {
        int min = 1;
        int size = nums.size () - 1;
        if (size == 1)
            return min;
        if (size == 0)
            return 0;
        int missing = size - nums.front ();
        if (missing == 0)
            return min;
        int sum, sum_max = 0;
        std::pair<int, int> best_pair{ 1, nums.front () };

        while (missing > 0)
            {
                int lim = best_pair.first + best_pair.second;
                for (int i = best_pair.first; i < size && i < lim; i++)
                    {
                        sum = i + nums[i];
                        if (sum >= sum_max)
                            {
                                sum_max = sum;
                                best_pair.first = i + 1;
                                best_pair.second = nums[i];
                            }
                    }
                missing = size - best_pair.first - best_pair.second;
                sum_max = 0;
                sum = 0;
                min++;
            }
        if (missing == 0)
            min++;

        return min;
    }
};
