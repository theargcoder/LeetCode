#include <algorithm>
#include <iostream>
#include <vector>

class KthLargest
{
  public:
    KthLargest (int k, std::vector<int> &nums)
    {
        backwards_count = k - 1;
        nums_in_order = nums;
        if (nums_in_order.size () > 1)
            {
                std::sort (nums_in_order.begin (), nums_in_order.end (),
                           std::greater<int> ());
            }
    }

    ~KthLargest () { nums_in_order.clear (); }

    int
    add (int val)
    {
        auto it
            = std::lower_bound (nums_in_order.begin (), nums_in_order.end (),
                                val, std::greater<int> ());
        nums_in_order.insert (it, val);

        // Return the kth largest element
        return nums_in_order[backwards_count];
    }

  private:
    int backwards_count;

  private:
    std::vector<int> nums_in_order;
};

/**
 * Your KthLargest object will be instant->ated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int
main ()
{
    std::vector<int> numbs;
    numbs.push_back (4);
    numbs.push_back (5);
    numbs.push_back (8);
    numbs.push_back (2);

    KthLargest *kthLargest = new KthLargest (3, numbs);
    std::cout << "case 1 :" << '\n';
    std::cout << kthLargest->add (3) << '\n';  // return 4
    std::cout << kthLargest->add (5) << '\n';  // return 5
    std::cout << kthLargest->add (10) << '\n'; // return 5
    std::cout << kthLargest->add (9) << '\n';  // return 8
    std::cout << kthLargest->add (4) << '\n';  // return 8};

    numbs.clear ();
    numbs.push_back (0);
    KthLargest *kthLargest_2 = new KthLargest (2, numbs);
    std::cout << "case 2 :" << '\n';
    std::cout << kthLargest_2->add (-1) << '\n'; // return 4
    std::cout << kthLargest_2->add (1) << '\n';  // return 5
    std::cout << kthLargest_2->add (-2) << '\n'; // return 5
    std::cout << kthLargest_2->add (-4) << '\n'; // return 8
    std::cout << kthLargest_2->add (3) << '\n';  // return 8};
}
