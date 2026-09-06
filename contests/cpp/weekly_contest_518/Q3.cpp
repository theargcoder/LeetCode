#include <vector>

struct node
{
  int pos, speed;
};

class Solution
{
public:
  int countGroups(const std::vector<int> &position, const std::vector<int> &speed, int distance)
  {
    std::vector<node> inc_dist, inc_speed;

    inc_dist.reserve(position.size());
    inc_speed.reserve(position.size());
    inc_dist.push_back(node{ .pos = position[0], .speed = speed[0] });
    for(size_t i = 1; i < position.size(); i++)
    {
      while(!inc_dist.empty() && position[i] - inc_dist.back().pos <= distance)
      {
        inc_dist.pop_back();
      }
      inc_dist.push_back(node{ .pos = position[i], .speed = speed[i] });
    }

    inc_speed.push_back(inc_dist.front());
    for(size_t i = 1; i < inc_dist.size(); i++)
    {
      while(!inc_speed.empty() && inc_speed.back().speed > inc_dist[i].speed)
      {
        inc_speed.pop_back();
      }
      inc_speed.push_back(inc_dist[i]);
    }

    return inc_speed.size();
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.countGroups({ 61, 640, 653, 863 }, { 615, 629, 464, 739 }, 222);

  return 0;
}
