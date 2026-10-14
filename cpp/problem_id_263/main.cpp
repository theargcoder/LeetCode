class Solution
{
public:
  bool isUgly(const int &n)
  {
    if(n < 1)
      return false;

    int n_it = n;

    while(n_it > 1)
    {
      if(n_it % 2 == 0)
      {
        n_it /= 2;
      }
      else if(n_it % 3 == 0)
      {
        n_it /= 3;
      }
      else if(n_it % 5 == 0)
      {
        n_it /= 5;
      }
      else
      {
        return false;
      }
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;

  const auto res_1 = sol.isUgly(6);

  return 0;
}
