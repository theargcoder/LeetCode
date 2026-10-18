#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
  int minSelection(std::vector<std::vector<int>> &availableIntervals, std::vector<std::vector<int>> &targetIntervals)
  {
    std::ranges::sort(availableIntervals);
    std::ranges::sort(targetIntervals);

    const size_t AVAILABLE_SIZE = availableIntervals.size(), TARGET_SIZE = targetIntervals.size();

    size_t a = 0, t = 0;
    int count = 0, max = -10e7;
    int to_cover = targetIntervals[0][0];

    while(t < TARGET_SIZE)
    {
      // skip duplicated starts since we want largest inteval
      const auto prev_max = max;
      for(; a < AVAILABLE_SIZE && availableIntervals[a][0] <= to_cover; a++)
      {
        max = std::max(max, availableIntervals[a][1]);
      }

      if(prev_max == max) // we dont have that range
      {
        return -1;
      }

      count++;

      for(; t < TARGET_SIZE && max >= targetIntervals[t][1]; t++) // we covered that range
      {
      }

      if(t == TARGET_SIZE)
      {
        return count;
      }

      to_cover = std::max(max, targetIntervals[t][1]);
    }

    return count;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  {
    std::vector<std::vector<int>> available = { { 1, 4 }, { 1, 7 }, { 3, 9 }, { 5, 10 }, { 10, 15 } };
    std::vector<std::vector<int>> target = { { 1, 3 }, { 2, 5 }, { 7, 8 }, { 10, 13 }, { 11, 15 }, { 12, 13 } };
    const auto res_1 = sol.minSelection(available, target);
    const bool banna = false;
    std::cout << banna;
  }

  {
    std::vector<std::vector<int>> available = { { 1, 2 }, { 3, 4 } };
    std::vector<std::vector<int>> target = { { 1, 4 } };
    const auto res_1 = sol.minSelection(available, target);
    const bool banna = false;
    std::cout << banna;
  }

  {
    std::vector<std::vector<int>> available = { { 4, 6 }, { 1, 4 }, { 2, 5 } };
    std::vector<std::vector<int>> target = { { 3, 4 }, { 2, 5 }, { 6, 7 } };
    const auto res_1 = sol.minSelection(available, target);
    const bool banna = false;
    std::cout << banna;
  }

  {
    std::vector<std::vector<int>> available = { { 3, 29 }, { 2, 2 }, { 30, 30 } };
    std::vector<std::vector<int>> target = { { 3, 9 },   { 2, 2 },   { 28, 28 }, { 7, 7 },   { 20, 25 }, { 5, 28 },  { 29, 29 }, { 16, 16 }, { 10, 10 }, { 16, 29 },
                                             { 23, 23 }, { 20, 20 }, { 12, 12 }, { 11, 11 }, { 26, 26 }, { 30, 30 }, { 3, 3 },   { 13, 13 }, { 21, 21 } };
    const auto res_1 = sol.minSelection(available, target);
    const bool banna = false;
    std::cout << banna;
  }

  {
    std::vector<std::vector<int>> available = { { 2, 8 }, { 5, 15 }, { 4, 25 }, { 7, 23 }, { 27, 27 } };
    std::vector<std::vector<int>> target = { { 3, 3 }, { 20, 20 }, { 7, 7 }, { 10, 23 }, { 17, 17 }, { 20, 25 }, { 27, 27 }, { 10, 10 }, { 25, 25 }, { 22, 22 }, { 2, 20 } };
    const auto res_1 = sol.minSelection(available, target);
    const bool banna = false;
    std::cout << banna;
  }

  return 0;
}
