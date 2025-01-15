#include <chrono>
#include <iostream>
#include <math.h>

/* WORKING SOLUTION TOOK 13 microseconds....
class Solution
{
  public:
    double
    findMedianSortedArrays (std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int m = nums1.size ();
        int n = nums2.size ();

        std::vector<int> combined_nums (m + n);

        if (m != 0 && n != 0)
            {

                std::merge (nums1.begin (), nums1.end (), nums2.begin (),
                            nums2.end (), combined_nums.begin ());
                int size = combined_nums.size ();
                if ((size % 2) == 0)
                    {
                        return (combined_nums[(size / 2) - 1]
                                + combined_nums[((size / 2))])
                               / 2.0;
                    }
                else
                    {
                        return combined_nums[std::ceil (size / 2.0) - 1];
                    }
            }
        else if (m != 0 && n == 0)
            {
                int size = m;
                if ((size % 2) == 0)
                    {
                        return (nums1[(size / 2) - 1] + nums1[((size / 2))])
                               / 2.0;
                    }
                else
                    {
                        return nums1[std::ceil (size / 2.0) - 1];
                    }
            }
        else if (m == 0 && n != 0)
            {
                int size = n;
                if ((size % 2) == 0)
                    {
                        return (nums2[(size / 2) - 1] + nums2[((size / 2))])
                               / 2.0;
                    }
                else
                    {
                        return nums2[std::ceil (size / 2.0) - 1];
                    }
            }
        else
            {
                return 0.0;
            }
    }
};
*/
class Solution
{
  public:
    double
    findMedianSortedArrays (std::vector<int> &nums1, std::vector<int> &nums2)
    {
        long long int total_sum = 0;

        int m_size = nums1.size ();
        int n_size = nums2.size ();

        if (m_size != 0 && n_size != 0)
            { // both nums1 and nums2 have size non zero
                const std::vector<int> &A = (m_size < n_size) ? nums1 : nums2;
                const std::vector<int> &B = (m_size < n_size) ? nums2 : nums1;

                int m = A.size ();
                int n = B.size ();
                int total = m + n;
                int half = total / 2;

                int left = 0, right = m;

                while (left <= right)
                    {
                        int i = (left + right) / 2; // Partition A
                        int j = half - i;           // Partition B

                        int Aleft = (i > 0) ? A[i - 1] : INT_MIN;
                        int Aright = (i < m) ? A[i] : INT_MAX;
                        int Bleft = (j > 0) ? B[j - 1] : INT_MIN;
                        int Bright = (j < n) ? B[j] : INT_MAX;

                        // Check if partition is valid
                        if (Aleft <= Bright && Bleft <= Aright)
                            {
                                if ((total % 2) == 0)
                                    { // meaning total is even
                                        int left_max = std::max (Aleft, Bleft);
                                        int right_max
                                            = std::min (Aright, Bright);
                                        return (left_max + right_max) / 2.0;
                                    }
                                else
                                    { // total isn't even
                                        int left_max = std::max (Aleft, Bleft);
                                        int right_min
                                            = std::min (Aright, Bright);
                                        return std::max (left_max, right_min);
                                    }
                            }
                        else if (Aleft > Bright)
                            {
                                right = i - 1; // Move left in A
                            }
                        else
                            {
                                left = i + 1; // Move right in A
                            }
                    }
            }
        else if (m_size != 0 && n_size == 0)
            { // nums1 has size non zero but nums2 has size 0
                if ((m_size % 2) == 0)
                    {
                        return (nums1[(m_size / 2) - 1]
                                + nums1[((m_size / 2))])
                               / 2.0;
                    }
                else
                    {
                        return nums1[std::ceil (m_size / 2.0) - 1];
                    }
            }
        else if (m_size == 0 && n_size != 0)
            { // nums2 has size non zero but nums1 has size 0
                if ((n_size % 2) == 0)
                    {
                        return (nums2[(n_size / 2) - 1]
                                + nums2[((n_size / 2))])
                               / 2.0;
                    }
                else
                    {
                        return nums2[std::ceil (n_size / 2.0) - 1];
                    }
            }
        else
            { // case when both nums1 and nums2 have size 0..... BAD
                return 0.0;
            }
        return 0.0; // to avoid compiler warking (compilers love to complain)
    }
};

int
main ()
{
    Solution solution; // Replace with your actual Solution class definition

    // Test Cases
    std::vector<std::vector<int> > test_nums1 = {
        { 1, 2, 3, 4, 5 },                      // test 1
        { 1, 2, 3, 5, 6, 7, 8 },                // test 2
        { 1, 3, 5, 7, 9, 11, 13 },              // test 3
        { 10, 20, 30, 40, 50 },                 // test 4
        { 10, 20, 30, 40, 50, 60, 70, 80 },     // test 5
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },      // test 6
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },  // test 7
        { 3, 4, 5, 6, 7, 8, 9, 10 },            // test 8
        { 3, 5, 7, 9, 11, 13, 15 },             // test 9
        { 1, 1, 1, 1, 1, 1 },                   // test 10
        { 2, 2, 2, 2, 2 },                      // test 11
        { 0, 1, 2, 3, 4, 5, 6 },                // test 12
        { 10, 11, 12, 13, 14, 15, 16, 17, 18 }, // test 13
        { 100, 200, 300, 400, 500 },            // test 14
        { 100, 101, 102, 103, 104, 105, 106 },  // test 15
        { 11, 22, 33, 44, 55, 66, 77 },         // test 16
        { 10, 30, 50, 70, 90 },                 // test 17
        { 1, 10, 100, 1000, 10000 },            // test 18
        { 13, 16, 19, 22, 25 },                 // test 19
        { 1000, 2000, 3000, 4000, 5000, 6000 }, // test 20
    };

    std::vector<std::vector<int> > test_nums2 = {
        { 6, 7, 8, 9 },                         // test 1
        { 4, 5, 6, 7, 8, 9 },                   // test 2
        { 2, 4, 6, 8, 10 },                     // test 3
        { 60, 70, 80, 90, 100 },                // test 4
        { 55, 65, 75, 85, 95, 105 },            // test 5
        { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, // test 6
        { 6, 8, 10, 12, 14, 16, 18 },           // test 7
        { 4, 6, 8, 10, 12, 14 },                // test 8
        { 2, 3, 5, 7, 9, 11, 13, 15, 17 },      // test 9
        { 2, 2, 2, 2, 2, 2 },                   // test 10
        { 6, 6, 6, 6, 6, 6 },                   // test 11
        { 0, 2, 4, 6, 8, 10, 12 },              // test 12
        { 20, 30, 40, 50, 60, 70, 80 },         // test 13
        { 150, 160, 170, 180, 190 },            // test 14
        { 101, 102, 103, 104, 105, 106, 107 },  // test 15
        { 23, 44, 55, 66, 77, 88 },             // test 16
        { 20, 40, 60, 80, 100 },                // test 17
        { 5000, 6000, 7000, 8000, 9000 },       // test 18
        { 10, 15, 20, 25, 30 },                 // test 19
        { 5000, 10000, 15000, 20000, 25000 },   // test 20
    };

    // Corrected Expected results
    std::vector<double> expected_results = {
        5,     // testcase 0
        6,     // testcase 1
        6.5,   // testcase 2
        55,    // testcase 3
        62.5,  // testcase 4
        8,     // testcase 5
        10,    // testcase 6
        7.5,   // testcase 7
        9,     // testcase 8
        1.5,   // testcase 9
        6,     // testcase 10
        4,     // testcase 11
        17.5,  // testcase 12
        185,   // testcase 13
        103.5, // testcase 14
        55,    // testcase 15
        55,    // testcase 16
        5500,  // testcase 17
        19.5,  // testcase 18
        5000,  // testcase 19
    };

    std::vector<bool> results;
    for (size_t i = 0; i < test_nums1.size (); ++i)
        {
            std::vector<int> nums1 = test_nums1[i];
            std::vector<int> nums2 = test_nums2[i];

            auto start = std::chrono::high_resolution_clock::now ();

            double ret = solution.findMedianSortedArrays (nums1, nums2);

            auto end = std::chrono::high_resolution_clock::now ();

            // Calculate elapsed time
            auto elapsed_ns
                = std::chrono::duration_cast<std::chrono::nanoseconds> (
                    end - start);
            auto elapsed_us
                = std::chrono::duration_cast<std::chrono::microseconds> (
                    end - start);
            auto elapsed_ms
                = std::chrono::duration_cast<std::chrono::milliseconds> (
                    end - start);
            auto elapsed_s = std::chrono::duration_cast<std::chrono::seconds> (
                end - start);

            // Output results
            std::cout << "Test Case " << i + 1 << ":\n";
            std::cout << "  Median: " << ret << '\n';
            std::cout << "  Expected: " << expected_results[i] << '\n';
            std::cout << "  Nanoseconds: " << elapsed_ns.count () << " ns\n";
            std::cout << "  Microseconds: " << elapsed_us.count () << " µs\n";
            std::cout << "  Milliseconds: " << elapsed_ms.count () << " ms\n";
            std::cout << "  Seconds: " << elapsed_s.count () << " s\n";

            // Check if the median and expected result are equal
            results.push_back (ret == expected_results[i]);
            if (results[i])
                {
                    std::cout << "\n\n" << "  EQUAL\n";
                }
            else
                {
                    std::cout << "  NOT EQUAL\n";
                }

            std::cout << "-----------------------------------\n";
        }
    int counter = 0;
    for (auto i : results)
        {
            counter++;
            std::string str = (i) ? "CORRECT" : "INCORRECT";
            std::cout << "test " << counter << " is " << str << '\n';
        }
    return 0;
}
