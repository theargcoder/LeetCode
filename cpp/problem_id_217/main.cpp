#include <array>
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <vector>

// 5 ms beats 99.90 % in time and 84% in memory !!

template <size_t N>
struct bool_array
{
  static constexpr bool is_prime(unsigned n)
  {
    if(n <= 1)
      return false;
    if(n <= 3)
      return true;
    if(n % 2 == 0 || n % 3 == 0)
      return false;

    for(unsigned i = 5; i * i <= n; i += 6)
    {
      if(n % i == 0 || n % (i + 2) == 0)
        return false;
    }
    return true;
  }

  static constexpr unsigned next_prime(unsigned n)
  {
    unsigned p = n + 1;
    while(!is_prime(p))
    {
      p++;
    }
    return p;
  }

  std::array<uint8_t, next_prime(N / 8U)> table;

  void zero() noexcept
  {
    table.fill(0);
  }

  bool set_return_true_if_used(const size_t &idx) noexcept
  {
    size_t our_idx = idx >> 3;
    size_t mod_idx = idx & 0b0111;

    if(table[our_idx] & (1U << mod_idx))
    {
      return true;
    }
    table[our_idx] |= (1U << mod_idx);
    return false;
  }
};

template <typename T, size_t N>
  requires std::is_integral_v<T>
class myhash
{
private:
  bool_array<N> table;

  size_t hash(const T &val) noexcept
  {
    uint32_t hash_value = (uint32_t)val * 0x9E3779B9;
    return ((uint64_t)hash_value * N) >> 32U;
  }

public:
  void zero()
  {
    table.zero();
  }

  bool insert_true_if_exists(const T &val) noexcept
  {
    const auto this_hash = hash(val);
    return table.set_return_true_if_used(this_hash);
  }
};

class Solution
{
private:
  myhash<int, 2'000'000> table;

public:
  bool containsDuplicate(const std::vector<int> &nums)
  {
    table.zero();

    for(const auto &i : nums)
    {
      if(table.insert_true_if_exists(i))
      {
        return true;
      }
    }

    return false;
  }
};

// beats 94% in time and 87% in memory
/*
class Solution
{
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::ranges::sort(nums);
    const int size = nums.size();

    for(int i = 1; i < size; i++)
    {
      if(nums[i] == nums[i - 1])
      {
        return true;
      }
    }

    return false;
  }
};
*/

// beats 69 % in time and 56% in memory
/*
class Solution
{
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::unordered_set<int> hash;

    for(const auto &i : nums)
    {
      if(hash.contains(i))
      {
        return true;
      }
      else
      {
        hash.insert(i);
      }
    }

    return false;
  }
};
*/
