#include <iostream>
#include <string>

class Solution
{
  public:
    int
    myAtoi (std::string s)
    {
        unsigned int int_to_retun = 0;
        bool negative = false;
        int size = s.size ();
        if (size == 0)
            return 0;

        for (int i = 0; i < size; i++)
            {
                if (s[i] == ' ')
                    {
                    }
                else if (s[i] == '-' || s[i] == '+' || std::isdigit (s[i]))
                    {
                        negative = (s[i] == '-') ? true : false;

                        std::size_t pos
                            = (s[i] == '-' || s[i] == '+')
                                  ? s.find_first_not_of ('0', i + 1)
                                  : s.find_first_not_of ('0', i);
                        if (pos == std::string::npos)
                            return 0;
                        if (!std::isdigit (s[pos]))
                            return 0;
                        std::size_t last_digit
                            = s.find_first_not_of ({ '0', '1', '2', '3', '4',
                                                     '5', '6', '7', '8', '9' },
                                                   pos);

                        if (last_digit == std::string::npos)
                            {
                                last_digit = size - 1;
                            }
                        else
                            {
                                last_digit = last_digit - 1;
                            }

                        int power = last_digit - pos;

                        if (power > 9)
                            {
                                if (negative)
                                    return INT32_MIN;
                                else
                                    return INT32_MAX;
                            }

                        if (power == 9 && !(s[pos] == '1' || s[pos] == '2'))
                            {
                                if (negative)
                                    return INT32_MIN;
                                else
                                    return INT32_MAX;
                            }

                        for (int j = pos; j <= last_digit; j++)
                            {
                                int_to_retun += (s[j] - 48) * pow (10, power);

                                power--;
                            }

                        break;
                    }
                else
                    {
                        return 0;
                    }
            }
        if (negative)
            {
                if (int_to_retun > INT32_MAX)
                    {
                        int_to_retun = INT32_MIN;
                    }
                else
                    {
                        // 2's compliment
                        int_to_retun = ~(int_to_retun) + 1;
                    }
            }
        else
            {
                if (int_to_retun > INT32_MAX)
                    int_to_retun = INT32_MAX;
            }

        return (int)(int_to_retun);
    }
};

int
main ()
{
    Solution solution;

    return 0;
}
