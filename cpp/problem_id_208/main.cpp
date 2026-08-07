#include <array>
#include <cassert>
#include <memory>
#include <string>

struct node
{
  bool end = false;
  std::array<std::unique_ptr<node>, 'z' - 'a' + 1> map{};
};

class Trie
{
private:
  std::unique_ptr<node> head = std::make_unique<node>();

public:
  Trie() = default;

  void insert(const std::string &word)
  {
    node *curr = head.get();

    for(const char &c : word)
    {
      const char ch = c - 'a';
      if(curr->map[ch] != nullptr)
      {
        curr = curr->map[ch].get();
      }
      else
      {
        curr->map[ch] = std::make_unique<node>();
        curr = curr->map[ch].get();
      }
    }
    curr->end = true;
  }

  bool search(const std::string &word)
  {
    node *curr = head.get();

    for(const char &c : word)
    {
      const char ch = c - 'a';
      if(curr->map[ch] == nullptr)
      {
        return false;
      }
      curr = curr->map[ch].get();
    }
    return curr->end;
  }

  bool startsWith(const std::string &prefix)
  {
    node *curr = head.get();

    for(const char &c : prefix)
    {
      const char ch = c - 'a';
      if(curr->map[ch] == nullptr)
      {
        return false;
      }
      curr = curr->map[ch].get();
    }
    return true;
  }
};

/* submission 1 kinda slow
struct node
{
  bool end = false;
  std::array<std::unique_ptr<node>, 128> map{};
};

class Trie
{
private:
  std::unique_ptr<node> head = std::make_unique<node>();

public:
  Trie() = default;

  void insert(const std::string &word)
  {
    node *curr = head.get();

    for(const char &ch : word)
    {
      if(curr->map[ch] != nullptr)
      {
        curr = curr->map[ch].get();
      }
      else
      {
        curr->map[ch] = std::make_unique<node>();
        curr = curr->map[ch].get();
      }
    }
    curr->end = true;
  }

  bool search(const std::string &word)
  {
    node *curr = head.get();

    for(const char &ch : word)
    {
      if(curr->map[ch] == nullptr)
      {
        return false;
      }
      curr = curr->map[ch].get();
    }
    return curr->end;
  }

  bool startsWith(const std::string &prefix)
  {
    node *curr = head.get();

    for(const char &ch : prefix)
    {
      if(curr->map[ch] == nullptr)
      {
        return false;
      }
      curr = curr->map[ch].get();
    }
    return true;
  }
};
*/
