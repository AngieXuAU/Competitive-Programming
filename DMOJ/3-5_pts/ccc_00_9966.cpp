// Canadian Computing Competition: 2000 Stage 1, Junior #2

// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool valid(int x) {
    string str = to_string(x);
    unordered_set<char> allowed = {'0', '1', '8', '6', '9'};

    int start = 0, end = str.size() - 1;
    char s, e;

    while (start <= end) {
        s = str[start], e = str[end];
        // illegal
        if (!allowed.count(s) || !allowed.count(e))
            return false;

        // 6 or 9
        if (s == '6') {
            if (e == '9') {
                start++;
                end--;
                continue;
            } else {
                return false;
            }
        }
        if (s == '9') {
            if (e == '6') {
                start++;
                end--;
                continue;
            } else {
                return false;
            }
        }

        // otherwise (0, 1, 8) they should match
        if (s != e)
            return false;

        // manage loop
        start++;
        end--;
    }
    return true;
}

int solve(int min, int max) {
    int count = 0;
    for (int i = min; i <= max; i++) {
        if (valid(i)) {
            // cout << i << "\n";
            count++;
        }
    }
    return count;
}

int main() {
    int min, max;
    cin >> min >> max;
    cout << solve(min, max);
    // int x;
    // cin >> x;
    // cout << valid(x);
    return 0;
}