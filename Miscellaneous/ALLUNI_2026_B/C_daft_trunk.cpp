// #include <cmath>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    if (num == 1) {
        cout << 0;
        return 0;
    }

    int prev;
    cin >> prev;

    int tmp, replacements = 0;
    bool dec = false;
    for (int i = 1; i < num; i++) {
        cin >> tmp;
        if (tmp < prev) {
            if (dec == true) {
                cout << tmp << " needs replacing\n";
                replacements++;
                dec = false;
            } else {
                dec = true;
                prev = tmp;
            }
        } else {
            dec = false;
            prev = tmp;
        }
    }

    cout << replacements;

    return 0;
}