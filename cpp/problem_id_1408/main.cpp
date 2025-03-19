#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution
{
  public:
    std::vector<std::string>
    stringMatching (std::vector<std::string> &words)
    {
        std::vector<std::string> vector_to_return;

        std::vector<std::string> temp = words;

        std::sort (temp.begin (), temp.end ());

        int size = temp.size ();

        std::map<std::string, std::string> temp_map;

        for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    if (words[i] != temp[j])
                        {
                            const auto pos = words[i].find (temp[j], 0);
                            if (pos != std::string::npos)
                                {
                                    temp_map.insert (
                                        std::pair<std::string, std::string> (
                                            temp[j], temp[j]));
                                }
                        }
            }

        for (auto pair : temp_map)
            vector_to_return.push_back (pair.first);

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
