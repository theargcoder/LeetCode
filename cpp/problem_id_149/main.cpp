#include <algorithm>
#include <map>
#include <numeric> // std::gcd
#include <string>
#include <utility> // std::pair
#include <vector>

// Trashy doesnt work
/*
class Solution
{
private:
  const long
  hash (const int &a, const int &b)
  {
    return static_cast<long> (a) + (static_cast<long> (b) << 32);
  }

public:
  int
  maxPoints (std::vector<std::vector<int>> &points)
  {
    const int n = points.size ();
    if (n == 0)
      return 0;

    int max = 0;

    std::map<int, std::map<int, bool>> mapitX, mapitY;
    std::map<long, bool> mapitdydx;

    for (int i = 0; i < n; i++)
      {
        mapitX[points[i][0]][points[i][1]] = true;
        mapitY[points[i][1]][points[i][0]] = true;

        mapitdydx[hash (points[i][0], points[i][1])] = true;
      }

    for (auto it = mapitX.begin (); it != mapitX.end (); it++)
      max = std::max (max, (int)it->second.size ());
    for (auto it = mapitY.begin (); it != mapitY.end (); it++)
      max = std::max (max, (int)it->second.size ());

    int xbeg = mapitX.begin ()->first;
    int xend = std::prev (mapitX.end ())->first;
    int lyen = std::prev (mapitX.begin ()->second.end ())->first;
    int ryen = std::prev (std::prev (mapitX.end ())->second.end ())->first;

    for (auto x = mapitX.begin (); x != mapitX.end (); x++)
      {
        int dylx = x->first;
        int dyl = x->second.begin ()->first;
        int ctl = 0;
        while (dyl <= lyen && dylx >= xbeg)
          {
            if (mapitdydx.count (hash (dylx, dyl)))
              ctl++;
            dyl++;
            dylx--;
          }

        max = std::max (max, ctl);

        int dyrx = x->first;
        int dyr = x->second.begin ()->first;
        int ctr = 0;
        while (dyr <= ryen && dyrx <= xend)
          {
            if (mapitdydx.count (hash (dyrx, dyr)))
              ctr++;
            dyr++;
            dyrx++;
          }

        max = std::max (max, ctr);
      }

    return max;
  }
};
*/

// well.
class Solution
{
private:
  const long
  hash (const int &a, const int &b)
  {
    return static_cast<long> (a) + (static_cast<long> (b) << 32);
  }

public:
  int
  maxPoints (std::vector<std::vector<int>> &points)
  {
    const int n = points.size ();
    if (n <= 2)
      return n;

    int maxCount = 0;

    // Vertical and horizontal count (optional optimization)
    std::map<int, std::map<int, bool>> mapitX, mapitY;
    for (int i = 0; i < n; i++)
      {
        mapitX[points[i][0]][points[i][1]] = true;
        mapitY[points[i][1]][points[i][0]] = true;
      }

    for (auto &p : mapitX)
      maxCount = std::max (maxCount, (int)p.second.size ());
    for (auto &p : mapitY)
      maxCount = std::max (maxCount, (int)p.second.size ());

    for (int i = 0; i < n; i++)
      {
        std::map<long, int> mapitdydx;
        int duplicates = 1; // count self
        int localMax = 0;

        for (int j = i + 1; j < n; j++)
          {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0)
              continue;
            int g = std::gcd (dx, dy);
            dx /= g;
            dy /= g;

            // Normalize slope direction
            if (dx < 0)
              {
                dx = -dx;
                dy = -dy;
              }
            else if (dx == 0)
              {
                dy = std::abs (dy);
              }

            long hsh = hash (dy, dx);
            mapitdydx[hsh]++;
            localMax = std::max (localMax, mapitdydx[hsh]);
          }

        maxCount = std::max (maxCount, localMax + duplicates);
      }

    return maxCount;
  }
};

int
main (int argc, char *argv[])
{
  Solution sol;
  return 0;
}
