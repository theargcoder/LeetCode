#include <iostream>
#include <vector>

class Solution
{
  public:
    int
    removeElement (std::vector<int> &nums, int val)
    {
        std::vector<int> result;
        for (int i = 0; i < nums.size (); i++)
            {
                if (nums[i] != val)
                    {
                        result.push_back (nums[i]);
                    }
            }
        int res_size = result.size ();
        for (int i = 0; i < res_size; i++)
            {
                nums[i] = result[i];
            }

        return res_size;
    }
};
