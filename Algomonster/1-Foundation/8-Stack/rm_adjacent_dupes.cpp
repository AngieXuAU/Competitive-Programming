#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

std::string remove_adjacent_duplicates_in_string(const std::string &s) {
    // Your code here
    std::stack<char> str;

    for (char c : s) {
        if (str.empty()) { // if it's empty, push new value
            str.push(c);
        } else {
            char top = str.top();
            if (c == top) {
                str.pop();
            } else {
                str.push(c);
            }
        }
    }

    // get the results into a string itself
    std::string result;
    while (!str.empty()) {
        result.push_back(str.top());
        str.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string s = "abbaca";
    std::string res = remove_adjacent_duplicates_in_string(s);
    std::cout << res << '\n';
    return 0;
}