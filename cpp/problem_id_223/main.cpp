#include <algorithm>

struct Coordinate
{
  int x, y;
};

class Solution
{
public:
  int computeArea(const int &ax1, const int &ay1, const int &ax2, const int &ay2, const int &bx1, const int &by1, const int &bx2, const int &by2)
  {
    const auto area_a = (ax2 - ax1) * (ay2 - ay1);
    const auto area_b = (bx2 - bx1) * (by2 - by1);

    const auto overlap_x = std::max(0, std::min(ax2, bx2) - std::max(ax1, bx1));
    const auto overlap_y = std::max(0, std::min(ay2, by2) - std::max(ay1, by1));

    const auto area_overlap = overlap_x * overlap_y;

    return area_a + area_b - area_overlap;
  }
};
