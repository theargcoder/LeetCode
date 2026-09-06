#include <deque>
#include <iterator>
#include <string>

class Solution
{
public:
  int countRotations(const std::string &s, const int &k)
  {
    std::deque<char> tmp;
    for(const auto &i : s)
    {
      tmp.insert(tmp.end(), i);
    }

    int cycle_ct = 0, tmp_ct = 0;
    for(size_t i = 1; i < s.size(); i++)
    {
      if(s[i] == s[i - 1])
      {
        tmp_ct++;
      }
      if(tmp_ct > k)
      {
        break;
      }
    }
    if(tmp_ct == k)
    {
      cycle_ct++;
    }

    for(size_t i = 0; i < s.size() - 1; i++)
    {
      tmp_ct = 0;
      const auto front = tmp.front();
      tmp.pop_front();
      tmp.insert(tmp.end(), front);
      auto it_prev = tmp.begin();
      auto it_curr = std::next(it_prev);
      while(it_curr != tmp.end())
      {
        if(*it_prev == *it_curr)
        {
          tmp_ct++;
        }
        if(tmp_ct > k)
        {
          break;
        }
        it_prev = it_curr;
        it_curr = std::next(it_curr);
      }
      if(tmp_ct == k)
      {
        cycle_ct++;
      }
    }

    return cycle_ct;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  sol.countRotations("aab", 1);

  return 0;
}
