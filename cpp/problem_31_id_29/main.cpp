#include <iostream>
#include <vector>

class Solution
{
  public:
    int
    divide (int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (dividend == divisor)
            return 1;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            {
                if (dividend < 0)
                    {
                        if (dividend == INT_MIN)
                            return INT_MAX;
                        else
                            return ~(dividend - 1);
                    }
                else
                    {
                        return ~(dividend) + 1;
                    }
            }
        int shift = 1;
        int remainer = dividend;
        int count = 0;
        if (dividend > 0 && divisor > 0)
            {
                if (divisor > dividend)
                    return 0;

                while (remainer >= divisor)
                    {
                        remainer -= divisor;
                        count += shift;
                    }
            }
        else if (dividend < 0 && divisor < 0)
            {
                while (remainer <= divisor)
                    {
                        remainer -= divisor;
                        count += shift;
                    }
            }
        else if (dividend < 0 && divisor > 0)
            {
                shift = -1;
                divisor = ~divisor + 1;
                while (remainer <= divisor)
                    {
                        remainer -= divisor;
                        count += shift;
                    }
            }
        else
            {
                shift = -1;
                if (divisor == INT_MIN)
                    return 0;
                divisor = ~(divisor - 1);
                while (remainer >= divisor)
                    {
                        remainer -= divisor;
                        count += shift;
                    }
            }

        return count;
    }
};
