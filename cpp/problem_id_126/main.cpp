#include <algorithm>
#include <array>
#include <climits>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// working but time limit exceeded :(

/*
class Solution
{
 public:
   std::vector<std::vector<std::string>>
   findLadders (std::string beginWord, std::string endWord,
                std::vector<std::string> &wordList)
   {
      auto beg = std::find (wordList.begin (), wordList.end (), beginWord);
      auto end = std::find (wordList.begin (), wordList.end (), endWord);

      if (end == wordList.end ())
         return {};

      const int n = wordList.size ();
      const int m = wordList[0].size ();

      std::vector<bool> used (n, false);
      std::vector<std::string> tt;
      std::vector<std::vector<std::string>> res;

      int ct = 0, minsize = INT_MAX;
      if (beg != wordList.end ())
         {
            tt.push_back (beginWord);
            used[std::distance (wordList.begin (), beg)] = true;
            dfs (wordList, endWord, n, m, ct, minsize, tt, res, used, *beg);
         }
      else
         {
            tt.push_back (beginWord);
            dfs (wordList, endWord, n, m, ct, minsize, tt, res, used,
                 beginWord);
         }

      return res;
   }

 private:
   void
   dfs (const std::vector<std::string> &wordList, const std::string &endWord,
        const int &n, const int &m, int &ct, int &minsize,
        std::vector<std::string> &tt,
        std::vector<std::vector<std::string>> &res, std::vector<bool> &used,
        const std::string &prev)
   {
      if (tt.back () == endWord)
         {
            if (tt.size () < minsize)
               {
                  res.clear ();
                  minsize = tt.size ();
               }
            if (tt.size () == minsize)
               res.push_back (tt);
            return;
         }
      else if (ct >= n)
         {
            return;
         }

      int ctint;

      for (int i = 0; i < n; i++)
         {
            if (used[i])
               continue;
            ctint = 0;
            for (int j = 0; j < m; j++)
               if (prev[j] != wordList[i][j])
                  ctint++;

            if (ctint != 1)
               continue;

            tt.push_back (wordList[i]);
            used[i] = true;
            ct++;
            dfs (wordList, endWord, n, m, ct, minsize, tt, res, used,
                 wordList[i]);
            ct--;
            used[i] = false;
            tt.pop_back ();
         }
   };
};
*/

// takes way too long
/*
class Solution
{
 public:
   std::vector<std::vector<std::string>>
   findLadders (std::string beginWord, std::string endWord,
                std::vector<std::string> &wordList)
   {
      auto beg = std::find (wordList.begin (), wordList.end (), beginWord);
      auto end = std::find (wordList.begin (), wordList.end (), endWord);

      if (end == wordList.end ())
         return {};

      const int n = wordList.size ();
      const int m = wordList[0].size ();

      std::vector<std::vector<std::string>> res;

      std::unordered_map<std::string, std::vector<std::string>> map;

      std::unordered_map<std::string, bool> used;
      int ct;
      for (int j = 0; j < n; j++)
         {
            ct = 0;
            for (int k = 0; k < m; k++)
               if (beginWord[k] != wordList[j][k])
                  ct++;

            if (ct != 1)
               continue;

            map[beginWord].push_back (wordList[j]);
         }

      for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < n; j++)
               {
                  if (i == j)
                     continue;

                  ct = 0;
                  for (int k = 0; k < m; k++)
                     if (wordList[i][k] != wordList[j][k])
                        ct++;

                  if (ct != 1)
                     continue;

                  map[wordList[i]].push_back (wordList[j]);
               }
         }

      int min = 500; // its the max wordList size...
      ct = 0;

      std::vector<std::string> tt{ beginWord };

      explore (map, endWord, used, n, tt, res, min, ct, beginWord);

      return res;
   }

 private:
   void
   explore (
       const std::unordered_map<std::string, std::vector<std::string>> &map,
       const std::string &endWord, std::unordered_map<std::string, bool> &used,
       const int &n, std::vector<std::string> &tt,
       std::vector<std::vector<std::string>> &res, int &min, int &ct,
       const std::string &lst)
   {
      if (tt.back () == endWord)
         {
            if (tt.size () < min)
               {
                  res.clear ();
                  min = tt.size ();
               }
            if (tt.size () == min)
               res.push_back (tt);
            return;
         }
      else if (ct >= n)
         return;

      for (const std::string &s : map.at (lst))
         {
            if (used[s])
               continue;

            used[s] = true;
            ct++;
            tt.push_back (s);
            explore (map, endWord, used, n, tt, res, min, ct, s);
            tt.pop_back ();
            ct--;
            used[s] = false;
         }
   }
};
*/

// FAST but NOT GOOD ENOUGH BRUHHH
/*
class Solution
{
 private:
   long
   hash (const std::string &str) const
   {
      long hash = 0;
      for (int i = 0; i < str.size (); i++)
         {
            hash += static_cast<long> (str[i]) << (i * 8);
         }
      return hash;
   }

 public:
   std::vector<std::vector<std::string>>
   findLadders (std::string beginWord, std::string endWord,
                std::vector<std::string> &wordList)
   {
      if (std::find (wordList.begin (), wordList.end (), endWord)
          == wordList.end ())
         return {};

      const int n = wordList.size ();
      const int m = wordList[0].size ();
      std::vector<std::vector<long>> res;
      std::unordered_map<long, std::vector<long>> map;
      std::unordered_map<long, long> hashtable;

      for (int i = 0; i < n; i++)
         {
            long hsh = hash (wordList[i]);
            hashtable[i] = hsh;
         }

      long beghsh = hash (beginWord);

      for (int i = 0; i < n; i++)
         {
            int diff = 0;
            for (int k = 0; k < m; k++)
               if (beginWord[k] != wordList[i][k])
                  diff++;
            if (diff == 1)
               map[beghsh].push_back (hashtable[i]);
         }

      for (int i = 0; i < n; i++)
         {
            if (beghsh == hashtable[i])
               continue;
            for (int j = 0; j < n; j++)
               {
                  if (i == j || beginWord == wordList[j])
                     continue;
                  int diff = 0;
                  for (int k = 0; k < m; k++)
                     if (wordList[i][k] != wordList[j][k])
                        diff++;
                  if (diff == 1)
                     map[hashtable[i]].push_back (hashtable[j]);
               }
         }

      std::unordered_map<long, int> level;
      std::queue<long> q;
      level[beghsh] = 0;
      q.push (beghsh);

      while (!q.empty ())
         {
            long word = q.front ();
            q.pop ();
            for (const long &next : map[word])
               {
                  if (!level.count (next))
                     {
                        level[next] = level[word] + 1;
                        q.push (next);
                     }
               }
         }

      std::vector<long> path{ beghsh };

      explore (map, level, hash (endWord), path, res, beghsh);

      std::vector<std::vector<std::string>> resres;

      for (auto &vec : res)
         {
            std::vector<std::string> ttpu;
            for (long &i : vec)
               ttpu.push_back (wordList[hashtable[i]]);
            resres.push_back (ttpu);
         }

      return resres;
   }

 private:
   void
   explore (const std::unordered_map<long, std::vector<long>> &map,
            const std::unordered_map<long, int> &level, const long &endWord,
            std::vector<long> &path, std::vector<std::vector<long>> &res,
            const long &curr)
   {
      if (curr == endWord)
         {
            res.push_back (path);
            return;
         }

      for (const long &next : map.at (curr))
         {
            if (level.count (next) && level.at (next) == level.at (curr) + 1)
               {
                  path.push_back (next);
                  explore (map, level, endWord, path, res, next);
                  path.pop_back ();
               }
         }
   }
};
*/

/*
class Solution
{
 public:
   std::vector<std::vector<std::string>>
   findLadders (std::string beginWord, std::string endWord,
                std::vector<std::string> &wordList)
   {
      std::unordered_map<
          std::string, std::pair<std::vector<std::string>, std::vector<bool>>>
          map;

      for (const std::string &word : wordList)
         {
            for (int i = 0; i < word.size (); i++)
               {
                  std::string pattern = word;
                  pattern[i] = '*'; // replace one char with '*'
                  map[pattern].first.push_back (word);
                  map[pattern].second.push_back (false);
               }
         }
      if (map[beginWord].first.empty ())
         {
            for (int i = 0; i < beginWord.size (); i++)
               {
                  std::string pattern = beginWord;
                  pattern[i] = '*';
                  map[pattern].first.push_back (beginWord);
                  map[pattern].second.push_back (false);
               }
         }

      const int n = wordList.size ();
      int min = INT_MAX;

      std::vector<std::vector<std::string>> res;

      std::vector<std::string> tt{ beginWord };

      explore (map, tt, res, n, endWord, min, beginWord);

      return res;
   }

 private:
   void
   explore (std::unordered_map<std::string, std::pair<std::vector<std::string>,
                                                      std::vector<bool>>> &map,
            std::vector<std::string> &tt,
            std::vector<std::vector<std::string>> &res, const int &n,
            const std::string &endWord, int &min, const std::string &last)
   {
      if (tt.size () >= n)
         return;
      else if (last == endWord)
         {
            if (tt.size () < min)
               {
                  res.clear ();
                  min = tt.size ();
               }
            if (tt.size () == min)
               res.push_back (tt);

            return;
         }

      const auto &here = map[last];

      const int m = here.second.size ();

      for (int i = 0; i < m; i++)
         {
            if (!here.second[i])
               continue;
            map[last].second[i] = true;
            tt.push_back (here.first[i]);
            explore (map, tt, res, n, endWord, min, here.first[i]);
            tt.pop_back ();
            map[last].second[i] = true;
         }
   }
};
*/

class Solution
{
 public:
   std::vector<std::vector<std::string>>
   findLadders (std::string beginWord, std::string endWord,
                std::vector<std::string> &wordList)
   {
      std::unordered_set<std::string> dict (wordList.begin (),
                                            wordList.end ());
      if (!dict.count (endWord))
         return {};

      // Step 1: Build adjacency list using pattern matching
      std::unordered_map<std::string, std::vector<std::string>> patternMap;
      int wordLen = beginWord.size ();
      auto getPatterns = [&] (const std::string &word) {
         std::vector<std::string> patterns;
         for (int i = 0; i < wordLen; ++i)
            {
               std::string pattern = word;
               pattern[i] = '*';
               patterns.push_back (pattern);
            }
         return patterns;
      };

      for (const std::string &word : dict)
         {
            for (const std::string &pattern : getPatterns (word))
               {
                  patternMap[pattern].push_back (word);
               }
         }

      // Step 2: BFS to find shortest paths & build parent graph
      std::unordered_map<std::string, std::vector<std::string>> parents;
      std::unordered_map<std::string, int> distance;
      std::queue<std::string> q;

      q.push (beginWord);
      distance[beginWord] = 0;

      while (!q.empty ())
         {
            std::string word = q.front ();
            q.pop ();

            int currDist = distance[word];

            for (const std::string &pattern : getPatterns (word))
               {
                  for (const std::string &neighbor : patternMap[pattern])
                     {
                        if (!distance.count (neighbor))
                           {
                              distance[neighbor] = currDist + 1;
                              q.push (neighbor);
                              parents[neighbor].push_back (word);
                           }
                        else if (distance[neighbor] == currDist + 1)
                           {
                              parents[neighbor].push_back (word);
                           }
                     }
               }
         }

      // Step 3: Backtrack all shortest paths
      std::vector<std::vector<std::string>> results;
      std::vector<std::string> path;

      if (distance.count (endWord))
         backtrack (endWord, beginWord, parents, path, results);

      return results;
   }

 private:
   void
   backtrack (
       const std::string &word, const std::string &beginWord,
       std::unordered_map<std::string, std::vector<std::string>> &parents,
       std::vector<std::string> &path,
       std::vector<std::vector<std::string>> &results)
   {
      path.push_back (word);

      if (word == beginWord)
         {
            std::vector<std::string> temp = path;
            std::reverse (temp.begin (), temp.end ());
            results.push_back (temp);
         }
      else
         {
            for (const std::string &parent : parents[word])
               backtrack (parent, beginWord, parents, path, results);
         }

      path.pop_back ();
   }
};
