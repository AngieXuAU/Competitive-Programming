#include <queue>

using namespace std;

class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int, vector<int>> max_heap;

        // initialise the heap
        for (int stone : stones) {
            max_heap.push(stone);
        }

        while (max_heap.size() >= 2) {
            int y = max_heap.top();
            max_heap.pop();
            int x = max_heap.top();
            max_heap.pop();

            y -= x;
            if (y > 0) {
                max_heap.push(y);
            }
        }

        if (max_heap.empty())
            return 0;

        return max_heap.top();
    }
};
