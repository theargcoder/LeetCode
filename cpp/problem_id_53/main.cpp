#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <vector>

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
///               WORKING BUT O(N^2)                      ///
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/*
class Solution
{
 public:
   int
   maxSubArray (std::vector<int> &nums)
   {
      long long SUPERSUM = 0;

      for (int i = 0; i < nums.size (); i++)
         {
            long long sum = 0;
            for (int j = i; j < nums.size (); j++)
               {
                  sum += nums[j];
                  SUPERSUM = std::max (SUPERSUM, sum);
               }
         }
      return SUPERSUM;
   }
};
*/
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

class Solution
{
 public:
   int
   maxSubArray (std::vector<int> &nums)
   {
      int max = nums[0];
      int curr = nums[0];

      for (int i = 1; i < nums.size (); i++)
         {
            curr = std::max (curr + nums[i], nums[i]);

            max = std::max (max, curr);
         }
      return max;
   }
};

int
main ()
{
   Solution sol;
   std::vector<int> arr{
      -42, 84,  -22, -12, 25,  -31, -91, -45, 19,  64,  27,  77,  76,   -79,
      9,   88,  -62, -46, 55,  -31, 40,  -26, -24, -90, -15, -25, -68,  -50,
      21,  87,  -10, 70,  74,  41,  -49, -30, -47, 26,  -50, 90,  -35,  65,
      103, 58,  -81, -73, -9,  -66, -22, -3,  39,  -57, 56,  24,  -91,  96,
      35,  -84, 6,   82,  -46, 12,  -25, -55, 38,  64,  73,  -75, -100, -77,
      -80, 17,  -1,  64,  -85, 58,  -81, -74, 19,  52,  -21, -5
   };

   std::cout << "response  = " << sol.maxSubArray (arr) << '\n';

   return 0;
}
