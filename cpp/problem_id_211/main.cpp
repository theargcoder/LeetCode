#include <array>
#include <memory>
#include <string>

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
