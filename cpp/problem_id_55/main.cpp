
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
 public:
   bool
   canJump (std::vector<int> &nums)
   {
      int i = 0;

      for (int reach = 0; i < nums.size () && i <= reach; ++i)
         reach = std::max (reach, i + nums[i]);

      return i == nums.size ();
   }
};
