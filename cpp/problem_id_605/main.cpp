#include <vector>

class Solution
{
public:
  bool
  canPlaceFlowers (std::vector<int> &flowerbed, int n)
  {
    const int m = flowerbed.size () - 1;

    int ct = 0;

    if (m == 0)
      {
        if (flowerbed[0] == 0)
          ct++;
      }
    else
      {
        bool prev = true;

        for (int i = 0; i < m; i++)
          {
            if (prev && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
              {
                ct++;
                flowerbed[i] = 1;
              }
            prev = flowerbed[i] == 0;
          }
        if (prev && flowerbed[m] == 0)
          ct++;
      }

    return ct >= n;
  }
};
