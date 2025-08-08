#include <vector>
class MinStack
{
private:
  std::vector<int> stk, mins;

private:
  int min = -1;

public:
  MinStack () {}

  void
  push (int val)
  {
    stk.push_back (val);
    if (mins.empty ())
      mins.push_back (val);
    else if (val < mins.back ())
      mins.push_back (val);
    else
      mins.push_back (mins.back ());
  }

  void
  pop ()
  {
    if (stk.empty () || mins.empty ())
      return;

    stk.pop_back ();
    mins.pop_back ();
  }

  int
  top ()
  {
    return stk.back ();
  }

  int
  getMin ()
  {
    return mins.back ();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
