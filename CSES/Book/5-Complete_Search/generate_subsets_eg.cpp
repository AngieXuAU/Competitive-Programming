#include <iostream>
#include <vector>

using namespace std;

int n = 3;

vector<int> subset;

void search(int k) {
    if (k == n) {
        for (int x : subset)
            cout << x << "\t";
        cout << "\n";
    } else {
        search(k + 1);
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
    }
}

int main() {
    search(0);
    return 0;
}