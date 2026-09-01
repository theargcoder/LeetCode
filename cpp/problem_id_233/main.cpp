
#include <cstdint>
class Solution
{
public:
  int countDigitOne(const int &n)
  {
    uint64_t num = n;
    uint64_t left, curr, right;
    uint64_t pow10 = 1;

    uint64_t count = 0;
    while(pow10 <= num)
    {
      left = num / (pow10 * 10);
      right = num % pow10;
      curr = (num / pow10) % 10;

      if(curr == 0)
      {
        count += left * pow10;
      }
      else if(curr == 1)
      {
        count += (left * pow10) + (right + 1);
      }
      else
      {
        count += (left + 1) * pow10;
      }

      pow10 *= 10;
    }

    return count;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.countDigitOne(10);
  const auto res_2 = sol.countDigitOne(11);
  const auto res_3 = sol.countDigitOne(12);
  const auto res_4 = sol.countDigitOne(13);

  const auto res_5 = sol.countDigitOne(100);
  const auto res_6 = sol.countDigitOne(111);
  const auto res_7 = sol.countDigitOne(121);
  const auto res_8 = sol.countDigitOne(131);

  return 0;
}
