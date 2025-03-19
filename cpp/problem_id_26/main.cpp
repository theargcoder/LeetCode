#include <iostream>
#include <vector>

class Solution
{
  public:
    int
    removeDuplicates (std::vector<int> &nums)
    {
        int size = nums.size ();
        if (size == 0)
            return 0;
        if (size == 1)
            return 1;

        std::vector<int> non_repeats{ nums[0] };

        int count = 0;

        for (int i = 0; i < size; i++)
            {
                if (non_repeats[count] != nums[i])
                    {
                        non_repeats.push_back (nums[i]);
                        count++;
                    }
            }

        for (int i = 0; i <= count; i++)
            {
                nums[i] = non_repeats[i];
            }

        return count + 1;
    }
};
