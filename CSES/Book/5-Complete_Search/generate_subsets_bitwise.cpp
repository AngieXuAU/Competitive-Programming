
#include <iostream>
#include <vector>

using namespace std;

int n = 3;

int main() {
    for (int b = 0; b < (1 << n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i))
                subset.push_back(i);
        }

        for (int x : subset) {
            cout << x << "\t";
        }
        cout << "\n";
    }
}