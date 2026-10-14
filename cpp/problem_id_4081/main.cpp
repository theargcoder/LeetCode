#include <algorithm>
#include <cstdint>
#include <ranges>
#include <vector>

constexpr auto LIMIT_N = 1'000;
constexpr auto MAX_SIZE = LIMIT_N + 1;

static std::vector<bool> is_prime(MAX_SIZE, true);
static std::vector<int> primes_till_10e4;
static bool done = false;

void build_primes_upto_10e4()
{
  if(done)
    return;

  done = true;

  for(int p = 2; p * p <= LIMIT_N; p++)
  {
    if(is_prime[p] == true)
    {
      for(int i = p * p; i <= LIMIT_N; i += p)
      {
        is_prime[i] = false;
      }
    }
  }

  for(int i = 2; i <= LIMIT_N; i++)
  {
    if(is_prime[i])
    {
      primes_till_10e4.push_back(i);
    }
  }
}

class Solution
{
public:
  std::vector<int> maxPrimeSubset(const int &n, const int &s)
  {
    build_primes_upto_10e4();

    const auto primes_end = std::ranges::upper_bound(primes_till_10e4, n);

    const auto capacity = static_cast<std::size_t>(s);

    // best[sum] = optimal subset that produces exactly 'sum'.
    std::vector<std::vector<int>> best(capacity + 1);

    // An empty vector alone cannot distinguish an unreachable sum
    // from the valid empty subset corresponding to sum zero.
    std::vector<bool> reachable(capacity + 1, false);
    reachable[0] = true;

    for(auto it = primes_till_10e4.begin(); it != primes_end && *it <= s; ++it)
    {
      const int p = *it;
      const auto prime_index = static_cast<std::size_t>(p);

      // Descending order ensures that each prime is used at most once.
      for(auto sum = capacity; sum >= prime_index; --sum)
      {
        const auto previous_sum = sum - prime_index;

        if(!reachable[previous_sum])
          continue;

        // Candidate = optimal subset for (sum - p), plus p.
        auto candidate = best[previous_sum];
        candidate.push_back(p);

        const bool fewer_primes = candidate.size() < best[sum].size();

        const bool lexicographically_smaller
            = candidate.size() == best[sum].size() && std::lexicographical_compare(candidate.begin(), candidate.end(), best[sum].begin(), best[sum].end());

        if(!reachable[sum] || fewer_primes || lexicographically_smaller)
        {
          best[sum] = std::move(candidate);
          reachable[sum] = true;
        }
      }
    }

    // The largest reachable positive sum wins.
    for(auto sum = capacity; sum > 0; --sum)
    {
      if(reachable[sum])
        return best[sum];
    }

    return {};
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.maxPrimeSubset(7, 20);
  const auto res_2 = sol.maxPrimeSubset(15, 18);

  return 0;
}
