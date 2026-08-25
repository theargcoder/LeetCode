#include <algorithm>
#include <climits>
#include <map>
#include <vector>

class Solution
{
  struct node
  {
    int min_index_diff = INT_MAX;

    std::vector<int> indexes;

    node() = default;

    explicit node(const int &idx)
    {
      indexes.push_back(idx);
    };
  };

public:
  bool containsNearbyAlmostDuplicate(const std::vector<int> &nums, const int &indexDiff, const int &valueDiff)
  {
    if(indexDiff == 0)
    {
      return false;
    }

    const int size = nums.size();
    std::map<int, node> freq;

    for(int i = 0; i < size; i++)
    {
      freq[nums[i]].indexes.push_back(i);
    }

    for(auto &val_node : freq)
    {
      auto &diff = val_node.second.min_index_diff;
      auto &vec = val_node.second.indexes;
      if(vec.size() > 1)
      {
        for(size_t i = 1; i < vec.size(); i++)
        {
          diff = std::min(diff, vec[i] - vec[i - 1]);
        }
      }
    }

    for(const auto &A : freq)
    {
      const auto &A_min_diff = A.second.min_index_diff;
      if(A_min_diff <= indexDiff) // same value but diff valid means EARLY return
      {
        return true;
      }
    }

    for(auto A = freq.begin(), B = A; A != freq.end(); A++)
    {
      const auto &A_value = A->first;
      B = freq.upper_bound(A_value + valueDiff); // 1 MORE from LAST VLAID node

      auto it_A = A, it_B = std::next(A);

      while(it_B != B)
      {
        const auto &it_A_vec = it_A->second.indexes;
        const auto &it_B_vec = it_B->second.indexes;
        for(const auto &i : it_A_vec)
        {
          auto j_it = std::ranges::lower_bound(it_B_vec, i - indexDiff);
          for(; j_it != it_B_vec.end(); j_it++)
          {
            if(std::abs(i - *j_it) <= indexDiff)
            {
              return true;
            }
            else
            {
              break;
            }
          }
        }
        it_B = std::next(it_B);
      }
    }

    return false;
  }
};
