#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

std::string remove_adjacent_duplicates_in_string(const std::string &s) {
    std::string result;

    for (char c : s) {
        if (result.empty()) { // if it's empty, push new value
            result.push_back(c);
        } else {
            char top = result.back();
            if (c == top) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
    }

    return result;
}

int main() {
    std::string s = "abbaca";
    std::string res = remove_adjacent_duplicates_in_string(s);
    std::cout << res << '\n';
    return 0;
}