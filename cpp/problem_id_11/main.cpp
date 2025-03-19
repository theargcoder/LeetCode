#include <iostream>
#include <vector>

// initial solution complexitiy is: O(N^2)
/*
class Solution
{
  public:
    int
    maxArea (std::vector<int> &height)
    {
        int max_water = 0;
        int size = height.size ();

        int min = 0, max = 0;

        for (int i = 0; i < size; i++)
            {
                min = height[i];
                for (int j = size - 1; j > i; j--)
                    {
                        int count = j - i;
                        int water = count * std::min (min, height[j]);
                        if (water > max_water)
                            max_water = water;
                    }
            }
        return max_water;
    }
};
*/

class Solution
{
  public:
    int
    maxArea (std::vector<int> &height)
    {
        int max_water = 0;
        int size = height.size ();

        int i = 0, j = size - 1;
        int min = 0, max = 0;

        while (i < j)
            {
                min = std::min (height[i], height[j]);
                int count = j - i;
                max_water = std::max (max_water, count * min);
                if (height[i] < height[j])
                    i++;
                else
                    j--;
            }
        return max_water;
    }
};

int
main ()
{
    Solution solution;

    std::vector<std::vector<int> > test_cases
        = { { 1, 8, 6, 2, 5, 4, 8, 3, 7 },
            { 1, 1 },
            { 4, 3, 2, 1, 4 },
            { 1, 2, 1 },
            { 2, 3, 10, 5, 7, 8, 9 },
            { 1, 2, 4, 3 },
            { 2, 3, 4, 5, 18, 17, 6 },
            { 1, 3, 2, 5, 25, 24, 5 },
            { 3, 9, 3, 4, 7, 2, 12, 6 },
            { 10, 20, 30, 40, 50 },
            { 10, 10, 10, 10 },
            { 5, 5, 5, 5, 5 },
            { 100, 200, 300, 400 },
            { 9, 9, 9, 1, 1, 9, 9, 9 },
            { 2, 1, 1, 1, 1, 2 },
            { 1, 2, 1, 3, 1, 2 },
            { 6, 5, 4, 3, 2, 1 },
            { 7, 6, 5, 4, 3, 2 },
            { 1, 10, 1, 10, 1, 10 },
            { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
            { 1, 3, 2, 5, 4, 8 },
            { 8, 1, 1, 8, 1, 1, 8 },
            { 1, 2 },
            { 2, 2, 2, 2, 2 },
            { 1, 2, 3, 4, 3, 2, 1 },
            { 1, 1, 1, 50, 1, 1, 1 },
            { 10, 5, 20, 5, 10, 5, 20 },
            { 1, 2, 100, 2, 1 },
            { 9, 7, 5, 3, 1 },
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } };

    std::vector<int> expected_results
        = { 49, 1, 16, 2,  36, 4,  17, 24, 45, 60, 30, 20, 400, 63, 10,
            8,  9, 12, 40, 20, 12, 48, 1,  8,  8,  6,  80, 4,   10, 25 };

    for (size_t i = 0; i < test_cases.size (); ++i)
        {
            int result = solution.maxArea (test_cases[i]);
            std::cout << "Test Case " << i + 1 << ": "
                      << (result == expected_results[i] ? "Passed" : "Failed")
                      << " (Output: " << result
                      << ", Expected: " << expected_results[i] << ")\n";
        }

    return 0;
}
