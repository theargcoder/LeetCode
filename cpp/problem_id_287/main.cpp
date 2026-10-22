#include <vector>

static std::vector<bool> count(static_cast<size_t>(10e5 + 2), false);

class Solution
{
public:
  int findDuplicate(std::vector<int> &nums)
  {
    std::fill(count.begin(), count.end(), false);

    for(const auto &i : nums)
    {
      if(count[i])
        return i;
      else
        count[i] = true;
    }

    return 0;
  }
};
