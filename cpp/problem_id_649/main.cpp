#include <deque>
#include <string>
#include <unordered_map>

class Solution
{
public:
  std::string
  predictPartyVictory (std::string senate)
  {
    const int n = senate.size ();

    static const std::unordered_map<char, char> map{ { 'R', 'D' },
                                                     { 'D', 'R' } };

    std::deque<char> deque;
    int R = 0, D = 0;

    for (int i = 0; i < n; i++)
      deque.push_back (senate[i]);

    while (deque.size () > 1)
      {
        char ch = deque.front ();
        deque.pop_front ();
        char opp = map.at (ch);

        int l = deque.size () - 1;
        int a = 0;
        while (a <= l && deque[a] != opp)
          a++;
        if (a > l)
          break;
        deque.erase (deque.begin () + a);
        deque.push_back (ch);
      }
    if (deque.front () == 'R')
      return "Radiant";
    else
      return "Dire";
  }
};
