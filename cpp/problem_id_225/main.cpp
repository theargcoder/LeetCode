#include <queue>

class MyStack
{
private:
  std::queue<int> que1;

public:
  MyStack() = default;

  void push(const int &x)
  {
    que1.push(x);
  }

  int pop()
  {
    std::queue<int> que2;
    while(que1.size() != 1)
    {
      que2.push(que1.front());
      que1.pop();
    }
    const auto val = que1.front();
    que1.pop();
    que1 = que2;
    return val;
  }

  int top()
  {
    std::queue<int> que2;
    while(que1.size() != 1)
    {
      que2.push(que1.front());
      que1.pop();
    }
    const auto val = que1.front();
    que1.pop();
    que2.push(val);
    que1 = que2;
    return val;
  }

  bool empty()
  {
    return que1.empty();
  }
};

int main(int argc, char *argv[])
{
  MyStack stk;

  stk.push(5);
  const auto res_1 = stk.pop();
  stk.push(5);
  stk.push(2);
  const auto res_2 = stk.pop();
  const auto res_3 = stk.top();
  const auto res_4 = stk.top();

  return 0;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
