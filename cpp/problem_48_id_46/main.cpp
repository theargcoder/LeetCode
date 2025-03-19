#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

/*
class Solution
{
 public:
   std::vector<std::vector<int> >
   permute (std::vector<int> &nums)
   {
      std::vector<std::vector<int> > to_ret = { nums };
      if (nums.size () == 1)
         return to_ret;
      if (nums.size () == 2)
         {
            auto tmp = nums;
            std::swap (tmp.back (), tmp.front ());
            to_ret.push_back (tmp);
            return to_ret;
         }
      const int size = nums.size () - 1;
      int remaining = 1;
      for (int i = size + 1; i >= 2; i--)
         {
            remaining *= i;
         }
      std::cout << nums.size () << "! = " << remaining << '\n';
      loop (to_ret, to_ret.back (), size, size, remaining);
      return to_ret;
   }

 private:
   void
   loop (std::vector<std::vector<int> > &to_ret, std::vector<int> &nums,
         int fixed, const int &size, int &remaining)
   {
      if (remaining == 1)
         return;
      remaining--;
      std::vector<int> cpy = nums;
      std::swap (cpy[fixed], cpy[fixed - 1]);
      to_ret.push_back (cpy);
      if (fixed == 1)
         {
            loop (to_ret, to_ret.back (), size, size, remaining);
         }
      else
         {
            loop (to_ret, to_ret.back (), fixed - 1, size, remaining);
         }
   }
};
*/
class Solution
{
 public:
   std::vector<std::vector<int> >
   permute (std::vector<int> &nums)
   {
      std::vector<std::vector<int> > to_ret = { nums };
      if (nums.size () == 1)
         return to_ret;
      if (nums.size () == 2)
         {
            auto tmp = nums;
            std::swap (tmp.back (), tmp.front ());
            to_ret.push_back (tmp);
            return to_ret;
         }
      const int size = nums.size ();
      int remaining = 1;
      for (int i = size; i >= 2; i--)
         {
            remaining *= i;
         }
      for (; remaining > 1; remaining--)
         {
            std::vector<int> cpy = to_ret.back ();
            nextPermutation (cpy, size);
            to_ret.push_back (cpy);
         }
      return to_ret;
   }

 private:
   void
   nextPermutation (std::vector<int> &nums, const int &size)
   {
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
