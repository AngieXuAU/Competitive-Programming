#include <iostream>
#include <string>

using namespace std;

int main() {
    int weight;
    cin >> weight;

    string result;

    if (weight <= 3) {
        result = "NO";
    } else {
        result = (weight % 2 == 0) ? "YES" : "NO";
    }
    cout << result;

    return 0;
}