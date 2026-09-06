#include <vector>

class Solution
{
public:
  int countGoodRotations(const std::vector<int> &nums)
  {
    std::vector<int> n_cpy;
    n_cpy.reserve(nums.size() * 2);

    for(const auto &i : nums)
    {
      n_cpy.push_back(i);
    }
    for(const auto &i : nums)
    {
      n_cpy.push_back(i);
    }

    size_t midpt = nums.size() / 2;

    int cycles = 0;
    long l_ct = 0, r_ct = 0;
    for(size_t k = 0; k < midpt; k++)
    {
      l_ct += n_cpy[k];
    }
    for(size_t k = midpt; k < nums.size(); k++)
    {
      r_ct += n_cpy[k];
    }
    if(l_ct > r_ct)
    {
      cycles++;
    }
    for(size_t i = 0, j = nums.size(); i < nums.size() - 1; i++)
    {
      l_ct -= n_cpy[i];
      r_ct -= n_cpy[midpt];
      l_ct += n_cpy[midpt];
      r_ct += n_cpy[j];
      j++, midpt++;

      if(l_ct > r_ct)
      {
        cycles++;
      }
    }

    return cycles;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  sol.countGoodRotations({ 1, 2, 3, 4, 5, 6 });
  sol.countGoodRotations({ 1, 2, 1, 2 });

  return 0;
}
