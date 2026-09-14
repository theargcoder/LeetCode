#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> cyclicShift(const int &n, const std::vector<std::vector<int>> &grid, const std::vector<int> &rowShift, const std::vector<int> &colShift)
  {
    std::vector<std::vector<int>> res;

    const size_t size = grid.size();
    std::vector<int> tmp;
    tmp.reserve(2 * size);

    for(size_t i = 0; i < size; i++)
    {
      tmp = grid[i];
      tmp.insert(tmp.end(), grid[i].begin(), grid[i].end());

      res.emplace_back(tmp.begin() + rowShift[i], tmp.begin() + rowShift[i] + size);
    }

    for(size_t i = 0; i < size; i++)
    {
      tmp.clear();
      for(size_t j = 0; j < size; j++)
      {
        tmp.push_back(res[j][i]);
      }
      for(size_t j = 0; j < size; j++)
      {
        tmp.push_back(res[j][i]);
      }

      for(size_t j = colShift[i], k = 0; j < size + colShift[i]; j++, k++)
      {
        res[k][i] = tmp[j];
      }
    }

    return res;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.cyclicShift(2, { { 1, 2 }, { 3, 4 } }, { 1, 0 }, { 0, 1 });

  return 0;
}
