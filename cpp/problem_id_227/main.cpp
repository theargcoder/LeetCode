#include <cstdint>
#include <string>
#include <vector>

enum OPP_T : uint8_t
{
  ADD = 0,
  SUB = 1,
  MUL = 2,
  DIV = 3,
  INVALID = 4,
};

OPP_T opp_to_opp_type(const char &ch)
{
  switch(ch)
  {
  case '+':
    return OPP_T::ADD;
  case '-':
    return OPP_T::SUB;
  case '*':
    return OPP_T::MUL;
  case '/':
    return OPP_T::DIV;
  default:
    return OPP_T::INVALID;
  }
}

int perform_opp(const int &A, const int &B, const OPP_T &opp)
{
  switch(opp)
  {
  case OPP_T::ADD:
    return A + B;
  case OPP_T::SUB:
    return A - B;
  case OPP_T::MUL:
    return A * B;
  case OPP_T::DIV:
    return A / B;
  default:
    return A;
  }
}

struct node
{
  int value;
  OPP_T opp;
};

class Solution
{
public:
  int calculate(const std::string &s)
  {
    const size_t size = s.size();

    std::vector<node> mul_div, add_sub;

    int A = 0;

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
          A = (A * 10) + (s[i] - '0');
        }
        i--;
      }
      else
      {
        mul_div.push_back({ .value = A, .opp = opp_to_opp_type(s[i]) });
      }
    }

    mul_div.push_back({ .value = A, .opp = OPP_T::INVALID });

    add_sub.reserve(mul_div.size());

    int i = 0;
    for(; i < mul_div.size() - 1; i++)
    {
      if(mul_div[i].opp == OPP_T::DIV || mul_div[i].opp == OPP_T::MUL)
      {
        int res = mul_div[i].value;
        for(; i < mul_div.size() - 1 && (mul_div[i].opp == OPP_T::DIV || mul_div[i].opp == OPP_T::MUL); i++)
        {
          res = perform_opp(res, mul_div[i + 1].value, mul_div[i].opp);
        }
        i--;

        add_sub.push_back({ .value = res, .opp = mul_div[i + 1].opp });
        i++;
      }
      else
      {
        add_sub.push_back(mul_div[i]);
      }
    }
    if(i != mul_div.size())
    {
      add_sub.push_back(mul_div.back());
    }

    A = 0;
    if(!add_sub.empty())
    {
      A = add_sub[0].value;
      for(i = 0; i < add_sub.size() - 1; i++)
      {
        A = perform_opp(A, add_sub[i + 1].value, add_sub[i].opp);
      }
    }

    return A;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.calculate("3+2*2");
  const auto res_2 = sol.calculate("1+25/3+6/42");
  const auto res_3 = sol.calculate("32  -   48  +  86/  43   - 52  /  69 * 62 -39/  30 -  17 *  44  /6  - 44   -96   - 21-   58/   100   * 41-82*  47- 32   + 96   - 22  ");

  return 0;
}
