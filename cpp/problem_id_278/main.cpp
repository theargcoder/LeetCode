// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(const int a);

class Solution
{
public:
  int firstBadVersion(const int &n)
  {
    int left = 0, right = static_cast<int>((1U << 31U) - 1);

    while(true)
    {
      if(isBadVersion(left) && isBadVersion(right))
        return left;

      const int mid = left + ((right - left) / 2);

      if(isBadVersion(mid))
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }

    return 0;
  }
};
