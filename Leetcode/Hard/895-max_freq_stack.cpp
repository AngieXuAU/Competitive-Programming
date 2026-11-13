/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

#include <unordered_map>
#include <utility>
using namespace std;

class FreqStack {
  private:
    unordered_map<int, pair<int, int>> freqs;
    vector<int> heap = {-1};

  public:
    FreqStack() {}

    void push(int val) {
        if (!freqs.contains(val)) {
            freqs[val] = {1, heap.size()};
            heap.push_back(val);
        } else {
            freqs[val].first++;
        }
        upheap(val);
    }

    int pop() {
        int result = heap[1];
        downheap();
        return result;
    }

    void upheap(int val) {
        int child = freqs.at(val).first;
        int index = freqs.at(val).second;
        int parent = heap[index / 2];

        while (child > parent) {
            // swap stored indices
            freqs.at(child).second = {index / 2};
            freqs.at(parent).second = {index};

            // swap in heap storage
            swap(heap.at(index), heap.at(index / 2));

            // iterate
            index /= 2;
            child = heap[index];
            parent = heap[index / 2];
        }
    }

    void downheap() { heap.erase(heap.begin() + 1); }
};