#include <algorithm>
#include <vector>

class Solution
{
public:
  int hIndex(std::vector<int> &citations)
  {
    const size_t size = citations.size();
    std::ranges::sort(citations);

    for(size_t i = 0; i < size; i++)
    {
      if(size - i <= citations[i])
      {
        return size - i;
      }
    }

    return 0;
  }
};
