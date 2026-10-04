#include <cstdint>
#include <string>
#include <vector>

static int cost['9' + 1]['9' + 1];

class Solution
{
public:
  int minRotations(const int &n, const std::string &s)
  {
    std::vector<int> foward(n + 1, 0), backward(n + 1, 0);

    populate_map();

    char prev = s[0];
    foward[0] = cost['0'][s[0]];
    for(int i = 1; i < n; i++)
    {
      const int cst = cost[prev][s[i]];
      foward[i] = cst + foward[i - 1];
      prev = s[i];
    }

    prev = s[n - 1];
    backward[n - 1] = cost['0'][s[n - 1]];
    for(int i = n - 2; i >= 0; i--)
    {
      backward[i] = cost[prev][s[i]] + backward[i + 1];
      prev = s[i];
    }

    int min_ct = std::min(foward[n - 1], backward[0]);

    for(int i = 1; i < n; i++)
    {
      int calc = foward[i - 1] + cost[s[i - 1]][s[n - 1]] + backward[i] - backward[n - 1];
      min_ct = std::min(min_ct, calc);
    }

    return min_ct;
  }

private:
  uint64_t hash(const char from, const char curr)
  {
    return static_cast<uint64_t>(from) << 32U | static_cast<unsigned>(curr);
  }

  void populate_map()
  {
    static bool done = false;
    if(done)
      return;
    done = true;

    for(char prev = '0'; prev <= '9'; prev++)
    {
      for(char ch = '0'; ch <= '9'; ch++)
      {
        int fow_ct = 0;
        for(char c = prev; c != ch; c++, fow_ct++)
        {
          if(c > '9')
          {
            c = '0';
            if(c == ch)
              break;
          }
        }

        int rev_ct = 0;
        for(char c = prev; c != ch; c--, rev_ct++)
        {
          if(c < '0')
          {
            c = '9';
            if(c == ch)
              break;
          }
        }

        cost[prev][ch] += std::min(fow_ct, rev_ct);
      }
    }
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.minRotations(4, "1502");
  const auto res_2 = sol.minRotations(4, "2916");

  return 0;
}
