#include <unordered_map>
#include <vector>

class Solution
{
 public:
   int
   singleNumber (std::vector<int> &nums)
   {
      const int n = nums.size ();

      std::unordered_map<int, int> map;

      for (int i = 0; i < n; i++)
         {
            if (map.count (nums[i]))
               map[nums[i]]++;
            else
               map[nums[i]] = 1;
         }

      for (int i = 0; i < n; i++)
         {
            if (map[nums[i]] == 1)
               return nums[i];
         }

      return nums.back (); // impossible per the problem statement
   }
};
