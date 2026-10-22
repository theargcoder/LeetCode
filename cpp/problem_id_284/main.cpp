#include <vector>

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator
{
  struct Data;
  Data *data;

public:
  Iterator(const std::vector<int> &nums);
  Iterator(const Iterator &iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator
{
  int cached;
  bool has_cached = false;

public:
  PeekingIterator(const std::vector<int> &nums) : Iterator(nums)
  {
  }

  int peek()
  {
    auto it = PeekingIterator(*this);
    return it.next();
  }
};
