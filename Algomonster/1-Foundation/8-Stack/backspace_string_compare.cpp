#include <iostream>
#include <stack>
#include <string>

bool backspace_string_compare(std::string &s, std::string &t) {
    std::stack<char> sstack, tstack;

    // sstack
    for (char c : s) {
        if (c != '#') {
            sstack.push(c);
        } else {
            if (!sstack.empty()) {
                sstack.pop();
            }
        }
    }

    // tstack
    for (char d : t) {
        if (d != '#') {
            tstack.push(d);
        } else {
            if (!tstack.empty()) {
                tstack.pop();
            }
        }
    }

    if (sstack.size() != tstack.size()) {
        return false; // resulting stacks should be identical
    }

    while (!sstack.empty()) {
        if (sstack.top() != tstack.top()) {
            return false;
        } else {
            sstack.pop();
            tstack.pop();
        }
    }

    return true;
}

int main() {
    std::string s = "ab#c", t = "ad#c";
    std::cout << backspace_string_compare(s, t);
    return 0;
}