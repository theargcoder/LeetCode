#include <array>
#include <string>
#include <unordered_map>
#include <vector>

// nice submission 31 ms in the 92% beaten
class Solution
{
public:
  std::vector<std::string> findRepeatedDnaSequences(const std::string &s)
  {
    const unsigned size = s.size();

    std::vector<std::string> vec;
    std::unordered_map<std::string_view, unsigned> unique;

    vec.reserve(unique.size());

    for(unsigned i = 0, j = 9; j < size; i++, j++)
    {
      const auto view = std::string_view(&s[i], 10);
      if(unique.count(view) == 0)
      {
        unique[view] = 1;
      }
      else if(unique[view] == 1)
      {
        vec.emplace_back(view);
        unique[view]++;
      }
    }

    return vec;
  }
};

/*
class Solution
{
private:
  struct my_str
  {
    const char *ptr;
    unsigned freq = 0;

    static unsigned encode(const char a)
    {
      switch(a)
      {
      case 'C':
        return 1;
      case 'G':
        return 2;
      case 'T':
        return 3;
      default:
        return 0;
      }
    }

    static unsigned hash(const char *__restrict__ ptr)
    {
      unsigned res = 0;
      for(unsigned i = 0; i < 10U; i++)
      {
        res |= (encode(*(ptr + i))) << (2U * i);
      }
      return res;
    }
  };

public:
  std::vector<std::string> findRepeatedDnaSequences(const std::string &s)
  {
    const unsigned size = s.size();

    constexpr unsigned STK_SIZE = 1'048'574;

    std::unordered_map<unsigned, my_str> stack;

    for(unsigned i = 0, j = 9; j < size; i++, j++)
    {
      const auto hash = my_str::hash(&s[i]);
      if(stack.count(hash) == 0)
      {
        stack[hash].ptr = &s[i];
        stack[hash].freq = 1;
      }
      else
      {
        stack[hash].freq++;
      }
    }

    std::vector<std::string> vec;
    vec.reserve(STK_SIZE);

    for(const auto &m_str : stack)
    {
      if(m_str.second.freq > 1)
      {
        vec.emplace_back(m_str.second.ptr, 10);
      }
    }

    return vec;
  }
};
*/

// first submission 39 ms in the 76% beaten
/*
class Solution
{
public:
  std::vector<std::string> findRepeatedDnaSequences(const std::string &s)
  {
    const unsigned size = s.size();

    std::unordered_map<std::string_view, unsigned> unique;

    for(unsigned i = 0, j = 9; j < size; i++, j++)
    {
      const auto view = std::string_view(&s[i], 10);
      if(unique.count(view) == 0)
      {
        unique[view] = 1;
      }
      else
      {
        unique[view]++;
      }
    }

    std::vector<std::string> vec;
    vec.reserve(unique.size());

    for(const auto &pair : unique)
    {
      if(pair.second > 1)
      {
        vec.emplace_back(pair.first);
      }
    }

    return vec;
  }
};
*/

// base version
/*
class Solution
{
public:
  std::vector<std::string> findRepeatedDnaSequences(const std::string &s)
  {
    std::set<std::string_view> unique;

    const unsigned size = s.size();
    for(unsigned i = 0, j = 9; j < size; i++, j++)
    {
      for(unsigned k = i + 1, l = j + 1; l < size; k++, l++)
      {
        bool repeated = true;
        for(unsigned m = i, n = k; n < l; m++, n++)
        {
          repeated = repeated && (s[m] == s[n]);
          if(!repeated)
          {
            break;
          }
        }

        if(repeated)
        {
          unique.insert(std::string_view(&s[i], 10));
          break;
        }
      }
    }

    std::vector<std::string> vec;
    vec.reserve(unique.size());

    for(const auto &un : unique)
    {
      vec.emplace_back(un);
    }

    return vec;
  }
};
*/
