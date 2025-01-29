#include <iostream>
#include <set>
#include <vector>

// 3 sum working solution (==0)
// using std::multiset
// beats a  lot of the solutions pretty fast
/*
class Solution
{
  public:
    std::vector<std::vector<int> >
    threeSum (std::vector<int> &nums)
    {
        std::vector<std::vector<int> > result;
        std::multiset<int> sorted (nums.begin (), nums.end ());

        int size = sorted.size ();

        if (size < 3)
            {
                return result;
            }

        auto middle = sorted.lower_bound (0);

        auto it_first = sorted.begin ();

        if (*it_first > 0)
            return result;

        if (sorted.count (0) > 2)
            result.push_back ({ 0, 0, 0 });

        for (auto it = sorted.begin (); it != sorted.end ();)
            {
                if (*it != 0)
                    {
                        int opposite = ~(*it - 1);

                        auto start = sorted.lower_bound (*it);
                        auto end = sorted.end ();
                        start++;
                        end--;

                        while (start != end && *start < opposite
                               && *start <= *end)
                            {
                                int sum = *start + *end;
                                if (sum == opposite)
                                    {
                                        std::vector<int> yei{ *it, *start,
                                                              *end };
                                        result.push_back (yei);
                                        while (*start == yei[1])
                                            start++;
                                        while (*end == yei[2])
                                            end--;
                                    }
                                else if (sum < opposite)
                                    {
                                        int start_original = *start;
                                        while (*start == start_original)
                                            start++;
                                    }
                                else
                                    {
                                        int end_original = *end;
                                        while (*end == end_original)
                                            end--;
                                    }
                            }
                    }
                else
                    {
                        break;
                    }
                it = sorted.upper_bound (*it);
            }

        return result;
    }
};
*/

// working (I THINK*****) WITH PRINTS
/*
class Solution
{
  public:
    std::vector<std::vector<int> >
    fourSum (std::vector<int> &sorted, int target)
    {
        std::vector<std::vector<int> > result;

        int size = sorted.size ();

        if (size < 4)
            {
                return result;
            }

        std::sort (sorted.begin (), sorted.end ());

        std::cout << "SORTED IS " << '\n';
        for (auto i : sorted)
            {
                std::cout << i << ' ' << ',';
            }
        std::cout << '\n';

        for (auto it = sorted.begin (); it < sorted.end () - 3;)
            {
                for (auto it_2 = it + 1; it_2 < sorted.end () - 2;)
                    {
                        int missing = target - (*it + *it_2);
                        std::cout << "MISSING -> " << missing << '\n';

                        auto start = it_2 + 1;
                        auto end = sorted.end () - 1;
                        std::cout << "start -> " << *start << '\n';
                        std::cout << "end -> " << *end << '\n';

                        while (start < end && *start <= std::abs (missing))
                            {
                                int sum = *start + *end;
                                std::cout << "start -> " << *start << '\n';
                                std::cout << "end -> " << *end << '\n';
                                std::cout << "SUM -> " << sum << '\n';
                                if (sum == missing)
                                    {
                                        std::vector<int> yei{ *it, *it_2,
                                                              *start, *end };
                                        result.push_back (yei);
                                        start = std::upper_bound (
                                            it_2, sorted.end (), yei[2]);
                                        while (end != sorted.begin ())
                                            if (*end == yei[3])
                                                end--;
                                            else
                                                break;
                                        if (start == sorted.end ()
                                            || end == sorted.end ())
                                            break;
                                    }
                                else if (sum < missing)
                                    {
                                        start = std::upper_bound (
                                            it_2, sorted.end (), *start);
                                        if (start == sorted.end ()
                                            || end == sorted.end ())
                                            break;
                                    }
                                else
                                    {
                                        int end_original = *end;
                                        while (end != sorted.begin ())
                                            if (*end == end_original)
                                                end--;
                                            else
                                                break;
                                        if (start == sorted.end ()
                                            || end == sorted.end ())
                                            break;
                                    }
                            }
                        it_2 = std::upper_bound (it, sorted.end (), *it_2);
                    }
                it = std::upper_bound (it, sorted.end (), *it);
            }

        return result;
    }
};
 */

class Solution
{
  public:
    std::vector<std::vector<int> >
    fourSum (std::vector<int> &sorted, int target)
    {
        std::vector<std::vector<int> > result;

        int size = sorted.size ();

        if (size < 4)
            {
                return result;
            }

        std::sort (sorted.begin (), sorted.end ());

        for (auto it = sorted.begin (); it < sorted.end () - 3;)
            {
                for (auto it_2 = it + 1; it_2 < sorted.end () - 2;)
                    {
                        long long int missing = (long long int)target
                                                - (long long int)(*it + *it_2);

                        auto start = it_2 + 1;
                        auto end = sorted.end () - 1;
                        while (start < end && *start <= std::abs (missing))
                            {
                                int sum = *start + *end;
                                if (sum == missing)
                                    {
                                        std::vector<int> yei{ *it, *it_2,
                                                              *start, *end };
                                        result.push_back (yei);
                                        start = std::upper_bound (
                                            it_2, sorted.end (), yei[2]);
                                        while (end != sorted.begin ())
                                            if (*end == yei[3])
                                                end--;
                                            else
                                                break;
                                        if (start == sorted.end ()
                                            || end == sorted.end ())
                                            break;
                                    }
                                else if (sum < missing)
                                    {
                                        start = std::upper_bound (
                                            it_2, sorted.end (), *start);
                                        if (start == sorted.end ()
                                            || end == sorted.end ())
                                            break;
                                    }
                                else
                                    {
                                        int end_original = *end;
                                        while (end != sorted.begin ())
                                            if (*end == end_original)
                                                end--;
                                            else
                                                break;
                                        if (start == sorted.end ()
                                            || end == sorted.end ())
                                            break;
                                    }
                            }
                        it_2 = std::upper_bound (it, sorted.end (), *it_2);
                    }
                it = std::upper_bound (it, sorted.end (), *it);
            }

        return result;
    }
};

int
main ()
{
    Solution solution;
    std::vector<std::vector<int> > inputs{
        { -1, 0, 1, 2, -1, -4 },
        { 0, 1, 1 },
        { 0, 0, 0 },
        { -1, 0, 1, 2, -1, -4, 4, 5, 2, 9, 1, 0, 2 },
        { 1, 2, 3, 4, 5, 6, 7 },
        { 45,  63,  56,  42,  103,  -79, -29, -80, -1,  -71, -78, 99,
          14,  19,  25,  -88, -102, 72,  99,  84,  100, 3,   -31, 33,
          65,  -34, 77,  39,  -36,  -89, -77, -2,  18,  30,  -28, -52,
          -26, 24,  -51, 46,  -92,  30,  76,  -31, 53,  54,  52,  -103,
          -56, -56, 61,  95,  45,   47,  39,  77,  54,  -83, -28, -100,
          -20, 77,  -36, 33,  -91,  -72, 77 },
        { 45,  63,   56,  42,   103, -79, -29,  -80,  -1,   -71, -78, 99,  14,
          19,  25,   -88, -102, 72,  99,  84,   100,  3,    -31, 33,  65,  -34,
          77,  39,   -36, -89,  -77, -2,  18,   30,   -28,  -52, -26, 24,  -51,
          46,  -92,  30,  76,   -31, 53,  54,   52,   -103, -56, -56, 61,  95,
          45,  47,   39,  77,   54,  -83, -28,  -100, -20,  77,  -36, 33,  -91,
          -72, 77,   -76, 27,   -16, 45,  47,   29,   44,   46,  -76, 93,  90,
          59,  -15,  54,  61,   55,  25,  55,   48,   44,   -44, -21, 21,  84,
          99,  -13,  90,  64,   -81, 1,   -95,  -89,  -48,  24,  87,  -26, 18,
          -83, 4,    66,  -40,  -74, -46, -101, -21,  -24,  51,  -22, -92, 58,
          57,  -69,  22,  105,  93,  29,  61,   39,   -21,  90,  86,  34,  -78,
          -96, -1,   -50, -31,  31,  -49, -1,   7,    27,   70,  21,  101, 98,
          -11, 60,   7,   -75,  -84, 24,  3,    22,   -10,  73,  -81, 0,   65,
          49,  33,   -25, 79,   61,  64,  -83,  51,   -43,  -25, -44, -20, -92,
          64,  -89,  59,  -57,  -5,  -11, -27,  15,   36,   49,  70,  81,  86,
          -3,  85,   -60, 104,  -11, -18, -14,  -37,  44,   61,  33,  52,  -11,
          36,  103,  -77, 98,   -39, -23, 99,   -67,  -82,  84,  -21, 67,  70,
          12,  3,    84,  -19,  100, 38,  -78,  26,   -92,  88,  -61, -67, 21,
          -65, -79,  16,  -8,   54,  -3,  -77,  -98,  72,   27,  90,  13,  0,
          2,   93,   -28, -71,  -97, -26, -39,  94,   8,    -91, 84,  75,  105,
          -38, -39,  -66, 101,  -64, 38,  -57,  -46,  -26,  14,  -15, -70, 69,
          48,  32,   1,   -81,  -71, -1,  -104, 17,   19,   14,  -15, 59,  -90,
          -83, -75,  -74, 2,    -29, 1,   -105, 12,   30,   -21, -33, -99, 44,
          -28, -2,   -6,  -46,  -77, -13, 88,   -7,   -87,  97,  -86, -48, -76,
          -51, -100, 97,  69 },
        { -83193, -24751, -49927, 43658,  8930,   -88728, -72456, -49122,
          77923,  -62291, 64440,  -61835, -15508, -56958, -92013, 22503,
          -17673, 31729,  78840,  42612,  44303,  -66831, -82291, -2843,
          29560,  70933,  -6901,  -19722, 51816,  95335,  -903,   -92174,
          -86488, 29267,  23810,  -22367, 80979,  79149,  -63421, 58821,
          11967,  -89328, 1393,   -80664, 25485,  -8255,  -74772, -5909,
          -59806, 86357,  -64999, 21153,  -83292, 57944,  15668,  71490,
          88124,  2196,   9530,   -39097, 27722,  -45334, 28549,  18024,
          97801,  -93147, 40977,  -52592, 8228,   74933,  -39702, 38981,
          -71365, -91987, -76135, 89814,  39063,  54536,  39425,  -98331,
          24115,  -79906, -24371, -53499, 46517,  34195,  -69895, -89596,
          19451,  94298,  82188,  -78877, 99505,  -53118, -93248, 31566,
          36716,  30337,  54438,  -46856, -48499, -55103, 83871,  55828,
          11137,  -80642, 53177,  82397,  22294,  -22096, -78391, 46231,
          59745,  -55825, -46365, -33702, -1858,  -19601, -72032, -9588,
          -99740, -26443, -58406, -11992, 16395,  25968,  19113,  -95470,
          -28994, 10962,  97942,  -14635, -57918, 79852,  30767,  -66179,
          85695,  -75288, 73671,  -40099, -51410, 24831,  14738,  53057,
          -68384, -80210, 55640,  10679,  -62665, -22994, -2028,  36098,
          -50905, 75319,  83454,  45223,  12289,  56760,  48905,  86126,
          -63877, 29506,  -54187, -23230, 35238,  29094,  -3780,  87844,
          12366,  40534,  25226,  15394,  41363,  18738,  -92156, 59590,
          -63450, 45159,  -91377, 64947,  97385,  7217,   95272,  55539,
          99247,  -57615, -86504, -5115,  40623,  -17580, -71856, 31968,
          35735,  -85,    61625,  -36466, -53958, 96011,  -45321, -75848,
          75244,  77295,  -21182, 90396,  -12308, 1815,   12991,  40033 }
    };

    std::vector<std::vector<std::vector<int> > > expected_result{ {}, {}, {},
                                                                  {}, {}, {},
                                                                  {}, {} };

    for (int i = 0; i < inputs.size (); i++)
        {
            std::cout << "INPUT is \n";
            std::cout << "{ ";
            for (auto j : inputs[i])
                {
                    std::cout << j << " ,";
                }
            std::cout << "}";
            std::cout << '\n';
            // Get the starting time
            auto start = std::chrono::high_resolution_clock::now ();

            std::vector<std::vector<int> > result
                = solution.fourSum (inputs[i], rand () % 10);
            auto end = std::chrono::high_resolution_clock::now ();

            // Calculate the duration in milliseconds
            auto duration
                = std::chrono::duration_cast<std::chrono::milliseconds> (
                    end - start);

            std::cout << "Result is \n";
            for (auto j : result)
                {
                    std::cout << "{ ";
                    for (auto p : j)
                        {
                            std::cout << p << " ,";
                        }
                    std::cout << "}, ";
                }
            std::cout << '\n';

            std::cout << "EXPECTED Result is \n";
            for (auto j : expected_result[i])
                {
                    std::cout << "{ ";
                    for (auto p : j)
                        {
                            std::cout << p << " ,";
                        }
                    std::cout << "}, ";
                }
            std::cout << '\n';
            // Print the duration
            std::cout << "Execution time: " << duration.count () << " ms"
                      << std::endl;
        }
    return 0;
}
