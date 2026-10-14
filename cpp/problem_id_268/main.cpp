#include <algorithm>
#include <numeric>
#include <vector>

#pragma GCC optimizations("03")

class Solution
{
public:
  int missingNumber(const std::vector<int> &nums)
  {
    const int size = static_cast<int>(nums.size());

    const int expected_sum = ((size + 1) * size) / 2;

#pragma omp simd reduction(+ : sum)
    const int actual_sum = std::reduce(nums.begin(), nums.end(), 0);

    return expected_sum - actual_sum;
  }
};
