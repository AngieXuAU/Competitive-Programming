#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> cs = {'1', '2', '3', '4'};

    for (char c : cs) {
        int x = (int)c;
        cout << x - 48 << endl;
    }
}