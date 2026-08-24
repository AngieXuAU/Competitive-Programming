#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n = 3;

vector<int> permutation;
bool chosen[3] = {false};

void search() {
    if (permutation.size() == n) {
        for (int x : permutation) {
            cout << x << "\t";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    // search();

    int m = 4;
    vector<int> p;
    for (int i = 0; i < m; i++) {
        p.push_back(i);
    }
    do {
        for (int x : p) {
            cout << x << "\t";
        }
        cout << "\n";
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}