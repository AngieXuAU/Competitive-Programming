#include <queue>

using namespace std;

class KthLargest {
  private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int kth;

  public:
    KthLargest(int k, vector<int> &nums) {
        kth = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > kth) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};

// tags: `heap, `priorityqueue