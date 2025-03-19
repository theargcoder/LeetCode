#include <algorithm>
#include <iostream>
#include <string>

// so close to wroking it hurts
/*
class Solution
{
  public:
    int
    longestValidParentheses (std::string s)
    {
        int size = s.size ();
        if (size < 2)
            return 0;
        int length = 0;
        std::vector<int> map;

        std::size_t start = s.find ('(', 0);
        if (start == std::string::npos)
            return 0;
        std::size_t closed_exists = s.find (')', 0);
        if (closed_exists == std::string::npos)
            return 0;

        int pending = -1;
        int pair = 0;

        for (int i = start; i < size; i++)
            {
                if (s[i] == '(')
                    {
                        if (i + 1 < size)
                            {
                                if (s[i + 1] == ')')
                                    {
                                        map.push_back (pair);
                                        i++;
                                    }
                                else
                                    {
                                        if (pending == -1)
                                            {
                                                map.push_back (pending);
                                                pending = 0;
                                            }
                                        pending++;
                                        map.push_back (pending);
                                    }
                            }
                        else
                            {
                                if (pending == -1)
                                    {
                                        map.push_back (pending);
                                        pending = 0;
                                    }
                                pending++;
                                map.push_back (pending);
                            }
                    }
                else
                    {
                        if (pending > 0)
                            {
                                map.push_back (pending);
                                pending--;
                            }
                        else if (pending == 0)
                            {
                                pending = -1;
                                map.push_back (pending);
                            }
                    }
            }

        return process_vector (map);
    }

  private:
    int
    decode_segment (std::vector<int> &arr, int seg_start, int seg_end)
    {
        int s = seg_start;
        if (arr[s] == -1)
            s++;

        int e = seg_end;
        if (arr[e] == -1)
            e--;

        if (s > e)
            return 0;

        std::unordered_map<int, std::vector<int> > occurrences;

        // Step 1: Store occurrences of each nonzero number
        for (int i = s; i <= e; i++)
            {
                if (arr[i] != 0)
                    {
                        occurrences[arr[i]].push_back (i);
                    }
            }

        int best_sum = 0;

        for (auto &entry : occurrences)
            {
                const std::vector<int> &indices = entry.second;
                int count = indices.size ();

                if (count < 2)
                    continue; // No valid pair

                int first_index = -1, last_index = -1;
                int max_first_index = -1, max_last_index = -1;
                int max_distance = 0;

                for (int i = 0; i < count - 1; i += 2)
                    {
                        int left = indices[i];
                        int right = indices[i + 1];

                        if (first_index == -1)
                            {
                                // First valid pair: start a new chain.
                                first_index = left;
                                last_index = right;
                            }
                        else
                            {
                                // Check the gap between the current chain’s
                                // end and the new pair’s start.
                                bool gap_allows_concat = true;
                                for (int k = last_index; k < left; k++)
                                    {
                                        // If any element in the gap is nonzero
                                        // and less than entry.first, the gap
                                        // is not acceptable.
                                        if (arr[k] != 0
                                            && arr[k] < entry.first)
                                            {
                                                gap_allows_concat = false;
                                                break;
                                            }
                                    }

                                if (gap_allows_concat)
                                    {
                                        // The gap is acceptable — extend the
                                        // current chain.
                                        last_index = right;
                                    }
                                else
                                    {
                                        // The gap does not allow
                                        // concatenation. "Commit" the current
                                        // chain by updating max-chain
                                        // variables if needed.
                                        int current_chain_distance
                                            = last_index - first_index;
                                        if (current_chain_distance
                                            > max_distance)
                                            {
                                                max_distance
                                                    = current_chain_distance;
                                                max_first_index = first_index;
                                                max_last_index = last_index;
                                            }
                                        // Start a new chain with the current
                                        // pair.
                                        first_index = left;
                                        last_index = right;
                                    }
                            }

                        // After handling this pair, update the max chain
                        // variables if the current chain is longer.
                        int current_chain_distance = last_index - first_index;
                        if (current_chain_distance > max_distance)
                            {
                                max_distance = current_chain_distance;
                                max_first_index = first_index;
                                max_last_index = last_index;
                            }
                    }

                if (first_index == -1)
                    continue;

                // Extend segment with zeros on both sides
                int ext_start = max_first_index;
                while (ext_start > s && arr[ext_start - 1] == 0)
                    ext_start--;

                int ext_end = max_last_index;
                while (ext_end < e && arr[ext_end + 1] == 0)
                    ext_end++;

                // Ensure we select the correct range based on expected sum
                int current_sum = 0;
                for (int i = ext_start; i <= ext_end; i++)
                    {
                        current_sum += (arr[i] == 0) ? 2 : 1;
                    }

                best_sum = std::max (best_sum, current_sum);
            }

        // If no valid segment found, find max run of zeros
        if (best_sum == 0)
            {
                int max_zero_run = 0, current_zero_run = 0;
                for (int i = s; i <= e; i++)
                    {
                        if (arr[i] == 0)
                            {
                                current_zero_run++;
                                max_zero_run = std::max (max_zero_run,
                                                         current_zero_run);
                            }
                        else
                            {
                                current_zero_run = 0;
                            }
                    }
                best_sum = max_zero_run * 2;
            }

        return best_sum;
    }

    int
    process_vector (std::vector<int> &vec)
    {
        int max_result = 0;
        int pos = 0;
        int n = static_cast<int> (vec.size ());

        while (pos < n)
            {
                int seg_start = pos;
                int seg_end = pos;
                if (vec[seg_start] == -1)
                    {
                        bool found = false;
                        for (int i = seg_start + 1; i < n; i++)
                            {
                                if (vec[i] == -1)
                                    {
                                        seg_end = i;
                                        found = true;
                                        break;
                                    }
                            }
                        if (!found)
                            seg_end = n - 1;
                    }
                else
                    {
                        int i;
                        for (i = seg_start; i < n; i++)
                            {
                                if (vec[i] == -1)
                                    break;
                            }
                        seg_end = (i < n) ? i : n - 1;
                    }

                int current_sum = decode_segment (vec, seg_start, seg_end);
                max_result = std::max (max_result, current_sum);
                pos = seg_end + 1;
            }
        return max_result;
    }
};
*/

class Solution
{
  public:
    int
    longestValidParentheses (std::string s)
    {
        int size = s.size ();
        if (size < 2)
            return 0;
        int length = 0;
        std::vector<int> map;

        std::size_t start = s.find ('(', 0);
        if (start == std::string::npos)
            return 0;
        std::size_t closed_exists = s.find (')', 0);
        if (closed_exists == std::string::npos)
            return 0;

        int pending = 0;
        int pair = 0;

        for (int i = start; i < size; i++)
            {
                if (s[i] == '(')
                    {
                        if (i + 1 < size)
                            {
                                if (s[i + 1] == ')')
                                    {
                                        map.push_back (pair);
                                        i++;
                                    }
                                else
                                    {
                                        pending++;
                                        map.push_back (pending);
                                    }
                            }
                        else
                            {
                                pending++;
                                map.push_back (pending);
                            }
                    }
                else
                    {
                        if (pending > 0)
                            {
                                map.push_back (pending);
                                pending--;
                            }
                        else
                            {
                                map.push_back (-1);
                            }
                    }
            }

        return process_vector (map);
    }

  private:
    int
    decode_segment (std::vector<int> &arr, int seg_start, int seg_end)
    {
        int s = seg_start;
        if (arr[s] == -1)
            s++;

        int e = seg_end;
        if (arr[e] == -1)
            e--;

        if (s > e)
            return 0;

        std::unordered_map<int, std::vector<int> > occurrences;

        // Step 1: Store occurrences of each nonzero number
        for (int i = s; i <= e; i++)
            {
                if (arr[i] != 0)
                    {
                        occurrences[arr[i]].push_back (i);
                    }
            }

        int best_sum = 0;

        for (auto &entry : occurrences)
            {
                const std::vector<int> &indices = entry.second;
                int count = indices.size ();

                if (count < 2)
                    continue; // No valid pair

                int first_index = -1, last_index = -1;
                int max_first_index = -1, max_last_index = -1;
                int max_distance = 0;

                for (int i = 0; i < count - 1; i += 2)
                    {
                        int left = indices[i];
                        int right = indices[i + 1];

                        if (first_index == -1)
                            {
                                // First valid pair: start a new chain.
                                first_index = left;
                                last_index = right;
                            }
                        else
                            {
                                // Check the gap between the current chain’s
                                // end and the new pair’s start.
                                bool gap_allows_concat = true;
                                for (int k = last_index; k < left; k++)
                                    {
                                        // If any element in the gap is nonzero
                                        // and less than entry.first, the gap
                                        // is not acceptable.
                                        if (arr[k] != 0
                                            && arr[k] < entry.first)
                                            {
                                                gap_allows_concat = false;
                                                break;
                                            }
                                    }

                                if (gap_allows_concat)
                                    {
                                        // The gap is acceptable — extend the
                                        // current chain.
                                        last_index = right;
                                    }
                                else
                                    {
                                        // The gap does not allow
                                        // concatenation. "Commit" the current
                                        // chain by updating max-chain
                                        // variables if needed.
                                        int current_chain_distance
                                            = last_index - first_index;
                                        if (current_chain_distance
                                            > max_distance)
                                            {
                                                max_distance
                                                    = current_chain_distance;
                                                max_first_index = first_index;
                                                max_last_index = last_index;
                                            }
                                        // Start a new chain with the current
                                        // pair.
                                        first_index = left;
                                        last_index = right;
                                    }
                            }

                        // After handling this pair, update the max chain
                        // variables if the current chain is longer.
                        int current_chain_distance = last_index - first_index;
                        if (current_chain_distance > max_distance)
                            {
                                max_distance = current_chain_distance;
                                max_first_index = first_index;
                                max_last_index = last_index;
                            }
                    }

                if (first_index == -1)
                    continue;

                // Extend segment with zeros on both sides
                int ext_start = max_first_index;
                while (ext_start > s && arr[ext_start - 1] == 0)
                    ext_start--;

                int ext_end = max_last_index;
                while (ext_end < e && arr[ext_end + 1] == 0)
                    ext_end++;

                // Ensure we select the correct range based on expected sum
                int current_sum = 0;
                for (int i = ext_start; i <= ext_end; i++)
                    {
                        current_sum += (arr[i] == 0) ? 2 : 1;
                    }

                best_sum = std::max (best_sum, current_sum);
            }

        // If no valid segment found, find max run of zeros
        if (best_sum == 0)
            {
                int max_zero_run = 0, current_zero_run = 0;
                for (int i = s; i <= e; i++)
                    {
                        if (arr[i] == 0)
                            {
                                current_zero_run++;
                                max_zero_run = std::max (max_zero_run,
                                                         current_zero_run);
                            }
                        else
                            {
                                current_zero_run = 0;
                            }
                    }
                best_sum = max_zero_run * 2;
            }

        return best_sum;
    }

    int
    process_vector (std::vector<int> &vec)
    {
        int max_result = 0;
        int pos = 0;
        int n = static_cast<int> (vec.size ());

        while (pos < n)
            {
                int seg_start = pos;
                int seg_end = pos;
                if (vec[seg_start] == -1)
                    {
                        bool found = false;
                        for (int i = seg_start + 1; i < n; i++)
                            {
                                if (vec[i] == -1)
                                    {
                                        seg_end = i;
                                        found = true;
                                        break;
                                    }
                            }
                        if (!found)
                            seg_end = n - 1;
                    }
                else
                    {
                        int i;
                        for (i = seg_start; i < n; i++)
                            {
                                if (vec[i] == -1)
                                    break;
                            }
                        seg_end = (i < n) ? i : n - 1;
                    }

                int current_sum = decode_segment (vec, seg_start, seg_end);

                max_result = std::max (max_result, current_sum);
                pos = seg_end + 1;
            }
        return max_result;
    }
};
