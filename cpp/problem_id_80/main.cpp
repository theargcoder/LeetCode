#include <vector>

class Solution
{
 public:
   int
   removeDuplicates (std::vector<int> &nums)
   {
      const int size = nums.size ();

      int ct = 1;
      int i = 1, j = 1;

      while (j < size)
         {
            if (ct == 2 && nums[i - 1] == nums[j])
               {
                  while (j < size && nums[j] == nums[i - 1])
                     j++;
                  if (j >= size)
                     return i;
                  std::swap (nums[i], nums[j]);
                  j++;
                  ct = 1;
               }
            else
               {
                  if (nums[j] == nums[i - 1])
                     ct++;
                  else
                     ct = 1;

                  std::swap (nums[i], nums[j]);
                  j++;
               }
            i++;
         }
      return i;
   }
};
