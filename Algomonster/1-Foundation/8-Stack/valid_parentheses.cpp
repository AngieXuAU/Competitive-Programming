
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool valid_parentheses(std::string &s) {
    std::stack<char> brackets;
    std::unordered_set<char> closing = {')', ']', '}'};
    std::unordered_map<char, char> pairs = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

    // check if odd --> invalid
    if (s.size() % 2 == 1) {
        return false;
    }

    // iterate through the string
    for (char c : s) {
        if (closing.contains(c)) {
            if (brackets.empty()) {
                return false;
            }
            char temp = brackets.top();
            if (pairs[temp] == c) { // logic of this line is broken
                brackets.pop();
            } else {
                return false;
            }
        } else {
            brackets.push(c);
        }
    }

    return true;
}

int main() {
    std::string s = "([{}(())])";
    std::cout << valid_parentheses(s);
    return 0;
}