#include <algorithm>
#include <array>
#include <cstring>
#include <string>
#include <vector>

// slow but readable
/*
class Solution
{
public:
  std::string largestNumber(std::vector<int> &nums)
  {
    const auto size = nums.size();
    std::vector<std::string> stack;

    unsigned zeros = 0;

    for(unsigned i = 0; i < size; i++)
    {
      if(nums[i] == 0)
      {
        zeros++;
      }
      const auto str = std::to_string(nums[i]);
      stack.push_back(str);
    }

    if(zeros == size)
    {
      return "0";
    }

    const auto sorter = [](const std::string &a, const std::string &b) { return a + b > b + a; };

    std::sort(stack.begin(), stack.end(), sorter);

    std::string str;

    for(const auto &i : stack)
    {
      str += i;
    }

    return str;
  }
};
*/

// faster but more 'manual' also much less memory usage
class Solution
{
public:
  std::string largestNumber(std::vector<int> &nums)
  {
    const auto size = nums.size();
    std::array<std::array<char, 11>, 100> stack;

    stack.fill(std::array<char, 11>{ 0 });

    unsigned zeros = 0;

    for(unsigned i = 0; i < size; i++)
    {
      if(nums[i] == 0)
      {
        zeros++;
      }
      const auto str = std::to_string(nums[i]);
      std::memcpy(&stack[i], str.c_str(), str.size());
    }

    if(zeros == size)
    {
      return "0";
    }

    const auto sorter = [](const auto &a, const auto &b)
    {
      const auto a_len = std::strlen(&a[0]);
      const auto b_len = std::strlen(&b[0]);
      const auto tot = a_len + b_len;

      std::array<char, 22> a_b, b_a;

      std::memcpy(&a_b[0], &a[0], a_len);
      std::memcpy(&a_b[a_len], &b[0], b_len);

      std::memcpy(&b_a[0], &b[0], b_len);
      std::memcpy(&b_a[b_len], &a[0], a_len);

      for(unsigned i = 0; i < tot; i++)
      {
        if(a_b[i] > b_a[i])
        {
          return true;
        }
        else if(a_b[i] < b_a[i])
        {
          return false;
        }
      }

      return false;
    };

    std::sort(stack.begin(), stack.begin() + size, sorter);

    std::string str;

    for(unsigned i = 0; i < size; i++)
    {
      str += std::string(stack[i].data());
    }

    return str;
  }
};

/*
int main(int argc, char *argv[])
{
  std::vector<int> vec = { 1000000000, 1000000000 };

  Solution sol;

  sol.largestNumber(vec);

  return 0;
}
*/
