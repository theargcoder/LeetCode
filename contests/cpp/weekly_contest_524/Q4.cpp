#include <algorithm>
#include <utility>
#include <vector>

class Solution
{
public:
  int minSelection(std::vector<std::vector<int>> &availableIntervals, std::vector<std::vector<int>> &targetIntervals)
  {
    std::sort(availableIntervals.begin(), availableIntervals.end());
    std::sort(targetIntervals.begin(), targetIntervals.end());

    const size_t available_size = availableIntervals.size();
    const size_t target_size = targetIntervals.size();

    std::vector<bool> covered(static_cast<size_t>(10e5 + 1), false);

    int count = 0;

    auto pair = std::make_pair(availableIntervals[0][0], availableIntervals[0][1]);

    size_t target_done = 1;
    size_t availables = 1;

    for(; availables < available_size; availables++)
    {
      while(availables < available_size && pair.first == availableIntervals[availables][0])
      {
        pair.second = availableIntervals[availables++][1];
      }

      while(target_done < target_size && pair.first < targetIntervals[target_done][0] && pair.second > targetIntervals[target_done][1]) // all covered
      {
        target_done++;
      }

      if(target_done >= target_size)
      {
        break;
      }

      for(unsigned i = pair.first; i <= pair.second; i++)
      {
        covered[i] = true;
      }

      count++;
    }

    for(const auto &pair : targetIntervals)
    {
      for(int i = pair[0]; i <= pair[1]; i++)
      {
        if(covered[i] == false)
        {
          return -1;
        }
      }
    }

    return count;
  }
};
