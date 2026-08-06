#include <unordered_map>
#include <unordered_set>
#include <vector>

struct node
{
  int val;

  std::vector<node *> dependencies;

  explicit node(int n_val, node *prereq) : val(n_val), dependencies{ prereq } {};
  explicit node(int n_val) : val(n_val) {};
};

class Solution
{
private:
  std::unordered_map<int, node *> memo;

public:
  bool canFinish(const int &numCourses, const std::vector<std::vector<int>> &prerequisites)
  {
    const unsigned size = prerequisites.size();

    if(size == 0)
    {
      return true;
    }

    const int curr_val = prerequisites[0][0];
    const int prerequisit = prerequisites[0][1];

    node *dep = new node(prerequisit);
    node *head = new node(curr_val, dep);

    memo[curr_val] = head;
    memo[prerequisit] = dep;

    if(!build_graph(prerequisites, size, 1))
    {
      return false;
    }

    std::unordered_set<node *> visited, recursed;

    for(auto [num, ptr] : memo)
    {
      if(!visited.count(ptr) && find_loops(visited, recursed, (node *)ptr))
      {
        return false;
      }
    }

    return true;
  }

private:
  bool find_loops(std::unordered_set<node *> &visited, std::unordered_set<node *> &recursed, node *head)
  {
    if(recursed.count(head))
    {
      return true; // cycle
    }
    if(visited.count(head))
    {
      return false; // no cycle
    }

    visited.insert(head);
    recursed.insert(head);

    for(const auto ptr : head->dependencies)
    {
      if(find_loops(visited, recursed, ptr))
      {
        return true;
      }
    }

    recursed.erase(head);
    return false;
  }

  bool build_graph(const std::vector<std::vector<int>> &prereq, const unsigned &size, const int i)
  {
    if(i >= size)
    {
      return true;
    }

    const int curr_val = prereq[i][0];
    const int prereq_val = prereq[i][1];

    if(curr_val == prereq_val)
    {
      return false;
    }

    const bool curr_exists = memo.count(curr_val);
    const bool pre_exists = memo.count(prereq_val);

    if(curr_exists && pre_exists)
    {
      node *head = reinterpret_cast<node *>(memo[curr_val]);
      node *prereq = reinterpret_cast<node *>(memo[prereq_val]);

      head->dependencies.push_back(prereq);
    }
    else if(curr_exists && !pre_exists)
    {
      node *dep = new node(prereq_val);
      node *head = reinterpret_cast<node *>(memo[curr_val]);

      head->dependencies.push_back(dep);

      memo[prereq_val] = dep;
    }
    else if(!curr_exists && pre_exists)
    {
      node *prereq = reinterpret_cast<node *>(memo[prereq_val]);
      node *head = new node(curr_val, prereq);

      memo[curr_val] = head;
    }
    else if(!curr_exists && !pre_exists)
    {
      node *dep = new node(prereq_val);
      node *head = new node(curr_val, dep);

      memo[curr_val] = head;
      memo[prereq_val] = dep;
    }

    return build_graph(prereq, size, i + 1);
  }
};
