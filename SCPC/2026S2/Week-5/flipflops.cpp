#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long solve(long long c, long long k, vector<long long> a) {
    for (int x : a) {
        if (c < x)
            break;
        // otherwise c > x
        if (k >= c - x) {
            long diff = c - x;
            x += diff; // ie. x = c;
            k -= diff; // flip flop consumed
        }
        c += x; // add on
    }
    return c;
}

int main() {
    int cases_num;
    cin >> cases_num;

    int n, k;
    long long c; // might have to be long long idk tbh

    for (int i = 0; i < cases_num; i++) {
        vector<long long> a;
        cin >> n >> c >> k;

        if (n == 0) {
            cout << c;
            continue;
        }

        int x;
        for (int j = 0; j < n; j++) {
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());

        cout << solve(c, k, a) << "\n";

        a.clear();
    }

    return 0;
}