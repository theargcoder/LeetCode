#include <iostream>
#include <numeric>
#include <vector>

/*
class Solution
{
  public:
    std::vector<int>
    findSubstring (std::string s, std::vector<std::string> &words)
    {
        int words_size = words.size ();
        int s_size = s.size ();
        int ind_word_size = words[0].size ();
        if (s_size < ind_word_size)
            return {};

        if ((s_size) < (words_size * ind_word_size))
            return {};

        std::vector<int> result;

        std::unordered_map<int, bool> eliminated;
        for (int x = 0; x < words_size; x++)
            {
                eliminated[x] = false;
            }

        for (int i = 0; i < s_size; i++)
            {
                std::string first_word = s.substr (i, ind_word_size);
                auto found
                    = std::find (words.begin (), words.end (), first_word);
                if (found != words.end ())
                    {
                        int to_eliminate
                            = std::distance (words.begin (), found);
                        eliminated[to_eliminate] = true;

                        for (int x = i + ind_word_size; x < s_size;
                             x += ind_word_size)
                            {
                                std::string loop_word
                                    = s.substr (x, ind_word_size);
                                bool kill = false;
                                find_algo (words, eliminated, loop_word, 0,
                                           kill);
                                if (kill)
                                    break;
                            }
                        bool valid = true;
                        for (auto pair : eliminated)
                            {
                                if (!pair.second)
                                    {
                                        valid = false;
                                        break;
                                    }
                            }
                        if (valid)
                            {
                                result.push_back (i);
                            }
                        for (int x = 0; x < words_size; x++)
                            {
                                eliminated[x] = false;
                            }
                    }
            }
        return result;
    }

  private:
    void
    find_algo (std::vector<std::string> &words,
               std::unordered_map<int, bool> &eliminated, std::string &word,
               int extra_distance, bool &kill)
    {
        auto loop_found
            = std::find (words.begin () + extra_distance, words.end (), word);
        if (loop_found != words.end ())
            {
                int loop_found_distance
                    = std::distance (words.begin (), loop_found);
                if (eliminated[loop_found_distance])
                    {
                        find_algo (words, eliminated, word,
                                   loop_found_distance + 1,
                                   kill); // we cant have repeats but we need
                                          // to make sure
                    }
                else
                    {
                        eliminated[loop_found_distance] = true;
                    }
            }
        else
            {
                kill = true; // this isnt valid permutation
                             // since subst isnt in words
            }
    };
};
*/

using namespace std;

class Solution
{
  public:
    vector<int>
    findSubstring (string s, vector<string> &words)
    {
        int words_size = words.size ();
        int s_size = s.size ();
        int ind_word_size = words[0].size ();
        if (s_size < ind_word_size)
            return {};

        if ((s_size) < (words_size * ind_word_size))
            return {};

        const int k = words.size ();
        const int n = words[0].length ();
        vector<int> ans;
        unordered_map<string, int> count;

        for (const string &word : words)
            ++count[word];

        for (int i = 0; i < s.length () - k * n + 1; ++i)
            {
                unordered_map<string, int> seen;
                int j;
                for (j = 0; j < k; ++j)
                    {
                        const string &word = s.substr (i + j * n, n);
                        if (++seen[word] > count[word])
                            break;
                    }
                if (j == k)
                    ans.push_back (i);
            }

        return ans;
    }
};
