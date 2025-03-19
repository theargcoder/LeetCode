#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

class Solution
{
 public:
   void
   rotate (std::vector<std::vector<int> > &matrix)
   {

      const int layers = matrix.size () - 1;
      const int middle = matrix.size () / 2;
      const int i_rst = matrix.front ().size () - 1;

      coordinates tl = coordinates (0, 0);
      coordinates tr = coordinates (i_rst, 0);
      coordinates bl = coordinates (0, layers);
      coordinates br = coordinates (i_rst, layers);
      // WE ASSUME THAT THIS IS A SYMETRIC MATRIX....

      while (tl.y < middle)
         {
            while (tl.x < tr.x)
               {
                  std::swap (matrix[tl.y][tl.x], matrix[bl.y][bl.x]);
                  std::swap (matrix[bl.y][bl.x], matrix[br.y][br.x]);
                  std::swap (matrix[br.y][br.x], matrix[tr.y][tr.x]);
                  tl.x++;
                  tr.y++;
                  br.x--;
                  bl.y--;
               }
            tl.y++;
            tl.x = tl.y;
            bl.x++;
            bl.y = layers - tl.y;
            tr.x--;
            tr.y = tl.y;
            br.y--;
            br.x = br.y;
         }
   }

 private:
   struct coordinates
   {
      unsigned char x, y;

      coordinates (unsigned char a, unsigned char b) : x (a), y (b) {};
   };
};

int
main ()
{
   std::vector<std::vector<int> > vec = {
      { 5, 1, 9, 11 },
      { 2, 4, 8, 10 },
      { 13, 3, 6, 7 },
      { 15, 14, 12, 16 },
   };

   Solution sol;

   std::cout << "ORIGINAL INPUT IS:" << '\n';
   for (auto &vec0 : vec)
      {
         for (auto &i : vec0)
            {
               std::cout << i << ' ';
            }
         std::cout << '\n';
      }

   sol.rotate (vec);

   std::cout << "FULL 90 DEG ROT IS :" << '\n';
   for (auto &vec0 : vec)
      {
         for (auto &i : vec0)
            {
               std::cout << i << ' ';
            }
         std::cout << '\n';
      }

   return 0;
}
