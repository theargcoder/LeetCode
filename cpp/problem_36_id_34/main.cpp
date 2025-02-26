#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int>
    searchRange (std::vector<int> &nums, int target)
    {
        auto begin = nums.begin ();
        auto end = nums.end ();
        auto it = std::lower_bound (begin, end, target);

        if (it == end)
            return { -1, -1 };

        if (*it != target)
            return { -1, -1 };

        auto it_en = std::upper_bound (it, end, target);

        std::vector<int> to_ret{ static_cast<int> (std::distance (begin, it)),
                                 static_cast<int> (std::distance (begin, it_en)
                                                   - 1) };

        return to_ret;
    }
};

int
main ()
{
    std::vector<int> vect;

    int size = 100000;

    for (int i = 0; i < size; i++)
        {
            vect.push_back (0);
            if (i % 2 == 0)
                vect[i] = -vect[i];
        }

    std::sort (vect.begin (), vect.end (), std::less<int> ());

    std::cout << "[ ";
    for (auto i : vect)
        std::cout << i << ", ";
    std::cout << "] ";
    return 0;
}
