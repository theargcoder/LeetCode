#include <charconv>
#include <numeric>
#include <string>
#include <string_view>
#include <vector>

class Solution
{
public:
  std::vector<std::string> addOperators(const std::string &num, const int &target)
  {
    std::string str;
    std::vector<std::string> result;
    std::vector<long> stack;
    search(num, result, stack, str, target);

    return result;
  }

private:
  void search(std::string_view numbers, std::vector<std::string> &result, std::vector<long> &stack, std::string &building, const long &target)
  {
    if(numbers.empty())
    {
      const auto sum = std::reduce(stack.begin(), stack.end());
      if(sum == target)
      {
        result.push_back(building);
      }
      return;
    }

    const auto undo = [&building](const size_t &range)
    {
      for(size_t j = 0; j <= range; j++)
        building.pop_back();
    };

    for(size_t i = 0; i < numbers.size(); i++)
    {
      const bool was_there_sign = !building.empty();
      const auto this_view = numbers.substr(0, i + 1);
      long num;
      std::from_chars(this_view.data(), this_view.data() + this_view.size(), num);

      if(!was_there_sign)
      {
        building += this_view;
        stack.push_back(+num);
        search(numbers.substr(i + 1), result, stack, building, target);
        stack.pop_back();
        undo(i);
      }
      else
      {
        // add
        building += '+';
        building += this_view;
        stack.push_back(+num);
        search(numbers.substr(i + 1), result, stack, building, target);
        stack.pop_back();
        undo(i + 1);

        // subtract
        building += '-';
        building += this_view;
        stack.push_back(-num);
        search(numbers.substr(i + 1), result, stack, building, target);
        stack.pop_back();
        undo(i + 1);

        // multiply
        building += '*';
        building += this_view;
        const auto prev_last = stack.back();
        stack.pop_back();
        stack.push_back(prev_last * num);
        search(numbers.substr(i + 1), result, stack, building, target);
        stack.pop_back();
        stack.push_back(prev_last);
        undo(i + 1);
      }

      if(numbers[0] == '0') // leading 0's can only be split by 0' since 05 is illegal
        break;
    }
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.addOperators("123", 6);
  const auto res_2 = sol.addOperators("105", 5);
  const auto res_3 = sol.addOperators("00", 0);
  const auto res_4 = sol.addOperators("999999999", 80);

  return 0;
}
