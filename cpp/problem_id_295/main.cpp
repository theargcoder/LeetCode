#include <queue>
#include <vector>

class MedianFinder
{
  std::priority_queue<int, std::vector<int>, std::greater<>> upper;
  std::priority_queue<int, std::vector<int>, std::less<>> lower;

  size_t size = 0;

public:
  MedianFinder() = default;

  void addNum(int num) noexcept
  {
    size++;
    if(lower.empty())
    {
      lower.push(num);
      return;
    }

    if(num > lower.top())
    {
      upper.push(num);
    }
    else
    {
      lower.push(num);
    }

    while(lower.size() < upper.size())
    {
      const auto val = upper.top();
      upper.pop();
      lower.push(val);
    }

    while(upper.size() + 1 < lower.size())
    {
      const auto val = lower.top();
      lower.pop();
      upper.push(val);
    }
  }

  double findMedian()
  {
    if(size & 0b01)
    {
      return lower.top();
    }
    else
    {
      return static_cast<double>(lower.top() + upper.top()) / 2.0;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char *argv[])
{
  MedianFinder sol;

  sol.addNum(1);
  sol.addNum(2);
  const auto res_1 = sol.findMedian();
  sol.addNum(3);
  const auto res_2 = sol.findMedian();

  return 0;
}
