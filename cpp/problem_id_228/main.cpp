#include <string>
#include <vector>

class Solution
{
public:
  std::vector<std::string> summaryRanges(const std::vector<int> &nums)
  {
    const size_t size = nums.size();

    std::vector<std::string> res;

    res.reserve(size);

    for(size_t left = 0, right; left < size; left++)
    {
      right = left + 1;
      for(; right < size && static_cast<long>(nums[right]) - static_cast<long>(nums[right - 1]) <= 1L; right++)
      {
      }
      res.emplace_back("");
      res.back() += std::to_string(nums[left]);
      if(nums[right - 1] - nums[left] >= 1)
      {
        res.back() += "->";
        res.back() += std::to_string(nums[right - 1]);
      }
      left = right - 1;
    }
    return res;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.summaryRanges({ 0, 1, 2, 4, 5, 7 });
  const auto res_2 = sol.summaryRanges({ 0, 2, 3, 4, 6, 8, 9 });

  return 0;
}
