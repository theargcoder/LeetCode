#include <array>
#include <vector>

template <size_t N>
static void get_spf(std::array<int, N> &spf)
{
  static bool once = true;
  if(once)
  {
    for(int i = 2; i < N; i++)
    {
      if(spf[i] != 0)
      {
        continue;
      }

      for(int j = i; j < N; j += i)
      {
        spf[j] = i;
      }
    }

    once = false;
  }
}

constexpr size_t MAX_SIZE = 100'003;
static std::array<int, MAX_SIZE> spf;
static std::array<int, MAX_SIZE> memo;

class Solution
{
public:
  int longestSubarray(const std::vector<int> &nums, const int &k)
  {
    get_spf(spf);
    memo.fill(0);

    const size_t size = nums.size();

    int l = 0, r = 0, diff = 0, max = 0;

    for(; r < size; r++)
    {
      {
        int curr = nums[r];
        while(curr > 1)
        {
          const int prime = spf[curr];
          if(memo[prime] == 0)
          {
            diff++;
          }
          memo[prime]++;

          while(curr % prime == 0)
          {
            curr /= prime;
          }
        }
      }

      while(diff > k)
      {
        int curr = nums[l];
        while(curr > 1)
        {
          const int prime = spf[curr];
          memo[prime]--;
          if(memo[prime] == 0)
          {
            diff--;
          }
          while(curr % prime == 0)
          {
            curr /= prime;
          }
        }
        l++;
      }
      max = std::max(max, r - l + 1);
    }

    return max;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  sol.longestSubarray({ 7, 6, 10, 12, 11 }, 3);
  //  sol.longestSubarray({ 6, 10, 15 }, 2);
  // sol.longestSubarray({ 3 }, 22);

  return 0;
}
