#include <numeric>
#include <vector>

class Solution
{
public:
  int maxValidSplits(const std::vector<int> &nums)
  {
    const size_t size = nums.size();

    std::vector<int> left_gdc(size, 0), right_gdc(size + 1, 0);

    int max = 0;

    for(size_t ignore = 0; ignore <= size; ignore++)
    {
      int splits = 0;
      for(int i = size - 1; i > 0; i--)
      {
        right_gdc[i] = (i == ignore) ? right_gdc[i + 1] : std::gcd(right_gdc[i + 1], nums[i]);
      }

      left_gdc[0] = (ignore == 0) ? 0 : nums[0];
      for(int i = 1; i < size; i++)
      {
        left_gdc[i] = (i == ignore) ? left_gdc[i - 1] : std::gcd(left_gdc[i - 1], nums[i]);
      }

      for(size_t j = 0; j < size; j++)
      {
        if(j == ignore)
        {
          continue;
        }

        if(left_gdc[j] == right_gdc[j + 1])
        {
          splits++;
        }
      }

      max = std::max(splits, max);
    }

    return max;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  sol.maxValidSplits({ 10, 30, 15, 10 });
  sol.maxValidSplits({ 12, 37, 1, 90 });

  return 0;
}
