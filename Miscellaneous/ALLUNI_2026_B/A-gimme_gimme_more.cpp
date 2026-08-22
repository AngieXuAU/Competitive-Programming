#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_children, total;
    cin >> num_children >> total;

    int ans;
    ans = total - (num_children * (num_children - 1) / 2);
    ans /= num_children;

    if (ans == 0) {
        cout << -1;
        return -1;
    }

    cout << ans;
    return 0;
}