#include <cstdint>
#include <iterator>
#include <set>

class Solution
{
private:
  void setup()
  {
    static bool done = false;
    if(done)
    {
      return;
    }
    done = true;

    DP.insert(1);

    auto it = DP.begin();
    int ct = 0;
    while(ct < 1691)
    {
      ct++;
      DP.insert(*it * 2);
      DP.insert(*it * 3);
      DP.insert(*it * 5);
      it = std::next(it);
    }
  }

public:
  static std::set<uint64_t> DP;

public:
  int nthUglyNumber(const int &n)
  {
    setup();

    auto it = std::next(DP.begin(), n - 1);
    return *it;
  }
};

std::set<uint64_t> Solution::DP = std::set<uint64_t>{};

int main(int argc, char *argv[])
{

  Solution sol;

  const auto res_1 = sol.nthUglyNumber(10);
  const auto res_2 = sol.nthUglyNumber(4);
  const auto res_3 = sol.nthUglyNumber(123);

  return 0;
}
