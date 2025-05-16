#include <vector>

class Solution
{
 public:
   bool
   search (std::vector<int> &nums, int target)
   {
      int left = 0, right = nums.size () - 1;
      if (right == 0)
         return nums[0] == target;

      if (target == nums[left] || target == nums[right])
         return true;
      else if (target < nums[left])
         {
            while (right > -1 && target < nums[right])
               right--;
            if (right == -1)
               return false;
            return target == nums[right];
         }
      else
         {
            while (left < nums.size () && target > nums[left])
               left++;
            if (left == nums.size ())
               return false;
            return target == nums[left];
         }
   }
};
