#include <iostream>
#include <unordered_set>

using namespace std;

int square_root(int n) {
    unordered_set<int> seen;
    // artificially create limits
    int min = 0, max = n, mid = min + (max - min) / 2;

    seen.insert(mid);
    // check rounding down
    while (min < max) {
        seen.insert(mid);
        if ((mid * mid) == n) { // perfect match
            return mid;
        } else if ((mid * mid) < n) { // less than - could be match if trunc.
            min = mid;
        } else { // overshot
            max = mid - 1;
        }

        // re-evaluate mid
        mid = min + (max - min) / 2;
        if (seen.count(mid) && seen.count(mid + 1)) {
            return mid;
        } else if (seen.count(mid)) {
            mid += 1;
        } else {
            continue;
        }
    }
    return mid;
}

int main() {
    for (int i = 0; i <= 30; i++) {
        cout << i << ": " << square_root(i) << "\n";
    }

    cout << square_root(1);
    return 0;
}