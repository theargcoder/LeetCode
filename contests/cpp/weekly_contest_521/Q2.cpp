#include <climits>
#include <vector>

class Solution
{
private:
  struct m_type
  {
    int num, count;
  };

  m_type count_ignore(const std::vector<int> &nums, const int &IGNORE)
  {
    m_type ct = { .num = INT_MIN, .count = 0 };
    for(const auto &num : nums)
    {
      if(num == IGNORE)
      {
        continue;
      }
      else if(ct.num == INT_MIN)
      {
        ct.num = num;
        ct.count = 1;
      }
      else if(num == ct.num)
      {
        ct.count++;
      }
      else if(ct.count >= 0)
      {
        ct.count--;
      }
      else
      {
        ct.count = 1;
        ct.num = num;
      }
    }
    return ct;
  }

public:
  int maxEqualAdjacentPairs(const std::vector<int> &nums)
  {
    const size_t size = nums.size();

    const auto ct_1 = count_ignore(nums, INT_MIN);
    const auto ct_2 = count_ignore(nums, ct_1.num);

    if(ct_2.num == INT_MIN)
    {
      return static_cast<int>(nums.size()) - 1;
    }
    else
    {
      auto nums_cpy = nums;

      for(auto &num : nums_cpy)
      {
        if(num == ct_1.num)
        {
          num = ct_2.num;
        }
      }

      int max = 0;
      for(size_t i = 1; i < size; i++)
      {
        size_t j = i;
        for(; i < size && nums_cpy[i] == nums_cpy[i - 1]; i++)
        {
        }
        max = std::max(max, static_cast<int>(i - j));
      }

      return max;
    }
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.maxEqualAdjacentPairs({ 1, 2, 3, 2 });
  const auto res_2 = sol.maxEqualAdjacentPairs({ 9, 5, 10 });
  const auto res_3 = sol.maxEqualAdjacentPairs({ 8, 8, 4, 5 });

  return 0;
}
