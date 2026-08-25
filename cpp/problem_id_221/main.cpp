#include <algorithm>
#include <array>
#include <vector>

class Solution
{
public:
  int maximalSquare(const std::vector<std::vector<char>> &matrix)
  {
    const size_t i_size = matrix.size();
    const size_t j_size = matrix.back().size();

    int max = 0;

    std::array<int, 301> prev{}, curr{};

    for(size_t j = 0; j < j_size; j++)
    {
      prev[j] = matrix[0][j] - '0';
      max = std::max(max, prev[j]);
    }

    for(size_t i = 1; i < i_size; i++)
    {
      curr[0] = matrix[i][0] - '0';
      max = std::max(max, curr[0]);
      for(size_t j = 1; j < j_size; j++)
      {
        if(matrix[i][j] == '0')
        {
          curr[j] = 0;
        }
        else
        {
          curr[j] = std::min({ prev[j - 1], prev[j], curr[j - 1] }) + 1;
          max = std::max(max, curr[j]);
        }
      }
      std::swap(prev, curr);
    }
    return max * max;
  }
};
