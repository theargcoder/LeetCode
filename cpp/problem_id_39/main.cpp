#include <iostream>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// FULLY FUNCTIONAL BUT INEFFICIENT
/*
class Solution
{
  public:
    std::vector<std::vector<int> >
    combinationSum (std::vector<int> &candidates, int target)
    {
        std::unordered_set<int> avaliable;
        for (int &pnt : candidates)
            {
                avaliable.insert (pnt);
            }
        std::vector<std::vector<int> > to_ret;

        int size = candidates.size ();
        int left = 0, right = target;

        if (avaliable.count (target) != 0)
            {
                to_ret.push_back ({ target });
            }

        std::vector<int> carr;

        recurse (to_ret, carr, false, avaliable, left, right);

        return to_ret;
    }

  private:
    std::unordered_set<size_t> hashes;

  private:
    void
    recurse (std::vector<std::vector<int> > &to_ret, std::vector<int> &carry,
             bool we_carried, const std::unordered_set<int> &avaliable,
             int &left, int &right)
    {
        left++;
        right--;

        if (left > right)
            return;

        if (avaliable.count (left) != 0 && avaliable.count (right) != 0)
            {
                if (we_carried)
                    {
                        std::vector<int> vec_to_push (carry.begin (),
                                                      carry.end ());
                        vec_to_push.push_back (left);
                        vec_to_push.push_back (right);
                        size_t hash = hashVectorUnordered (vec_to_push);
                        if (hashes.count (hash) == 0)
                            {
                                to_ret.push_back (std::move (vec_to_push));
                                hashes.insert (hash);
                            }
                        int n1_left = 0, n1_right = right;
                        carry.push_back(left);
                        recurse (to_ret, carry, true, avaliable, n1_left,
                                 n1_right);
                        carry.pop_back();
                    }
                else
                    {
                        to_ret.push_back ({ left, right });
                        int n1_left = 0, n1_right = right;
                        std::vector<int> l_carr = { left };
                        recurse (to_ret, l_carr, true, avaliable, n1_left,
                                 n1_right);
                        if (left >= 4)
                            {
                                int n2_left = 0, n2_right = left;
                                std::vector<int> l_carr = { right };
                                recurse (to_ret, l_carr, true, avaliable,
                                         n1_left, n1_right);
                            }
                    }
            }
        else if (avaliable.count (left) != 0 && avaliable.count (right) == 0)
            {
                if (we_carried)
                    {
                        carry.push_back (left);
                        int n1_left = 0, n1_right = right;
                        recurse (to_ret, carry, true, avaliable, n1_left,
                                 n1_right);
                        carry.pop_back ();
                    }
                else
                    {
                        std::vector<int> l_carr{ left };
                        int n1_left = 0, n1_right = right;
                        recurse (to_ret, l_carr, true, avaliable, n1_left,
                                 n1_right);
                    }
            }
        else if (avaliable.count (right) != 0 && avaliable.count (left) == 0)
            {
                if (left >= 4)
                    {
                        if (we_carried)
                            {
                                carry.push_back (right);
                                int n1_left = 0, n1_right = left;
                                recurse (to_ret, carry, true, avaliable,
                                         n1_left, n1_right);
                                carry.pop_back ();
                            }
                        else
                            {
                                std::vector<int> l_carr{ right };
                                int n1_left = 0, n1_right = left;
                                recurse (to_ret, l_carr, true, avaliable,
                                         n1_left, n1_right);
                            }
                    }
            }

        recurse (to_ret, carry, we_carried, avaliable, left, right);
    }
    // Custom hash function that is order-independent for a vector<int>
    size_t
    hashVectorUnordered (const std::vector<int> &vec)
    {
        // Count frequencies of each element
        std::unordered_map<int, int> freq;
        for (int num : vec)
            {
                freq[num]++;
            }

        // Move frequency counts to a vector of pairs for deterministic
        // ordering.
        std::vector<std::pair<int, int> > freqPairs (freq.begin (),
                                                     freq.end ());
        // Sort the pairs by the element value (the key)
        std::sort (
            freqPairs.begin (), freqPairs.end (),
            [] (const std::pair<int, int> &a, const std::pair<int, int> &b) {
                return a.first < b.first;
            });

        // Combine the hash values of each (element, frequency) pair.
        // This approach is similar to boost::hash_combine.
        size_t hash_value = 0;
        for (const auto &p : freqPairs)
            {
                size_t h1 = std::hash<int>{}(p.first);
                size_t h2 = std::hash<int>{}(p.second);
                hash_value
                    ^= h1 + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
                hash_value
                    ^= h2 + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
            }
        return hash_value;
    }
};
*/

// properly implemented backtracking LOL
class Solution
{
  public:
    std::vector<std::vector<int> >
    combinationSum (std::vector<int> &candidates, int target)
    {
        std::sort (candidates.begin (), candidates.end ());
        std::vector<std::vector<int> > result;
        std::vector<int> current;
        backtrack (candidates, target, 0, current, result);
        return result;
    }

  private:
    void
    backtrack (const std::vector<int> &candidates, int target, int start,
               std::vector<int> &current,
               std::vector<std::vector<int> > &result)
    {
        if (target == 0)
            {
                result.push_back (current);
                return;
            }
        for (int i = start; i < candidates.size () && candidates[i] <= target;
             i++)
            {
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;
                current.push_back (candidates[i]);
                backtrack (candidates, target - candidates[i], i, current,
                           result);
                current.pop_back ();
            }
    }
};
