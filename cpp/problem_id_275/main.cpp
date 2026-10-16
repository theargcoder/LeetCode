#include <vector>

class Solution
{
public:
  int hIndex(const std::vector<int> &citations)
  {
    const size_t size = citations.size();
    size_t left = 0, right = size;

    while(right - left > 1)
    {
      const size_t diff = (right - left);
      const size_t mid = left + (diff >> 1) + (diff & 0b01);

      if(citations[mid] >= size - mid)
      {
        right = mid;
      }
      else if(citations[mid] < size - mid)
      {
        left = mid;
      }
    }

    int res = size - right;

    if(res == 0 && citations[0] != 0)
      return 1;

    return res;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.hIndex({ 0, 1, 3, 5, 6 });

  return 0;
}
