#include <cstdint>
#include <string>
#include <vector>

int64_t add(const int64_t &A, const int64_t &B)
{
  return A + B;
}

int64_t sub(const int64_t &A, const int64_t &B)
{
  return A - B;
}

class Solution
{
private:
  struct node
  {
    int64_t level, value;
    char opp;
  };

public:
  int calculate(const std::string &s)
  {
    const size_t size = s.size();
    std::vector<node> stack;

    int64_t A = 0;
    char opp = '+';
    int64_t level = 0;
    for(size_t i = 0; i < size; i++)
    {
      for(; i < size && s[i] == ' '; i++)
      {
      }

      if(std::isdigit(s[i]))
      {
        A = s[i++] - '0';
        for(; i < size && std::isdigit(s[i]); i++)
        {
          A = (A * 10LL) + static_cast<int64_t>(s[i] - '0');
        }
        i--;
      }
      else if(s[i] == '(')
      {
        level++;
        // stack.push_back({ .level = level++, .value = A, .opp = opp });
      }
      else if(s[i] == ')')
      {
        stack.push_back({ .level = level, .value = A, .opp = opp });

        int j = stack.size() - 1;
        while(j >= 0 && stack[j].level == level)
        {
          j--;
        }

        j += 1, A = stack[j].value;

        for(; j < stack.size() - 1; j++)
        {
          A = (stack[j].opp == '-') ? sub(A, stack[j + 1].value) : add(A, stack[j + 1].value);
        }

        while(!stack.empty() && stack.back().level == level)
        {
          stack.pop_back();
        }

        level--;
      }
      else if(s[i] == '+')
      {
        stack.push_back({ .level = level, .value = A, .opp = '+' });
        A = 0;
      }
      else if(s[i] == '-')
      {
        stack.push_back({ .level = level, .value = A, .opp = '-' });
        A = 0;
      }
    }

    stack.push_back({ .level = level, .value = A, .opp = opp });

    int j = 0;
    A = stack[j].value;

    for(; j < stack.size() - 1; j++)
    {
      A = (stack[j].opp == '-') ? sub(A, stack[j + 1].value) : add(A, stack[j + 1].value);
    }

    return A;
  }
};
