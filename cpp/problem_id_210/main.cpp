#include <array>
#include <vector>

#define NUM_COURSES 2000

// 7 ms solution
class Solution
{
private:
  std::vector<int> to_ret;

  std::array<short, NUM_COURSES + 1> degree;
  std::array<std::vector<short>, NUM_COURSES + 1> num_depe, levels;
  std::array<bool, NUM_COURSES + 1> used, visited, recursed;

public:
  std::vector<int> findOrder(const int &numCourses, const std::vector<std::vector<int>> &prerequisites)
  {
    const auto size = prerequisites.size();
    degree.fill(-1);
    levels.fill({});
    to_ret.clear();
    to_ret.reserve(NUM_COURSES);

    if(size == 0)
    {
      for(int i = 0; i < numCourses; i++)
      {
        to_ret.push_back(i);
      }
      return to_ret;
    }
    else if(canFinish(numCourses, prerequisites))
    {
      grade(numCourses);
      traverse(numCourses);
      for(const auto &level : levels)
      {
        for(const int &j : level)
        {
          to_ret.push_back(j);
        }
      }
      for(unsigned i = 0; i <= NUM_COURSES && i < numCourses; i++)
      {
        if(!used[i])
        {
          to_ret.push_back(i);
        }
      }
      return to_ret;
    }
    else
    {
      return {};
    }
  }

private:
  void traverse(const int &numCourses)
  {
    for(int i = 0; i < numCourses; i++)
    {
      if(!used[i])
      {
        continue;
      }

      const auto deg = degree[i];

      levels[deg].push_back(i);
    }
  }

  void grade(const int &numCourses)
  {
    for(int i = 0; i <= numCourses; i++)
    {
      if(!used[i])
      {
        continue;
      }
      degree[i] = dfs_grade(i);
    }
  }

  int dfs_grade(const int num)
  {
    if(degree[num] != -1)
    {
      return degree[num];
    }

    int deg = 0;

    for(const auto &i : num_depe[num])
    {
      deg = std::max(deg, dfs_grade(i) + 1);
    }

    degree[num] = deg;
    return deg;
  }

  bool canFinish(const int &numCourses, const std::vector<std::vector<int>> &prerequisites)
  {
    const unsigned size = prerequisites.size();

    if(size == 0)
    {
      return true;
    }

    num_depe.fill({});
    used.fill(false);

    for(const auto &vec : prerequisites)
    {
      const int curr_val = vec[0];
      const int prerequisit = vec[1];

      if(curr_val == prerequisit)
      {
        return false;
      }

      used[curr_val] = used[prerequisit] = true;

      num_depe[curr_val].push_back(prerequisit);
    }

    visited.fill(false);
    recursed.fill(false);

    for(int i = 0; i <= numCourses; i++)
    {
      if(!used[i])
      {
        continue;
      }
      if(!visited[i] && find_loops(i))
      {
        return false;
      }
    }

    return true;
  }

  bool find_loops(const int &num)
  {
    if(recursed[num])
    {
      return true; // cycle
    }
    if(visited[num])
    {
      return false; // no cycle
    }

    visited[num] = true;
    recursed[num] = true;

    for(const auto &num : num_depe[num])
    {
      if(find_loops(num))
      {
        return true;
      }
    }

    recursed[num] = false;
    return false;
  }
};
