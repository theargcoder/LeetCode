#include <array>
#include <cstdint>

class Solution
{
private:
  using matrix_t = std::array<std::array<uint64_t, 2>, 2>;

  matrix_t X;
  matrix_t Y;

  matrix_t multiply_matrixes(matrix_t &A, matrix_t &B)
  {
    constexpr uint64_t MOD = 1'000'000'007;
    matrix_t res;
    res[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    res[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    res[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    res[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

    return res;
  }

public:
  int countGoodStrings(long long n)
  {
    X[0][0] = 1, X[0][1] = 0;
    X[1][0] = 0, X[1][1] = 1;

    Y[0][0] = 1, Y[0][1] = 1;
    Y[1][0] = 1, Y[1][1] = 0;

    while(n > 0)
    {
      if(n & 0b01)
      {
        X = multiply_matrixes(X, Y);
      }
      Y = multiply_matrixes(Y, Y);
      n >>= 1;
    }

    return (X[0][1] * 2) % (1'000'000'007);
  }
};
