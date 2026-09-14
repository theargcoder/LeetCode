#include <algorithm>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

struct PALI
{
public:
  static std::vector<long long> even_pal, odd_pal;

  PALI()
  {
    init_palis();
  }

  void init_palis()
  {
    if(even_pal.empty())
    {
      even_pal.reserve(199998 / 2);
      odd_pal.reserve(199998 / 2);

      constexpr auto max_val = 10000000000LL;

      for(int half_len = 1; half_len <= 5; ++half_len)
      {
        int64_t start = 1;
        for(int i = 1; i < half_len; ++i)
        {
          start *= 10;
        }
        const int64_t end = start * 10;

        for(int64_t i = start; i < end; ++i)
        {
          std::string s = std::to_string(i);
          std::string rev = s;
          std::reverse(rev.begin(), rev.end());

          std::string odd_p = s + rev.substr(1);
          long long val_odd = std::stoll(odd_p);
          if(val_odd <= max_val)
          {
            if((val_odd & 0b01) == 0)
            {
              even_pal.push_back(val_odd);
            }
            else
            {
              odd_pal.push_back(val_odd);
            }
          }

          std::string even_p = s + rev;
          long long val_even = std::stoll(even_p);
          if(val_even <= max_val)
          {
            if((val_even & 0b01) == 0)
            {
              even_pal.push_back(val_even);
            }
            else
            {
              odd_pal.push_back(val_even);
            }
          }
        }
      }

      std::sort(even_pal.begin(), even_pal.end());
      std::sort(odd_pal.begin(), odd_pal.end());
    }
  }
};

std::vector<long long> PALI::odd_pal{};
std::vector<long long> PALI::even_pal{};

class Solution
{
  static const PALI pal;

public:
  long long minOperations(const std::vector<int> &nums)
  {
    const size_t size = nums.size();
    uint64_t res = 0;

    for(size_t i = 0; i < size; i++)
    {
      const bool even = (nums[i] & 0b01) == 0;

      auto lower = pal.even_pal.begin(), higer = pal.even_pal.begin();
      if(even)
      {
        lower = std::lower_bound(pal.even_pal.begin(), pal.even_pal.end(), nums[i]);
        lower = (*lower == nums[i]) ? lower : lower - 1;
        higer = std::upper_bound(pal.even_pal.begin(), pal.even_pal.end(), nums[i]);
      }
      else
      {
        lower = std::lower_bound(pal.odd_pal.begin(), pal.odd_pal.end(), nums[i]);
        lower = (*lower == nums[i]) ? lower : lower - 1;
        higer = std::upper_bound(pal.odd_pal.begin(), pal.odd_pal.end(), nums[i]);
      }

      const auto dist_lo = (nums[i] - *lower) / 2;
      const auto dist_hi = (*higer - nums[i]) / 2;

      res += std::min(dist_lo, dist_hi);
    }

    return res;
  }
};

PALI const Solution::pal = PALI{};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.minOperations({ 10, 12, 14, 16 });
  const auto res_2 = sol.minOperations({ 9, 10, 11, 10 });
  const auto res_3 = sol.minOperations({ 125 });
  const auto res_4 = sol.minOperations({ 10005 });
  const auto res_5 = sol.minOperations({ 30001 });
  const auto res_6 = sol.minOperations({ 32171 });

  return 0;
}
