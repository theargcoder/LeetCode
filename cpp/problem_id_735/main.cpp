#include <algorithm>
#include <math.h>
#include <stack>
#include <vector>

class Solution
{
public:
  std::vector<int>
  asteroidCollision (std::vector<int> &asteroids)
  {
    const int n = asteroids.size ();

    std::stack<int> stk;

    stk.push (asteroids[0]);

    for (int i = 1; i < n; i++)
      {
        if (stk.empty ())
          stk.push (asteroids[i]);
        else if ((stk.top () > 0 && asteroids[i] > 0)
                 || (stk.top () < 0 && asteroids[i] < 0)
                 || (stk.top () < 0 && asteroids[i] > 0))
          stk.push (asteroids[i]);
        else if (stk.top () > 0 && asteroids[i] < 0)
          {
            bool broke = false;
            int abs = std::abs (asteroids[i]);
            while (!stk.empty () && stk.top () > 0)
              {
                if (abs > std::abs (stk.top ()))
                  stk.pop ();
                else if (abs < std::abs (stk.top ()))
                  {
                    broke = true;
                    break;
                  }
                else
                  {
                    stk.pop ();
                    broke = true;
                    break;
                  }
              }
            if (!broke)
              stk.push (asteroids[i]);
          }
      }

    std::vector<int> res;

    while (!stk.empty ())
      res.push_back (stk.top ()), stk.pop ();

    std::reverse (res.begin (), res.end ());

    return res;
  }
};
