#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    std::vector<std::string>
    letterCombinations (std::string digits)
    {

        int size = digits.size ();
        if (size == 0)
            return {};

        std::vector<std::string> result;

        if (size == 1)
            {
                for (auto chr : mapping[digits[0] - 48])
                    {
                        std::string res_str;
                        res_str += chr;
                        result.push_back (res_str);
                    }
                return result;
            }

        std::string loop_str;
        combinations (digits, loop_str, result);

        return result;
    }

  private:
    void
    combinations (std::string &str, std::string &to_push,
                  std::vector<std::string> &vect)
    {
        if (str.size () == 1)
            {
                int base_loc = str[0] - 48;
                for (auto chr : mapping[base_loc])
                    {
                        to_push.push_back (chr);
                        vect.push_back (to_push);
                        to_push.pop_back ();
                    }
            }
        else
            {
                int base_loc = str[0] - 48;
                std::string str_rest = str;
                str_rest.erase (0, 1);
                for (auto chr : mapping[base_loc])
                    {
                        to_push.push_back (chr);
                        combinations (str_rest, to_push, vect);
                        to_push.pop_back ();
                    }
            }
    }
    using my_pair = std::pair<int, std::vector<char> >;
    std::vector<std::vector<char> > mapping{
        {},
        {},
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's' },
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z' },
    };
};

int
main ()
{
    Solution solution;
    std::vector<std::string> inputs{ "2",    "23",   "",         "6234",
                                     "2222", "2355", "244532444" };
    for (auto str : inputs)
        {
            std::vector<std::string> result
                = solution.letterCombinations (str);
            std::cout << "result here it COMES " << '\n';
            for (auto p : result)
                {
                    std::cout << p << ", ";
                }
            std::cout << '\n';
        }
    return 0;
}
