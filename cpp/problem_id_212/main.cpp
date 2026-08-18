#include <array>
#include <memory>
#include <string>
#include <vector>

#define N_NEIGHBORS 4
#define MAX_LEVELS 12
#define MAX_TRIE_HEIGHT 12 * 12
#define MAX_LENGTH 10
#define N_LETTERS 'z' - 'a'
#define WRD_SIZE 30'000

// left, right, up, down
constexpr char OFFSET[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

class Trie
{
public:
  struct node
  {
    bool end = false;
    std::array<std::unique_ptr<node>, 'z' - 'a' + 1> map{};
  };
  std::unique_ptr<node> head_ = std::make_unique<node>();

public:
  Trie() = default;

  void insert(const std::string &word)
  {
    node *curr = head_.get();

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

  node *head()
  {
    return head_.get();
  }
};

class Solution
{
  Trie trie;
  std::vector<std::string> to_ret;

  std::array<std::array<bool, MAX_LEVELS>, MAX_LEVELS> used;
  size_t x_size, y_size;

public:
  std::vector<std::string> findWords(const std::vector<std::vector<char>> &board, std::vector<std::string> &words)
  {
    to_ret.reserve(30'000);
    for(auto &arr : used)
    {
      arr.fill(false);
    }
    x_size = board.size();
    y_size = board.back().size();

    for(const auto &wrd : words)
    {
      trie.insert(wrd);
    }

    std::string str_aa;
    auto *head = trie.head();
    for(size_t i = 0; i < x_size; i++)
    {
      for(size_t j = 0; j < y_size; j++)
      {
        if(head->map[board[i][j] - 'a'] != nullptr)
        {
          build_tree(board, head->map[board[i][j] - 'a'].get(), str_aa, i, j);
        }
      }
    }

    return to_ret;
  }

private:
  void build_tree(const std::vector<std::vector<char>> &board, Trie::node *curr, std::string &str, size_t i, size_t j)
  {
    if(str.size() >= MAX_LENGTH)
    {
      return;
    }
    if(used[i][j])
    {
      return;
    }

    used[i][j] = true;
    str.push_back(board[i][j]);
    if(curr->end)
    {
      curr->end = false;
      to_ret.push_back(str);
    }

    for(const auto &k : OFFSET)
    {
      size_t x_coo = i + k[0];
      size_t y_coo = j + k[1];
      if(x_coo < x_size && y_coo < y_size && curr->map[board[x_coo][y_coo] - 'a'] != nullptr)
      {
        build_tree(board, curr->map[board[x_coo][y_coo] - 'a'].get(), str, x_coo, y_coo);
      }
    }

    str.pop_back();
    used[i][j] = false;
  }
};
