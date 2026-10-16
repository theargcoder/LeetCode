#include <string>
#include <string_view>

constexpr std::string_view words[]
    = { "Zero",    "One",     "Two",       "Three",    "Four",     "Five",   "Six",    "Seven", "Eight", "Nine",  "Ten",     "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred" };

class Solution
{
public:
  std::string numberToWords(const int &num)
  {
    if(num == 0)
      return "Zero";

    int number = num;

    std::string num_words;
    bool not_first = false;

    {
      constexpr int divisor = 1'000'000'000;
      const auto div = number / divisor;
      number -= div * divisor;
      if(div != 0) // no zero leading
      {
        num_words += words[div];
        num_words += " Billion";
        not_first = true;
      }
    }

    for(const auto divisor : { 1'000'000, 1'000, 1 })
    {
      const auto div = number / divisor;
      number -= div * divisor;

      if(div == 0) // no zero leading
        continue;

      if(div >= 100)
      {
        const auto prefix = div / 100;
        num_words += (not_first) ? " " : "";
        num_words += words[prefix];
        num_words += " Hundred";
        not_first = true;
      }

      const auto tens_and_ones = div - (div / 100 * 100);
      const auto prefix = (div >= 100) ? (div - (div / 100 * 100)) / 10 : div / 10;
      const auto sufix = div % 10;
      num_words += (not_first && tens_and_ones != 0) ? " " : "";
      num_words += (tens_and_ones != 0) ? (tens_and_ones <= 20) ? words[tens_and_ones] : words[18 + prefix] : "";
      num_words += (tens_and_ones > 20 && sufix != 0) ? " " : "";
      num_words += (tens_and_ones > 20 && sufix != 0) ? words[sufix] : "";
      num_words += (divisor == 1'000'000) ? " Million" : (divisor == 1'000) ? " Thousand" : "";

      not_first = true;
    }

    return num_words;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.numberToWords(123);
  const auto res_2 = sol.numberToWords(123'456);
  const auto res_3 = sol.numberToWords(123'456'789);
  const auto res_4 = sol.numberToWords(123'456'789'0);
  const auto res_5 = sol.numberToWords(110);
  const auto res_6 = sol.numberToWords(1100000);
  const auto res_7 = sol.numberToWords(123456789);

  return 0;
}
