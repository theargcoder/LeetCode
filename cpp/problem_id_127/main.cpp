#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
 public:
   int
   ladderLength (std::string beginWord, std::string endWord,
                 std::vector<std::string> &wordList)
   {
      if (std::find (wordList.begin (), wordList.end (), endWord)
          == wordList.end ())
         return 0;

      const int n = wordList.size ();
      const int m = beginWord.size ();

      std::unordered_map<std::string, std::vector<std::string>> map;

      for (int i = 0; i < n; i++)
         {
            std::string word = wordList[i];
            for (int j = 0; j < m; j++)
               {
                  char c = word[j];
                  word[j] = '*';
                  map[word].push_back (wordList[i]);
                  word[j] = c;
               }
         }

      std::unordered_map<std::string, int> distance;
      std::queue<std::string> queue;

      queue.push (beginWord);
      distance[beginWord] = 1;

      while (!queue.empty ())
         {
            std::string s = queue.front ();
            queue.pop ();

            int dis = distance[s];

            for (int j = 0; j < m; j++)
               {
                  char c = s[j];
                  s[j] = '*';
                  for (auto &adj : map[s])
                     {
                        if (!distance.count (adj))
                           {
                              distance[adj] = dis + 1;
                              queue.push (adj);
                           }
                        else if (distance.count (endWord))
                           return distance.at (endWord);
                     }
                  s[j] = c;
               }
         }

      return (distance.count (endWord)) ? distance[endWord] : 0;
   }
};
