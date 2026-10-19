#include <array>
#include <cstdint>
#include <string>
#include <vector>

static constexpr size_t MAX = 10e5 + 1;

static constexpr auto next_char_in_order = []()
{
  std::array<char, 'W' + 1> cha_to_cha{};

  cha_to_cha.at('R') = 'B';
  cha_to_cha.at('B') = 'W';
  cha_to_cha.at('W') = 'R';

  return cha_to_cha;
}();

static std::array<uint16_t, MAX> parent_of, child_of;

class Solution
{
public:
  int findColoredRoot(const std::vector<std::vector<int>> &edges, const std::string &colors)
  {
    const int size = colors.size();

    std::fill(parent_of.begin(), parent_of.begin() + size, 0);
    std::fill(child_of.begin(), child_of.begin() + size, 0);

    for(const auto &vec : edges)
    {
      const auto u_i = vec[0];
      const auto v_i = vec[1];
      const char col_u = colors[u_i];
      const char col_v = colors[v_i];

      const char next_col_u = next_char_in_order[col_u];
      const char next_col_v = next_char_in_order[col_v];

      if(next_col_u == col_v)
      {
        parent_of[u_i]++;
        child_of[v_i]++;
      }
      else if(next_col_v == col_u)
      {
        child_of[u_i]++;
        parent_of[v_i]++;
      }
      else
      {
        return -1;
      }
    }

    int root = -1;

    for(int i = 0; i < size; i++)
    {
      if(parent_of[i] > 2)
      {
        return -1;
      }

      if(child_of[i] == 0)
      {
        if(root != -1)
        {
          return -1;
        }
        root = i;
      }
    }

    return root;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.findColoredRoot({ { 3, 1 }, { 3, 2 }, { 1, 4 }, { 2, 0 } }, "BRRWB");

  return 0;
}
