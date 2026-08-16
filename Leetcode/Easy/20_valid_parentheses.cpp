#include <stack>
using namespace std;

class Solution {
  public:
    bool match(const char &open, const char &close) {
        switch (open) {
        case '(':
            return (close == ')');
        case '[':
            return (close == ']');
        case '{':
            return (close == '}');
        default:
            return false;
        }
    }

    bool isValid(const string &s) {
        stack<char> seen;

        char c, top;
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                seen.push(c);
            } else {
                if (seen.empty()) {
                    return false;
                }
                if (match(seen.top(), c)) {
                    seen.pop();
                } else {
                    return false;
                }
            }
        }

        return (seen.empty());
    }
};