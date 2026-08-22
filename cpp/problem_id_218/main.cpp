#include <algorithm>
#include <set>
#include <vector>

struct node
{
  int x, height;

  node() = default;
  node(const int &_x, const int &_height) : x(_x), height(_height) {};
};

class Solution
{
private:
  enum meaning : char
  {
    START = 0,
    END = 1,
    HEIGHT = 2
  };

public:
  std::vector<std::vector<int>> getSkyline(const std::vector<std::vector<int>> &buildings)
  {
    std::vector<std::vector<int>> to_ret;
    std::multiset<int> pq;

    std::vector<node> ordered;

    for(const auto &building : buildings)
    {
      ordered.emplace_back(building[meaning::START], -building[meaning::HEIGHT]);
      ordered.emplace_back(building[meaning::END], building[meaning::HEIGHT]);
    }

    std::ranges::sort(ordered,
                      [](const auto &a, const auto &b)
                      {
                        if(a.x != b.x)
                        {
                          return a.x < b.x;
                        }
                        else
                        {
                          return a.height < b.height;
                        }
                      });

    int curr_max = 0;
    pq.insert(0);
    for(const auto &nd : ordered)
    {
      if(nd.height > 0)
      {
        pq.erase(pq.find(nd.height));
      }
      else
      {
        pq.insert(-nd.height);
      }

      auto it = pq.rbegin();
      if(*it != curr_max)
      {
        curr_max = *it;
        to_ret.push_back({ nd.x, curr_max });
      }
    }

    return to_ret;
  }
};
