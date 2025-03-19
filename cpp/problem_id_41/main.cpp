#include <iostream>
#include <math.h>
#include <vector>

class Solution
{
  public:
    int
    firstMissingPositive (std::vector<int> &nums)
    {
        int size = nums.size ();

        for (int p = 0; p < 6; p++)
            {
                for (int i = 0; i < size; i++)
                    {
                        if (nums[i] > 0 && nums[i] < size)
                            {
                                std::swap (nums[i], nums[nums[i] - 1]);
                            }
                    }
            }

        if (nums.front () != 1)
            return 1;
        for (int i = 0; i < size; i++)
            {
                if (i + 1 != nums[i])
                    return i + 1;
            }
        return size + 1;
    }
};

int
main ()
{

    return 0;
}
