#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
  bool wordPattern(const std::string &pattern, const std::string &s)
  {
    std::unordered_map<char, std::string_view> map;
    std::unordered_set<std::string_view> unique;

    const size_t size = s.size();
    size_t ptr = 0;
    size_t n_ptr = 0;

    for(const char &ch : pattern)
    {
      if(n_ptr >= size)
        return false;

      for(; ptr < size && s[ptr] == ' '; ptr++)
      {
      }

      n_ptr = ptr;
      for(; n_ptr < size && s[n_ptr] != ' '; n_ptr++)
      {
      }
      auto found = map.find(ch);
      std::string_view this_word = std::string_view(s.data() + ptr, n_ptr - ptr);
      if(found == map.end())
      {
        if(unique.contains(this_word))
        {
          return false;
        }
        unique.insert(this_word);
        map[ch] = this_word;
      }
      else
      {
        if(found->second != this_word)
        {
          return false;
        }
      }

      ptr = n_ptr;
    }

    return n_ptr == ptr && ptr == size;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.wordPattern("abba", "dog cat cat dog");
  const auto res_2 = sol.wordPattern("he", "unit");
  return 0;
}
