#include <climits>
#include <vector>

class Solution
{
public:
  long long maxValue(const std::vector<int> &nums)
  {
    const size_t N = nums.size();
    std::vector<int> rtd(N + 1); // for swap

    bool plus = false;
    long long in_sum = nums[0];
    for(size_t i = 1; i < N; i++)
    {
      in_sum += (plus) ? nums[i] : -nums[i];
      plus = !plus;
    }

    size_t min_loc = 0, max_loc = 0;
    int min = INT_MAX, max = INT_MIN;
    for(size_t i = 0; i < N; i++)
    {
      if(nums[i] > max)
      {
        max = nums[i];
        max_loc = i;
      }

      if(nums[i] < min)
      {
        min = nums[i];
        min_loc = i;
      }
    }

    size_t smallest_loc = std::min(min_loc, max_loc);
    size_t bigest_loc = std::max(min_loc, max_loc);

    for(size_t i = 0; i < smallest_loc; i++)
    {
      rtd[i] = nums[i];
    }

    // skip the smallest since is LEFT ROTATION
    for(size_t i = smallest_loc; i < bigest_loc; i++)
    {
      rtd[i] = nums[i + 1];
    }
    rtd[bigest_loc] = nums[smallest_loc];
    for(size_t i = bigest_loc + 1; i < N; i++)
    {
      rtd[i] = nums[i];
    }

    plus = false;
    long long other_sum = rtd[0];
    for(size_t i = 1; i < N; i++)
    {
      other_sum += (plus) ? rtd[i] : -rtd[i];
      plus = !plus;
    }

    return std::max(in_sum, other_sum);
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const int res_1 = sol.maxValue({ 1, 5, 2 });

  return 0;
}
