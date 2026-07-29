#include <unordered_map>
#include <vector>

class Solution
{
public:
  bool isHappy(const int n)
  {
    std::unordered_map<int, bool> visited;

    int current = n;
    std::vector<int> stack(10, 0);

    while(current && current != 1)
    {
      if(visited.count(current)) // visiting a number 2 times == loop
      {
        return false;
      }
      visited[current] = true;

      while(current)
      {
        const unsigned rem = current % 10;
        const unsigned div = current / 10;
        stack.push_back(rem);
        current = div;
      }

      while(!stack.empty())
      {
        current += stack.back() * stack.back();
        stack.pop_back();
      }
    }

    return current == 1;
  }
};
