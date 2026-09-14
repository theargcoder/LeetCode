#include <stack>

class MyQueue
{
private:
  std::stack<int> stk;

public:
  MyQueue() = default;

  void push(const int &x)
  {
    stk.push(x);
  }

  int pop()
  {
    std::stack<int> cpy;

    while(stk.size() > 1)
    {
      cpy.push(stk.top());
      stk.pop();
    }

    const int res = stk.top();
    stk.pop();

    while(!cpy.empty())
    {
      stk.push(cpy.top());
      cpy.pop();
    }

    return res;
  }

  int peek()
  {
    std::stack<int> cpy;

    while(stk.size() > 1)
    {
      cpy.push(stk.top());
      stk.pop();
    }

    const int res = stk.top();
    stk.pop();
    cpy.push(res);

    while(!cpy.empty())
    {
      stk.push(cpy.top());
      cpy.pop();
    }

    return res;
  }

  bool empty()
  {
    return stk.empty();
  }
};

int main(int argc, char *argv[])
{
  MyQueue que;

  que.push(1);
  que.push(2);
  const auto res_1 = que.peek();
  const auto res_2 = que.pop();
  const auto res_3 = que.empty();

  return 0;
}
