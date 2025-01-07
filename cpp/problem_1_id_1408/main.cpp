#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    std::vector<std::string>
    stringMatching (std::vector<std::string> &words)
    {
        std::vector<std::string> vector_to_return;
        auto iterator = words.begin ();
        auto end = words.end ();

        while (iterator != end)
            {
                std::string *iterator_ptr = &*iterator;
                for (auto j : words)
                    if (j != *iterator_ptr)
                        if (iterator_ptr->find (j) != std::string::npos)
                            {
                                bool repeted = false;
                                for (auto p : vector_to_return)
                                    if (p == j)
                                        repeted = true;
                                if (!repeted)
                                    vector_to_return.push_back (j);
                            }
                iterator++;
            }

        return std::move (vector_to_return);
    }
};

int
main ()
{
    std::vector<std::string> words;
    words.push_back ("leetcode");
    words.push_back ("as");
    words.push_back ("hero");
    words.push_back ("superhero");
    Solution solved;

    std::vector<std::string> words_solved = solved.stringMatching (words);

    for (auto i : words_solved)
        {
            std::cout << i << '\n';
        }
};
