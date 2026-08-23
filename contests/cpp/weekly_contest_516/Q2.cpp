#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> findDisappearedNumbers(const std::vector<int> &nums, const int &lower, const int &upper)
  {
    std::vector<std::vector<int>> to_ret;
    std::vector<bool> map(100'001, false);

    for(const auto &i : nums)
    {
      map[i] = true;
    }

    int left = lower, right = upper;

    while(left <= right)
    {
      int pvt_1 = left;
      while(left <= right && !map[left])
      {
        left++;
      }
      if(left - 1 >= pvt_1)
      {
        to_ret.push_back({ pvt_1, left - 1 });
      }
      left++;
    }

    return to_ret;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  sol.findDisappearedNumbers({ 3, 9, 7 }, 1, 12);

  return 0;
}
