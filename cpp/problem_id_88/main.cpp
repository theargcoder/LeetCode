#include <algorithm>
#include <vector>

// O (2 * (m+n)) Solution
class Solution
{
 public:
   void
   merge (std::vector<int> &nums1, const int m, std::vector<int> &nums2,
          const int n)
   {
      std::vector<int> full_sorted (m + n, 0);
      int x = 0, y = 0;

      while (x < m && y < n)
         {
            if (nums1[x] == nums2[y])
               {
                  full_sorted[x + y] = nums1[x];
                  x++;
                  full_sorted[x + y] = nums2[y];
                  y++;
               }
            else if (nums1[x] < nums2[y])
               {
                  full_sorted[x + y] = nums1[x];
                  x++;
               }
            else
               {
                  full_sorted[x + y] = nums2[y];
                  y++;
               }
         }

      if (x != m && y == n)
         {
            while (x < m)
               {
                  full_sorted[x + y] = nums1[x];
                  x++;
               }
         }
      else if (x == m && y != n)
         {
            while (y < n)
               {
                  full_sorted[x + y] = nums2[y];
                  y++;
               }
         }

      for (int i = 0; i < full_sorted.size (); i++)
         {
            nums1[i] = full_sorted[i];
         }

      return;
   }
};

// cheating
/*
class Solution
{
 public:
   void
   merge (std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
   {
      int i = m - 1;
      int j = n - 1;
      int k = m + n - 1;

      while (i >= 0 && j >= 0)
         {
            if (nums1[i] > nums2[j])
               nums1[k--] = nums1[i--];
            else
               nums1[k--] = nums2[j--];
         }

      while (j >= 0)
         nums1[k--] = nums2[j--];
   }
};
*/
