#include <array>
#include <memory>
#include <string>

// beats 95% in speed and 92% in memory
class WordDictionary
{
private:
  static constexpr auto N_LETTERS = 'z' - 'a' + 1;
  struct node
  {
    bool end = false;
    std::array<std::unique_ptr<node>, N_LETTERS> next;
  };

  struct rec_stack
  {
    const node *ptr;
    size_t i, j;
  };

private:
  std::unique_ptr<node> head;

public:
  WordDictionary() : head(std::make_unique<node>()) {};

  void addWord(const std::string &wrd)
  {
    node *ptr = head.get();
    const size_t size = wrd.size();
    const char *__restrict__ word = &wrd[0];
    size_t i = 0;
    for(; i < size; i++)
    {
      size_t idx = word[i] - 'a';
      if(ptr->next[idx] == nullptr)
      {
        ptr->next[idx] = std::make_unique<node>();
      }
      ptr = ptr->next[idx].get();
    }
    ptr->end = true;
  }

  bool search(const std::string &wrd)
  {
    const size_t size = wrd.size();
    const char *__restrict__ word = wrd.data();

    const node *ptr = head.get();

    std::array<rec_stack, 2> stack;
    size_t stack_ptr = 0;

    size_t i = 0;
    size_t j = 0;

  start:
    for(; i < size; i++)
    {
      if(word[i] != '.')
      {
        const size_t idx = word[i] - 'a';

        if(ptr->next[idx] == nullptr)
        {
          goto backtrack;
        }

        ptr = ptr->next[idx].get();
        continue;
      }

      j = 0;

    recurse:
      for(; j < N_LETTERS; ++j)
      {
        if(ptr->next[j] == nullptr)
        {
          continue;
        }

        stack[stack_ptr++] = { .ptr = ptr, .i = i++, .j = j };

        ptr = ptr->next[j].get();

        goto start;
      }

      goto backtrack;
    }

    if(ptr->end)
    {
      return true;
    }

  backtrack:
    if(stack_ptr == 0)
    {
      return false;
    }

    {
      const auto frame = stack[--stack_ptr];

      ptr = frame.ptr;
      i = frame.i;
      j = frame.j + 1;
    }

    goto recurse;
  }
};

// beats 93% in time and 93% in memory
/*
class WordDictionary
{
private:
  static constexpr auto N_LETTERS = 'z' - 'a' + 1;
  struct node
  {
    bool end = false;
    std::array<std::unique_ptr<node>, N_LETTERS + 1> next;
  };

private:
  std::unique_ptr<node> head;

public:
  WordDictionary() : head(std::make_unique<node>()) {};

  void addWord(const std::string &wrd)
  {
    node *ptr = head.get();
    const size_t size = wrd.size();
    const char *__restrict__ word = &wrd[0];
    size_t i = 0;
    while(i < size)
    {
      size_t idx = word[i] - 'a';
      if(ptr->next[idx] == nullptr)
      {
        ptr->next[idx] = std::make_unique<node>();
      }
      ptr = ptr->next[idx].get();
      i++;
    }
    ptr->end = true;
  }

  bool search(const std::string &word)
  {
    return search_mid(head.get(), 0, &word[0], word.size());
  }

private:
  bool search_mid(const node *ptr_ptr, const size_t st_pt, const char *__restrict__ word, const size_t &size)
  {
    const node *ptr = ptr_ptr;
    size_t i = st_pt;
    while(i < size)
    {
      if(word[i] == '.')
      {
        for(auto &j : ptr->next)
        {
          if(j == nullptr)
          {
            continue;
          }
          else if(search_mid(j.get(), i + 1, word, size))
          {
            return true;
          }
        }
        return false;
      }

      size_t idx = word[i] - 'a';
      if(ptr->next[idx] == nullptr)
      {
        return false;
      }
      ptr = ptr->next[idx].get();
      i++;
    }
    return ptr->end;
  }
};
*/

// beats 68% in time and 93% in memory
/*
class WordDictionary
{
private:
  static constexpr auto N_LETTERS = 'z' - 'a' + 1;
  struct node
  {
    bool end = false;
    std::array<std::unique_ptr<node>, N_LETTERS + 1> next;
  };

private:
  std::unique_ptr<node> head;

public:
  WordDictionary() : head(std::make_unique<node>()) {};

  void addWord(const std::string &word)
  {
    node *ptr = head.get();
    const size_t size = word.size();
    size_t i = 0;
    while(i < size)
    {
      size_t idx = word[i] - 'a';
      if(ptr->next[idx] == nullptr)
      {
        ptr->next[idx] = std::make_unique<node>();
      }
      ptr = ptr->next[idx].get();
      i++;
    }
    ptr->end = true;
  }

  bool search(std::string word)
  {
    return search_mid(head.get(), 0, word);
  }

private:
  bool search_mid(node *ptr_ptr, const size_t st_pt, std::string &word)
  {
    node *ptr = ptr_ptr;
    const size_t size = word.size();
    size_t i = st_pt;
    while(i < size)
    {
      if(word[i] == '.')
      {
        for(auto &j : ptr->next)
        {
          if(j == nullptr)
          {
            continue;
          }
          else if(search_mid(j.get(), i + 1, word))
          {
            return true;
          }
        }
        return false;
      }

      size_t idx = word[i] - 'a';
      if(ptr->next[idx] == nullptr)
      {
        return false;
      }
      ptr = ptr->next[idx].get();
      i++;
    }
    return ptr->end;
  }
};
*/
//
////
