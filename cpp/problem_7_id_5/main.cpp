#include <iostream>
#include <string>
#include <vector>

/*
class Solution
{
  public:
    std::string
    longestPalindrome (std::string s)
    {
        std::string palindrome;

        int size = s.size ();
        if (size == 0)
            return std::string ("");
        else if (size == 1)
            return s;

        for (int i = 0; i < s.size (); i++)
            {
                for (int j = s.size () - 1; j > i; j--)
                    {
                        std::string possible_palindrome
                            = s.substr (i, j - i + 1);
                        std::size_t possible_palindrome_size
                            = possible_palindrome.size ();

                        bool possible_valid = true;

                        if (possible_palindrome_size % 2 == 0)
                            {
                                int middle_low = std::floor (
                                    possible_palindrome_size / 2.0);
                                auto st_it = possible_palindrome.begin ();
                                auto st_it_loop = possible_palindrome.begin ();
                                auto en_it_loop
                                    = possible_palindrome.end () - 1;
                                bool loop = true, last = false;
                                while (loop)
                                    {
                                        if (*st_it_loop != *en_it_loop)
                                            {
                                                possible_valid = false;
                                                break;
                                            }
                                        st_it_loop++;
                                        en_it_loop--;
                                        if (last)
                                            loop = false;
                                        last = st_it_loop
                                               == (st_it + middle_low);
                                    }
                            }
                        else
                            {
                                auto st_it = possible_palindrome.begin ();
                                auto en_it = possible_palindrome.end () - 1;
                                bool loop = true, last = false;
                                while (loop)
                                    {
                                        if (*st_it != *en_it)
                                            {
                                                possible_valid = false;
                                                break;
                                            }
                                        st_it++;
                                        en_it--;
                                        if (last)
                                            loop = false;
                                        last = (st_it == en_it);
                                    }
                            }
                        if (possible_valid
                            && palindrome.size () < possible_palindrome_size)
                            {
                                palindrome = possible_palindrome;
                            }

                        if ((j - i) <= palindrome.size ())
                            {
                                j = i;
                            }
                    }
            }

        if (palindrome.size () == 0)
            {
                std::string to_return;
                to_return += s[0];
                return to_return;
            }
        else
            {
                return palindrome;
            }
    }
};
*/
class Solution
{
  public:
    std::string
    longestPalindrome (std::string s)
    {
        int N = s.size ();
        if (N == 0)
            return std::string ("");
        if (N == 1)
            return s;
        N = 2 * N + 1; // Position count
        int L[N];      // LPS Length Array
        L[0] = 0;
        L[1] = 1;
        int C = 1;   // centerPosition
        int R = 2;   // centerRightPosition
        int i = 0;   // currentRightPosition
        int iMirror; // currentLeftPosition
        int maxLPSLength = 0;
        int maxLPSCenterPosition = 0;
        int start = -1;
        int end = -1;
        int diff = -1;

        for (i = 2; i < N; i++)
            {
                iMirror = 2 * C - i;
                L[i] = 0;
                diff = R - i;
                if (diff > 0)
                    L[i] = std::min (L[iMirror], diff);

                while (
                    ((i + L[i]) < N && (i - L[i]) > 0)
                    && (((i + L[i] + 1) % 2 == 0)
                        || (s[(i + L[i] + 1) / 2] == s[(i - L[i] - 1) / 2])))
                    {
                        L[i]++;
                    }

                if (L[i] > maxLPSLength)
                    {
                        maxLPSLength = L[i];
                        maxLPSCenterPosition = i;
                    }

                if (i + L[i] > R)
                    {
                        C = i;
                        R = i + L[i];
                    }
            }
        start = (maxLPSCenterPosition - maxLPSLength) / 2;
        end = start + maxLPSLength - 1;
        std::string result;
        for (i = start; i <= end; i++)
            result += s[i];

        if (result.size () == 0)
            {
                return std::string ("");
            }
        else
            {
                return result;
            }
    }
};

int
main ()
{
    Solution solution;

    std::vector<std::string> testInputs = {
        "babad",                 // Multiple palindromes, choose the longest
        "cbbd",                  // Shortest palindrome example
        "a",                     // Single character is a palindrome
        "",                      // Empty string
        "racecar",               // Full string palindrome
        "abacdfgdcaba",          // Multiple palindromes
        "abcd",                  // No palindrome longer than 1
        "aaaa",                  // Repeated characters
        "aabbcbbaa",             // Entire string is a palindrome
        "abcdefgfedcba",         // Full string palindrome
        "abcddcbaxyz",           // Longest is in the middle
        "xyzzyx",                // Palindrome at the start
        "abcdefg",               // No palindrome longer than 1
        "aabcdcbabcddcba",       // Multiple, longer palindrome in the middle
        "aaa",                   // All characters the same
        "aabcbaa",               // Symmetrical palindrome
        "civic",                 // Full string palindrome
        "deified",               // Full string palindrome
        "abcdefghhgfedcba",      // Long palindrome spanning the string
        "ghghghg",               // Alternating characters forming palindromes
        "palindrome",            // No palindrome longer than 1
        "abcdeffedcba",          // Full string palindrome with even length
        "abcdefghhgfed",         // Longest palindrome in the middle
        "abcdcbaaa",             // Longest is at the start
        "abcdefgh",              // No palindrome longer than 1
        "zzzzzzzzzz",            // All characters are the same
        "helloollehworld",       // Multiple palindromes, choose the longest
        "amanaplanacanalpanama", // Full string palindrome with spaces
                                 // ignored
        "aabbccddeeff",          // Only short palindromes
        "noonracecar",           // Multiple palindromes
        "rotator",               // Full string palindrome
        "qwertyuioppoiuytrewq",  // Full string palindrome
        "malayalam",             // Full string palindrome
        "abcdefghij",            // No palindrome longer than 1
        "level",                 // Full string palindrome
        "redivider",             // Full string palindrome
        "xyz",                   // No palindrome longer than 1
        "tattarrattat",          // Full string palindrome
        "abcdefghijjihgfedcba",  // Full string palindrome
        "aaaaaaa",               // Entire string palindrome of same characters
        "abcdefghijk",           // No palindrome longer than 1
        "ab",                    // No palindrome longer than 1
        "aaba",                  // Smallest palindrome
        "ac",                    // No palindrome longer than 1
        "banana",                // Longest palindrome in the middle
        "abababab",              // Longest at the end
        "zyx",                   // No palindrome longer than 1
        "xyzyx", "aacabdkacaa",
        "aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhh"
        "hhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooo"
        "oooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvv"
        "vvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxw"
        "wwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqq"
        "ppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjj"
        "jiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddcccccccc"
        "ccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeefffffffff"
        "fgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmm"
        "mmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttt"
        "tttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyy"
        "yyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrr"
        "rrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkk"
        "kkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddd"
        "dddddddccccccccccbbbbbbbbbbaaaa"

        // Palindrome in the middle
    };

    std::vector<std::string> expectedResults = {
        "bab",
        "bb",
        "a",
        "",
        "racecar",
        "aba",
        "a",
        "aaaa",
        "aabbcbbaa",
        "abcdefgfedcba",
        "abcddcba",
        "xyzzyx",
        "a",
        "abcddcba",
        "aaa",
        "aabcbaa",
        "civic",
        "deified",
        "abcdefghhgfedcba",
        "ghghghg",
        "p",
        "abcdeffedcba",
        "defghhgfed",
        "abcdcba",
        "a",
        "zzzzzzzzzz",
        "helloolleh",
        "amanaplanacanalpanama",
        "aa",
        "racecar",
        "rotator",
        "qwertyuioppoiuytrewq",
        "malayalam",
        "a",
        "level",
        "redivider",
        "x",
        "tattarrattat",
        "abcdefghijjihgfedcba",
        "aaaaaaa",
        "a",
        "a",
        "aba",
        "a",
        "anana",
        "abababa",
        "z",
        "xyzyx",
        "aca",
        "aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhh"
        "hhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnoooo"
        "ooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvv"
        "vvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxww"
        "wwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqp"
        "pppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjj"
        "iiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccc"
        "cbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffff"
        "gggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmm"
        "mnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrsssssssssstttttttt"
        "ttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyy"
        "yyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrr"
        "rrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkk"
        "kkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeedddd"
        "ddddddccccccccccbbbbbbbbbbaaaa"
    };

    for (size_t i = 0; i < testInputs.size (); ++i)
        {
            std::string result = solution.longestPalindrome (testInputs[i]);
            if (result == expectedResults[i])
                {
                    std::cout << "Test " << i + 1 << " GOOD.\n";
                }
            else
                {
                    std::cout << "Test " << i + 1
                              << " BAD \nInput: " << testInputs[i]
                              << "\nExpected: " << expectedResults[i]
                              << "\nGot: " << result << '\n';
                }
        }

    return 0;
}
