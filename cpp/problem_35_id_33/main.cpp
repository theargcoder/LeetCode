#include <vector>

class Solution
{
  public:
    int
    search (std::vector<int> &nums, int target)
    {
        int size = nums.size ();
        int found = 0;
        while (found < size)
            {
                if (nums[found] == target)
                    return found;
                found++;
            }
        return -1;
    }
};

int
main ()
{
    return 0;
}
