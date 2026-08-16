#include <stack>

using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        stack<int> reverse;
        int tmp;
        while (x > 0) {
            tmp = x % 10;
            reverse.push(tmp);
            x /= 10;
            // cout << tmp << "\n";
        }

        stack<int> reverse_copy = reverse;
        stack<int> straight;

        int top;
        while (!reverse.empty()) {
            top = reverse.top();
            straight.push(top);
            reverse.pop();
        }

        return (reverse_copy == straight);
    }
};