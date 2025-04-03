#include <algorithm>
#include <string>
#include <vector>

class Solution
{
 public:
   std::string
   getPermutation (int n, int k)
   {
      std::vector<int> permu;
      int i;
      for (i = 1; i <= n; i++)
         permu.push_back (i);

      for (; k > 1; k--)
         nextPermutation (permu);

      std::string res;
      for (i = 0; i < permu.size (); i++)
         res.push_back (permu[i] + '0');

      return res;
   }

 private:
   void
   nextPermutation (std::vector<int> &nums)
   {
      int size = nums.size ();
      if (size == 1)
         return;

      if (std::is_sorted (nums.begin (), nums.end (), std::greater<int> ()))
         {
            std::sort (nums.begin (), nums.end ());
            return;
         }

      for (auto i = nums.begin (); i != nums.end () - 1; i++)
         {
            if (std::is_sorted (i, nums.end ()))
               {
                  int to_swap_1 = 2, to_swap_2 = 1;
                  while (nums[size - to_swap_1] == nums[size - to_swap_2])
                     {
                        to_swap_1++;
                        to_swap_2++;
                        if (to_swap_1 > size)
                           return;
                     }
                  std::swap (nums[size - to_swap_1], nums[size - to_swap_2]);
                  return;
               }
            if (std::is_sorted (i, nums.end (), std::greater<int> ()))
               {
                  auto last_greater = std::lower_bound (
                      i, nums.end (), *(i - 1), std::greater<int> ());
                  std::swap (*(i - 1), *(last_greater - 1));
                  std::sort (i, nums.end ());
                  return;
               }
         }
   }
};
