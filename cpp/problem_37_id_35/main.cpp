#include <iostream>
#include <vector>

class Solution
{
  public:
    int
    searchInsert (std::vector<int> &nums, int target)
    {
        return static_cast<int> (std::distance (
            nums.begin (),
            std::lower_bound (nums.begin (), nums.end (), target)));
    }
};

int
main ()
{
    return 0;
}
