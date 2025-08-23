#include <vector>

class Solution
{
public:
  double
  findMaxAverage (std::vector<int> &nums, int k)
  {
    const int n = nums.size ();

    double sum = 0, avr;

    int i = 0;
    for (int l = i; l < k; l++)
      sum += nums[l];
    avr = sum / k;

    for (int j = k; j < n; i++, j++)
      {
        sum -= nums[i];
        sum += nums[j];
        avr = std::max (avr, sum / k);
      }

    return avr;
  }
};
