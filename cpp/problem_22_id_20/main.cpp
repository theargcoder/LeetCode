#include <iostream>
#include <unordered_map>

class Solution
{
  public:
    bool
    isValid (std::string s)
    {
        int size = s.size ();
        if (size % 2 != 0) // input is uneven cant be valid since no match
                           // guaranteed for 1
            {
                return false;
            }
        else
            {
                std::string buffer;

                for (int i = 0; i < size; i++)
                    {
                        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                            {
                                buffer += s[i];
                            }
                        else
                            {
                                if (buffer.size () != 0)
                                    {
                                        if (s[i] == ']')
                                            {
                                                if (buffer[buffer.size () - 1]
                                                    != '[')
                                                    return false;
                                                else
                                                    buffer.pop_back ();
                                            }
                                        if (s[i] == ')')
                                            {
                                                if (buffer[buffer.size () - 1]
                                                    != '(')
                                                    return false;
                                                else
                                                    buffer.pop_back ();
                                            }
                                        if (s[i] == '}')
                                            {
                                                if (buffer[buffer.size () - 1]
                                                    != '{')
                                                    return false;
                                                else
                                                    buffer.pop_back ();
                                            }
                                    }
                                else
                                    {
                                        return false;
                                    }
                            }
                    }

                if (buffer.size () == size)
                    return false;
                if (buffer.size () != 0)
                    return false;
            }
        return true;
    }
};
