/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class FreqStack {
  private:
    unordered_map<int, int> freqs;
    vector<stack<int>> heap;

  public:
    FreqStack() {}

    void push(int val) {
        int existing_max = heap.size();
        freqs[val]++;

        if (freqs[val] > existing_max) {
            heap.emplace_back();
            heap.back().push(val);
        } else {
            heap[freqs[val] - 1].push(val);
        }
    }

    int pop() {
        stack<int> *stk = &heap[heap.size() - 1];
        int result = stk->top();
        freqs[result]--;
        stk->pop();
        if (stk->empty()) {
            heap.erase(heap.end() - 1);
        }
        return result;
    }
};

int main() {
    FreqStack *obj = new FreqStack();
    obj->push(1);
    obj->push(1);
    obj->push(1);
    obj->push(2);
    cout << obj->pop() << "\n";
    cout << obj->pop() << "\n";
    obj->push(2);
    obj->push(2);
    obj->push(1);
    cout << obj->pop() << "\n";
    cout << obj->pop() << "\n";
    cout << obj->pop() << "\n";

    return 0;
}