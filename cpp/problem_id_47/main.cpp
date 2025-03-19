#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

// first sumbition SLOW but working and it passed
/*
class Solution
{
 public:
   std::vector<std::vector<int> >
   permuteUnique (std::vector<int> &nums)
   {
      std::set<std::vector<int> > ans;
      helper (ans, nums, 0);
      std::vector<std::vector<int> > to_ret;
      for (auto &vec : ans)
         {
            to_ret.push_back (vec);
         }
      return to_ret;
   }

 private:
   void
   helper (std::set<std::vector<int> > &ans, std::vector<int> &nums, int index)
   {
      if (index == nums.size ())
         {
            ans.insert (nums);
            return;
         }
      for (int i = index; i < nums.size (); i++)
         {
            std::swap (nums[i], nums[index]);
            helper (ans, nums, index + 1);
            std::swap (nums[i], nums[index]);
         }
   }
};
*/

// a lot faster, works very very similarly to the slow one

class Solution
{
 public:
   std::vector<std::vector<int> >
   permuteUnique (std::vector<int> &nums)
   {
      std::sort (nums.begin (), nums.end ());
      std::vector<std::vector<int> > ans;
      helper (ans, nums, 0);
      return ans;
   }

 private:
   void
   helper (std::vector<std::vector<int> > &ans, std::vector<int> &nums,
           int index)
   {
      if (index == nums.size ())
         {
            ans.push_back (nums);
            return;
         }
      for (int i = index; i < nums.size (); i++)
         {
            if (i != index && nums[i] == nums[index])
               continue;
            std::swap (nums[i], nums[index]);
            helper (ans, nums, index + 1);
         }
      for (int i = nums.size () - 1; i > index; i--)
         {
            std::swap (nums[index], nums[i]);
         }
   }
};
