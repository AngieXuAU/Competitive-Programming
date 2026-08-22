
#include <iostream>

using namespace std;

int main() {
    long num_of_choc_types;
    cin >> num_of_choc_types;

    const int MAXN = 200005;
    long choc_count[MAXN];
    // long choc_count[num_of_choc_types];
    int i;
    for (i = 0; i < num_of_choc_types; i++) {
        cin >> choc_count[i];
    }

    if (num_of_choc_types == 1) {
        cout << choc_count[0];
        return 0;
    }

    long max = choc_count[num_of_choc_types - 1];

    // cout << "max: " << max << "\n";
    long long total = max;

    // cout << "total starts at: " << total << "\n";

    i--;
    while (i > 0) {
        // cout << "i is: " << i << "\n";
        i--;
        max--;
        // max = the smaller of num of chocs available and max - 1
        max = (max < choc_count[i]) ? (max) : choc_count[i];
        max = (max >= 0) ? max : 0;

        // cout << "adding: " << max << "\n";
        total += max;
        // cout << "total: " << total << "\n";
    }

    cout << total;

    return 0;
}